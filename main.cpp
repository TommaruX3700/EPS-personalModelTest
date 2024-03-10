//Enable to 1 to execute only "TEST_REGION"
#define TEST_MODE 0 

#pragma region "Includes" 
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>
    #include <chrono>
    #include <algorithm>
    #include <regex>
    #include <thread>

    #include "extLibs/nlohmannJSON/json.hpp"
    #include "extLibs/rapidjson/document.h"

    #include "headers/entities/physical/Pack.hpp"
    #include "headers/entities/physical/PalletGroup.hpp"
    #include "headers/entities/geometry/Grid.hpp"
    
    #include "headers/logic/BoxNesting/mainLoops.hpp"

    #include "headers/logic/messages.hpp" 
    #include "headers/logic/letturaFileJson.hpp" 
    #include "headers/logic/ordinamentoPacchi.hpp"
    #include "headers/logic/ottimizzazione.hpp"
    #include "headers/logic/sceltaPacchiNesting.hpp"
    #include "headers/logic/spostaPacchi.hpp"
    #include "headers/logic/trovaDominio.hpp"
    #include "headers/logic/test.hpp"
#pragma endregion

int main (int argc, char* argv[]) 
{  
    try
    {
#pragma region "Global Variables"
        std::string inputJsonPath;
        packVector packs;
        Pallet examplePallet;
#pragma endregion

#if TEST_MODE == 1
        /*
        * FOR NESTING DEBUG, LAUNCH OPERATIONS STRAIGHT FROM HERE 
        */
        testFunction();
#else
#pragma region "BlockCode 1 - Startup Routine"
            try
            {
                if (argc > 1)
                {
                    //Gets arguments as INPUT
                    inputJsonPath = argv[1];
                    consoleStartMessage(inputJsonPath);
                    //Check if file exists 
                    std :: ifstream inputFile(inputJsonPath);
                    if (!inputFile)
                    {
                        //File doesn't exists: throw error
                        throw std :: invalid_argument("Invalid JSON path provided or unable to access file.");
                    } 
                    else
                    {
                        // Open the file 
                        std::ifstream file(inputJsonPath);      
                        // Read the entire file into a string --> https://www.geeksforgeeks.org/rapidjson-file-read-write-in-cpp/
                        std::string jsonStringContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>()); 
                        ReadJson jsonConverter(jsonStringContent);
                        packs = jsonConverter.getPackVector();
                        examplePallet = Pallet(jsonConverter.getPalletInfos());
                    }
                }
                else
                {
                    consoleLog("WARNING: NO JSON FILE PROVIDED");
                    return -1;
                }
            }
            catch(const std::exception& e)
            {
                return consoleErrorMessage(e.what());
            }

#pragma endregion

#pragma region "BlockCode 2 - Pallet Loop"
            
#pragma region "BlockCode 2.1 - Ordinamento Input && Scelta pacchi Nesting"
            /*
            *   Il concetto di base è di avere TUTTI i pacchi sul vettore secondario, in modo da iterare successivamente il sortInput()
            *   e lavorare quindi usando il primo vettore come "vettore operativo" ed il secondo come buffer per i pacchi scartati.
            */
            PalletGroup palletGroup;
            Geometry::ThreeNum_set<int> palletDims = examplePallet.getPalletDims();

            packVector pacchiNonPallettizzabiliByFLAG;
            std::pair<packVector, packVector> dividedPacks;

            dividedPacks = isPalletizable(packs);
            pacchiNonPallettizzabiliByFLAG = dividedPacks.second;

#pragma endregion

#pragma region "BlockCode 2.2 - Crea pallet da pacchi non palletizzabili dal flag"
            /*
            *   Aggiungo tutti i pacchi non palletizzabili by flag a dei Pallet dedicati.
            */
            for (auto pack : pacchiNonPallettizzabiliByFLAG)
            {
                Pallet newPallet(palletDims);
                newPallet.addPack(pack);
                palletGroup.addPallet(&newPallet);
            }
#pragma endregion

#pragma region "BlockCode 2.3 - Nesting loop"
            /*
            *   Raccolgo l'output dei miei threads nel vettore "nestedPallets", mentre in "remainingPacks" i pacchi scartati.
            */
            packVector packsToNest, remainingPacks;
            palletVector nestedPallets;

            packsToNest = dividedPacks.first;
            MainNestLoops(palletDims, &nestedPallets, packsToNest, &remainingPacks);
            for (auto pallet : nestedPallets)
            {
                palletGroup.addPallet(&pallet);
            }
            
#pragma endregion

#pragma endregion

#pragma region "BlockCode 3 - End Routine"
            /*
            *   TODO outputToJSON(), containing these informations: 
            *   > palletGroup (nested and on pallets)
            *   > remainingPacks (not nested, excluded definitely)
            */
#pragma endregion
    
#endif
        return 0;
    }
    catch(const std::invalid_argument& e) 
    {
        return consoleErrorMessage(e.what());
    }
    catch(const std::exception& e)
    {
        return consoleErrorMessage(e.what());
    }  
}