#define TEST_MODE 0 //Enable to 1 to execute only "TEST_REGION"

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
    
    #include "headers/logic/BoxNesting/BoxNesting.hpp"
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

            packVector palletizablePacksVector;
            packVector nonPalletizablePacksVector;            
            //qui verrà aggiunto un vettore con i pacchi già flaggati come non pallettizzabili, da mettere immediatamente su singoli pallets e aggiungere subito al pallet group.
            
            #pragma region "BlockCode 2.1 - Ordinamento Input && Scelta pacchi Nesting"
                /*
                *   FEDERICO - 2 metodi per la suddivisione input e scelta pacchi nesting 
                *   dividiPacchiNonPalletizzabilio(packs); ->> 2 outputs: vettore di pacchi non palletizzabili by flag e tutto il resto
                *   sortInput(packs); ->> 2 outputs: vettore di pacchi che stanno nei limiti imposti del palletExample e tutti quelli invece "scartati"
                */
            #pragma endregion

            #pragma region "To adapt to Federico's modifications"
            /*
            * get sortInput() output in this variable:
            * > packs that can be nested
            * > fill this with all the remaining packs after flagged pack deletion
            * > first -> nestable packs on current pallet
            * > second -> scarted packs to reuse later on another thread untill finished o time enlapsed
            */
            std::pair<packVector, packVector> remainingPacks; 

            /*
            *   Append first part to second part:
            *       Il concetto di base è di avere TUTTI i pacchi sul vettore secondario, in modo da iterare successivamente il sortInput()
            *       e lavorare quindi usando il primo vettore come "vettore operativo" ed il secondo come buffer per i pacchi scartati.
            */
            remainingPacks.second.insert(std::end(remainingPacks.second), std::begin(remainingPacks.first), std::end(remainingPacks.first));

            PalletGroup palletGroup;

            /*
            *   SOSTITUIRE con il terzo packVector creato nel BlockCode 2.1
            *   ASSEGNARE QUI I PACCHI SCARTATI FLAGGATI NON PALLETTIZZABILI 
            */
            packVector pacchiNonPallettizzabiliByFLAG; 

            Geometry::ThreeNum_set<int> palletDims = examplePallet.getPalletDims();
            #pragma endregion

            #pragma region "BlockCode 2.2 - Crea pallet da pacchi non palletizzabili dal flag"
                for (auto pack : pacchiNonPallettizzabiliByFLAG)
                {
                    Pallet newPallet(palletDims);
                    newPallet.addPack(pack);
                    palletGroup.addPallet(&newPallet);
                }
            #pragma endregion

            #pragma region "BlockCode 2.3 - Nesting loop"
                auto start = std::chrono::steady_clock::now();
                auto partialTime = std::chrono::steady_clock::now();
                std::chrono::duration<double> loopTimer;
                
                std::set<std::thread> operatingThreads;
                std::set<Pallet> nestedPallets;

                #pragma region "Thread Loops"

                    do
                    {
                        /*
                        *   LOOP_1 (do-while) (RESUME INTO A FUNCTION) 
                        *       > Questo loop ad ogni ciclo ogni pacco contenuto nel buffer dei pacchi scartati.
                        *       > remainingPacks.first -> pacchi su cui lanciare il thread di nesting
                        *       > remainingPacks.second -> pacchi "scartati" dal nesting e che necessitano di tornare sotto elaborazione fino ad un tot massimo.
                        */

                        // remainingPacks = sortInput(remainingPacks.second);
                        packVector notNested;
                        Pallet newPallet(palletDims);
                        //add pallet vector reference to save reference
                        nestedPallets.insert(newPallet);
                        BoxNesting threadOperation();
                        std::thread newThread (&BoxNesting::nesting, &threadOperation, &newPallet, &remainingPacks.first, &notNested);
                        operatingThreads.insert(newThread);
                        
                        //TODO:this wont work because it notNested may be compiled or not: use this informations in the join loop
                        remainingPacks.second.insert(remainingPacks.second.end(), notNested.begin(), notNested.end());

                        partialTime = std::chrono::steady_clock::now();
                        loopTimer = partialTime - start;

                        if (loopTimer.count() >= 20)
                        {
                            throw std::invalid_argument("Threads creation loop took up to 20 seconds for execution: check code");
                        }

                    } while (remainingPacks.second.size());

                    start = std::chrono::steady_clock::now();
                    while (operatingThreads.size())
                    {
                        /*
                        *   LOOP_2 (RESUME INTO A FUNCTION)
                        *   7.  take all the FIRST vector objects, add them into a pallet and add the pallet to the Pallet Group
                        *   8.  take all the SECOND vector objects and add them to an another vector to recicle (unNestedPacks).
                        *   9.  With this new vector, repeat the LOOP_1 with the same operations, for a max of lets say, 5 times (or timeout)
                        * 
                        *   Make a loop that waits threads to join.
                        *   make it not to enlapse too much time
                        *   NB: note that execution will be blocked until each thread will join correctly.
                        */
                        auto currentThread = --operatingThreads.end();
                        if (currentThread->joinable())
                        {
                            std::thread& joinableThread = const_cast<std::thread&>(*currentThread);
                            joinableThread.join();
                        }
                        
                        partialTime = std::chrono::steady_clock::now();
                        loopTimer = partialTime - start;
                        
                        if (loopTimer.count() >= 20)
                        {
                            throw std::invalid_argument("Threads join loop took up to 20 seconds for execution: check code");
                        }
                    }

                #pragma endregion  

            #pragma endregion

            #pragma endregion

        #pragma region "BlockCode 3 - End Routine"
            
            //Output as json (Plan B: output string)

            //TODO: 
            //  - [ ] Ticket: "main: End Routine - vectorToJson() implementation"
          
            //Execute function to prepare the output json
            //nlohmann::json outputJson = vectorToJson(all the arguments needed)
            //std::cout << outputJson << '\n';

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

#pragma region "Function implementations"

    //TODO: move most of this in external files

    //TODO:
    //  - [ ] Ticket: "main: End Routine - vectorToJson() implementation"
    //
    //json vectorToJson (all the arguments needed)
    //{ 
    //      Build the output json, structure defined in Documentation.
    //      Examples&Wiki: https://json.nlohmann.me/api/json/
    //}
    
#pragma endregion
