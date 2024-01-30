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

    #include "headers/logic/letturaFileJson.hpp" 
    #include "headers/logic/ordinamentoPacchi.hpp"
    #include "headers/logic/ottimizzazione.hpp"
    #include "headers/logic/sceltaPacchiNesting.hpp"
    #include "headers/logic/spostaPacchi.hpp"
    #include "headers/logic/trovaDominio.hpp"
    #include "headers/logic/test.hpp"
#pragma endregion

#pragma region "Function declarations"
    int consoleErrorMessage(std::string errorString);
    void consoleStartMessage();
    void consoleLog(std::string message);
    void testFunction();
    //json vectorToJson (all the arguments needed);

#pragma endregion

std :: string inputJsonPath;

int main (int argc, char* argv[]) 
{  
    try
    {
        packVector packs;
        Pallet examplePallet;

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
                    consoleStartMessage();

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

            #pragma region "BlockCode 2.2 - Crea pallet da pacchi non palletizzabili dal flag"
                /*
                *   TODO - primo loop per creazione pallet di pacchi non pallettizzabili:
                *   > crea pallet group
                *   > crea pallet per ogni pacco non palletizzabile x via del flag
                *   > aggiungi il singolo pallet al palletGroup
                */
                PalletGroup palletGroup;
                packVector pacchiNonPallettizzabiliByFLAG;
                Geometry::ThreeNum_set<int> palletDims;
                for (auto pack : pacchiNonPallettizzabiliByFLAG)
                {
                    palletDims = examplePallet.getPalletDims();
                    Pallet newPallet(palletDims);
                    newPallet.addPack(pack);
                    palletGroup.addPallet(&newPallet);
                }
            #pragma endregion

            #pragma region "BlockCode 2.3 - Nesting loop"
                /*
                * Qui dentro vengono usati i BlockCodes:
                * - 2.3.1;
                * - 2.3.2; 
                * - 2.3.3.
                * 
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

                do
                {
                    /*
                    * NESTING CODE:
                    * effettua sortInput per il 
                    * lancia multithreading per ogni nesting operation   
                    * 
                    */

                    //palletizablePacksVector = sortInput(nonPalletizablePacksVector);

                    partialTime = std::chrono::steady_clock::now();
                    loopTimer = partialTime - start;
                    if (loopTimer.count() >= 20)
                    {
                        //20 seconds has passed inside the loop
                        throw std::invalid_argument("Pallet loop took up to 15 seconds of execution: check code");
                    }
                } while (nonPalletizablePacksVector.size());
               
            #pragma endregion

            #pragma region "oldLoop"
            // Loop gets back here once ended all the other operations and gets aborted if 15 seconds passed
            // Put all the rouge packs (from nonPalletizablePacksVector) on single pallets and append them to palletGroup.
            /*
            auto start = std::chrono::steady_clock::now();
            std::chrono::duration<double> palletLoopDuration;

            while (palletizablePacksVector.size() && (palletLoopDuration.count() < 15))
            {
                //gets partial Loop time
                auto partialTime = std::chrono::steady_clock::now();
                palletLoopDuration = partialTime - start;
            }

    	    //Ticket "BlockCode 2 - End routine":
            if (palletLoopDuration.count() >= 15)
            {
                //15 seconds has passed inside the loop
                throw std::invalid_argument("Pallet loop took up to 15 seconds of execution: check code");
            }
            */
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

    //TODO:
    //  - [ ] Ticket: "main: End Routine - vectorToJson() implementation"
    //
    //json vectorToJson (all the arguments needed)
    //{ 
    //      Build the output json, structure defined in Documentation.
    //      Examples&Wiki: https://json.nlohmann.me/api/json/
    //}

    void consoleLog (std::string message)
    {
        #if TEST_MODE == 1
            std::cout << "EPS-M_TEST_MODE: " << "\n";
        #else
            std::cout << "EPS-LogMessage: " << "\n\n"; 
        #endif
            std ::cout << message << "\n" << "-------------------------------------------------" << std::endl;
    }

    void consoleStartMessage ()
    {
        #if TEST_MODE == 1
            std::cout << "\nEPS-M_TEST_MODE: START" << "\n";
            std ::cout << "-------------------------------------------------" << std::endl;

        #else
            std::cout << "\nEPS-M: START" << "\n";
            std::cout << "> Input: " << inputJsonPath << "\n" << "-------------------------------------------------" << std::endl;

        #endif
    }

    int consoleErrorMessage (std::string errorString) 
    {
        #if TEST_MODE == 1
            std::cout << "EPS-M_TEST_MODE: ERROR" << "\n" << "> ";
        #else
            std::cout << "EPS-M: ERROR" << "\n" << "> ";
        #endif
            std::cerr << errorString << '\n';
            std::cout << "-------------------------------------------------" << "\n" << std::endl;
        return -1;
    }
    
#pragma endregion
