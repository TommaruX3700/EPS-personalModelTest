#define TEST_MODE 0 //Enable to 1 to execute only "TEST_REGION"

#pragma region "Includes" 
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>
    #include <chrono>
    #include <algorithm>
    #include <regex>

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
        std :: string inputJsonPath;
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

            PalletGroup palletGroup;
            packVector pacchiNonPallettizzabiliByFLAG; //ASSEGNARE QUI I PACCHI SCARTATI FLAGGATI NON PALLETTIZZABILI, anzi sostituire con il terzo packVector creato nel BlockCode 2.1
            Geometry::ThreeNum_set<int> palletDims = examplePallet.getPalletDims();

            #pragma region "BlockCode 2.2 - Crea pallet da pacchi non palletizzabili dal flag"
                for (auto pack : pacchiNonPallettizzabiliByFLAG)
                {
                    Pallet newPallet(palletDims);
                    newPallet.addPack(pack);
                    palletGroup.addPallet(&newPallet);
                }
            #pragma endregion

            #pragma region "BlockCode 2.3 - Nesting loop"
                /*
                *   IDEA:
                *   make all the nesting process inside the loop launch as multithread fucntions
                *   give as each inputs the palletizablePacksVector and get 2 outputs for each process:
                *   > a good vector of palletized pallets that will instantly create a new pallet and beign assigned to the pallet group
                *   > a bad one that will be collected (or appended to a vector of discarded packs, that will go throught another set of processes)
                *   recall a Ordinamento Input && Scelta pacchi Nesting prima di far ricominciare il codice con i vettori dei pacchi scartati
                *   settare un timeout per gli scarti
                *   ritornare il palletGroup totale
                * 
                *   TODO - nesting loop e multithreading
                *   > loop (probabile do-while) che prende procede solo se ci sono ancora pacchi "scartati" o il tempo di esecuzione è sotto i 15 secondi
                *   > lancio il multithreading una singola funzione "nesting(scartedPacks)" 
                *   > dentro la funzione "nesting()" effettuo sortInput(), tutte le operazioni del caso e appeno gli scarti di tutto in un secondo output, quindi ho sempre due outputs
                *   > sottraggo al vettore con cui ho lanciato la roba i pacchi che ho messo in input e reitero fino a quando non finisconon
                * 
                *   TODO - attendo e riprovo con gli scarti
                *   > await tutte le funzioni lanciate in multithreading e con l'output scelgo che fare o meno.
                */

                auto start = std::chrono::steady_clock::now();
                auto partialTime = std::chrono::steady_clock::now();
                std::chrono::duration<double> loopTimer;

                /*
                * MOVE THIS AFTER IMPLEMENTATION OF BLKCODE 2.1 and get sortInput() output in this variable:
                * > packs that can be nested
                * > fill this with all the remaining packs after flagged pack deletion
                * > first -> nestable packs on current pallet
                * > second -> scarted packs to reuse later on another thread untill finished o time enlapsed
                */

                std::pair<packVector, packVector> remainingPacks; 
                //Append first part to second part
                /*
                *   Il concetto di base è di avere TUTTI i pacchi sul vettore secondario, in modo da iterare successivamente il sortInput()
                *   e lavorare quindi usando il primo vettore come "vettore operativo" ed il secondo come buffer per i pacchi scartati.
                */

                remainingPacks.second.insert(std::end(remainingPacks.second), std::begin(remainingPacks.first), std::end(remainingPacks.first));
            
                do
                {
                    Pallet newPallet(palletDims);
                    BoxNesting nesting();

                    /*
                    *   > Questa operazione mi permette di rivalutare ad ogni ciclo ogni pacco contenuto nel buffer dei pacchi scartati  
                    */

                    //  remainingPacks = sortInput(remainingPacks.second);

                    /*
                    *   > Launch multithreading and learn how to wait threads and collect outputs
                    *   > Understand how to adapt threads to machine (accordingly to max usable thread numbers)
                    */

                    partialTime = std::chrono::steady_clock::now();
                    loopTimer = partialTime - start;
                    if (loopTimer.count() >= 20)
                    {
                        //20 seconds has passed inside the loop
                        throw std::invalid_argument("Pallet loop took up to 20 seconds of execution: check code");
                    }
                } while (remainingPacks.second.size());
               
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
