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
    #include "headers/entities/geometry/Grid.hpp"

    #include "headers/logic/letturaFileJson.hpp" 
    #include "headers/logic/ordinamentoPacchi.hpp"
    #include "headers/logic/ottimizzazione.hpp"
    #include "headers/logic/sceltaPacchiNesting.hpp"
    #include "headers/logic/spostaPacchi.hpp"
    #include "headers/logic/trovaDominio.hpp"
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
                    
                        // Read the entire file into a string 
                        // https://www.geeksforgeeks.org/rapidjson-file-read-write-in-cpp/
                        std::string jsonStringContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>()); 

                        nlohmann::json inputJson = convertStringToJson(jsonStringContent.c_str());

                        packVector packs = getInputPacksInfos(inputJson);
                        //Pallet palletInfo = getInputPalletInfos(inputJson);
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
            /*
                Author: 
                    Tommaso Maruzzo
                Description:
                    Main pallet creation loop.
                    Must be iterated untill the end of available packs (palletizablePacksVector).
            */
            
            std::vector<Pack*> palletizablePacksVector;
            std::vector<Pack*> nonPalletizablePacksVector;            

            #pragma region "BlockCode 2.1 - Ordinamento Input"
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
                #pragma region "BlockCode 2.2 - Scelta pacchi Nesting"
                    //Execute only once packToNest  routine 

                #pragma endregion

                #pragma region "BlockCode 2.3 - Nesting loop"
                    // Qui dentro vengono usati i BlockCodes:
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
            std::cout << "EPS-M: " << "\n"; 
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

    void testFunction()
    {
        std::string outputTestString = "";
        /*
            DOING: Ticket #25
        */

        #pragma region "test Pack & 3D_object"
            //PACK: funziona
            ThreeNum_set<int> testDims, testCoords;
            testDims.X = 4;
            testDims.Y = 6;
            testDims.Z = 2;
            testCoords.X = 5; 
            testCoords.Y = 5;
            testCoords.Z = 5; 

            float testWeight = 2.4;
            int testID = 10;
            bool testFlag = true;

            Pack testPack1(testDims, testCoords, testWeight, testID, testFlag);

            testDims.X = 2;
            testDims.Y = 2;
            testDims.Z = 2;
            testCoords.X = 1; 
            testCoords.Y = 1;
            testCoords.Z = 1; 

            Pack testPack2(testDims, testCoords, 1, 20, true);
                    
            ThreeNum_set<int> extractedDims;
            extractedDims = testPack1.getDims();
            ThreeNum_set<int> extractedCoords;
            extractedCoords = testPack1.getCenterCoords();

            outputTestString = " Pack1 dims are: \n X -> " + std::to_string(extractedDims.X) + "\n Y -> " + std::to_string(extractedDims.Y) + "\n Z -> " + std::to_string(extractedDims.Z) + "\n";
            outputTestString += "\n Pack1 coords are: \n X -> " + std::to_string(extractedCoords.X) + "\n Y -> " + std::to_string(extractedCoords.Y) + "\n Z -> " + std::to_string(extractedCoords.Z) + "\n";
            outputTestString += "\n Pack1 Volume: " + std::to_string(testPack1.getVolume());
            outputTestString += "\n Pack1 ID: " + std::to_string(testPack1.getPackID());
            outputTestString += "\n Pack1 Density: " + std::to_string(testPack1.getDensity());
                    
            //testPack2 = testPack1;

            extractedDims = testPack2.getDims();
            extractedCoords = testPack2.getCenterCoords();

            outputTestString += "\n\n Pack2 dims are: \n X -> " + std::to_string(extractedDims.X) + "\n Y -> " + std::to_string(extractedDims.Y) + "\n Z -> " + std::to_string(extractedDims.Z) + "\n";
            outputTestString += "\n Pack2 coords are: \n X -> " + std::to_string(extractedCoords.X) + "\n Y -> " + std::to_string(extractedCoords.Y) + "\n Z -> " + std::to_string(extractedCoords.Z) + "\n";
            outputTestString += "\n Pack2 Volume: " + std::to_string(testPack2.getVolume());
            outputTestString += "\n Pack2 ID: " + std::to_string(testPack2.getPackID());
            outputTestString += "\n Pack2 Density: " + std::to_string(testPack2.getDensity());
                    
            if (testPack1 == testPack2)
            {
                outputTestString += "\n\n I PACCHI SONO UGUALI :)";
            } else
            {
                outputTestString += "\n I PACCHI SONO DIVERSI :(";
            }
        #pragma endregion

        #pragma region "test creazione Grid"
            //funziona
            ThreeNum_set<int> testMaxDims;
            testMaxDims.X = 20;
            testMaxDims.Y = 20;
            testMaxDims.Z = 20;

            Grid testGrid(testMaxDims);

        #pragma endregion

        #pragma region "test assegnazione Pack su Grid"
            //funziona
            //funziona ma non fa il suo lavoro correttamente.
            testGrid.setOccupiedCells(&testPack1);
            testGrid.setOccupiedCells(&testPack2);
        #pragma endregion

        #pragma region "test eliminazione Pack da Grid"
            //funziona
            //testGrid.freeOccupiedCells(&testPack1);
            //testGrid.freeOccupiedCells(&testPack2);
        #pragma endregion

        std :: cout << "piano1: XY" << std :: endl;
        testGrid.printGrid(1);
        std :: cout << "piano2: YZ" << std :: endl;
        testGrid.printGrid(2);
        std :: cout << "piano3: XZ" << std :: endl;
        testGrid.printGrid(3);
        //consoleLog(outputTestString);
    }

#pragma endregion
