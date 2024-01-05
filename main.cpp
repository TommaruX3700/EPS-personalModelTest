#define TEST_MODE 1 //Enable to 1 to execute only "TEST_REGION"

#pragma region "Includes" 
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>
    #include <chrono>

    #include "extLibs/nlohmannJSON/json.hpp"

    #include "headers/entities/physical/Pack.hpp"

    #include "headers/logic/ordinamentoPacchi.hpp"
    #include "headers/logic/ottimizzazione.hpp"
    #include "headers/logic/sceltaPacchiNesting.hpp"
    #include "headers/logic/spostaPacchi.hpp"
    #include "headers/logic/trovaDominio.hpp"
#pragma endregion

#pragma region "Function declarations"
    int consoleErrorMessage (std::string errorString);
    void consoleStartMessage (std::string inputString);
    void consoleLog(std::string message);
    
    //json vectorToJson (all the arguments needed);

#pragma endregion

int main (int argc, char* argv[]) 
{  
    try
    {
    #if TEST_MODE == 1
        /*
            TODO: Ticket #25
        */

            //TODO: test creazione Pack
            ThreeNum_set<int> testDims, testCoords;
            testDims.X = 2;
            testDims.Y = 3;
            testDims.Z = 6;
            testCoords.X = 2; 
            testCoords.Y = 2;
            testCoords.Z = 2; 
            float testWeight = 2.4;
            int testID = 10;
            bool testFlag = true;
            Pack testPack(testDims, testCoords, testWeight, testID, testFlag); //constructor dowsnt work at all, it just feels like any implementation works.

            std::string outputStringPack = "";
            ThreeNum_set<int> extractedCoords;
            extractedCoords = testPack.getCenterCoords();
            
            outputStringPack = "Pack coords are: \n X -> " + std::to_string(extractedCoords.X) + "\n Y -> " + std::to_string(extractedCoords.Y) + "\n Z -> " + std::to_string(extractedCoords.Z);
            outputStringPack += "\n Pack Volume: " + std::to_string(testPack.getVolume());
            outputStringPack += "\n Pack ID: " + std::to_string(testPack.getPackID());
            outputStringPack += "\n Pack Density: " + std::to_string(testPack.getDensity());
            
            consoleLog(outputStringPack);

            //TODO: test creazione Grid

            //TODO: test assegnazione Pack su Grid

            //TODO: test eliminazione Pack da Grid

    #else
        #pragma region "CodeBlock 1 - Startup Routine"
            //Gets arguments as INPUT
            const std :: string inputJsonPath = argv[1];
            consoleStartMessage(inputJsonPath);

            //Check if file exists 
            std :: ifstream inputJsonFile;
            inputJsonFile.open(inputJsonPath);
            if (!inputJsonFile)
            {
                //File doesn't exists: throw error
                throw std :: invalid_argument("Invalid JSON path provided or unable to access file.");
            }

            //Ticket: "BlockCode 1 - Lettura file json"
            //  output: std::vector<Pack*> extractedPacksArray;

        #pragma endregion

        #pragma region "CodeBlock 2 - Pallet Loop"
            /*
                Author: 
                    Tommaso Maruzzo
                Description:
                    Main pallet creation loop.
                    Must be iterated untill the end of available packs (palletizablePacksVector).
            */
            
            std::vector<Pack*> palletizablePacksVector;
            std::vector<Pack*> nonPalletizablePacksVector;            

            #pragma region "CodeBlock 2.1 - Ordinamento Input"
                /*
                    Author: 
                        Tommaso Maruzzo
                    Description: 
                        Filters out all the packs by their flags.
                            - not palletizable ones appended on "nonPalletizablePacksVector";
                            - palletizable ones appended on "palletizablePacksVector".
                */

            #pragma endregion
        
            auto start = std::chrono::steady_clock::now();
            std::chrono::duration<double> palletLoopDuration;
            
            //Loop gets back here once ended all the other operations and gets aborted if 15 seconds passed
            while (palletizablePacksVector.size() && (palletLoopDuration.count() < 15))
            {
                #pragma region "CodeBlock 2.2 - Scelta pacchi Nesting"
                    //Execute only once packToNest  routine 

                #pragma endregion

                #pragma region "CodeBlock 2.3 - Nesting loop"
                    // Qui dentro vengono usati i CodeBlocks:
                    // - 2.3.1;
                    // - 2.3.2; 
                    // - 2.3.3.

                #pragma endregion

                //Add non used packs to "packsToNest" vector
                
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
            
            //  put all the rouge packs (from nonPalletizablePacksVector) on single pallets and append them to palletGroup.

        #pragma endregion

        #pragma region "Code Block 3 - End Routine"
            
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
            std::cout << "EPS-M: " << "\n"; 
        #endif
            std ::cout << "> " << message << "\n" << "-------------------------------------------------" << std::endl;
    }

    void consoleStartMessage (std::string inputString)
    {
        #if TEST_MODE == 1
            std::cout << "\nEPS-M_TEST_MODE: START" << "\n";
        #else
            std::cout << "\nEPS-M: START" << "\n";
        #endif
            std::cout << "> Input: " << inputString << "\n" << "-------------------------------------------------" << std::endl;
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
