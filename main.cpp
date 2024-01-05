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
    int consoleErrorMessage(std::string errorString);
    void consoleStartMessage();
    void consoleLog(std::string message);
    
    //json vectorToJson (all the arguments needed);

#pragma endregion

int main (int argc, char* argv[]) 
{  
    try
    {
        consoleStartMessage();

    #if TEST_MODE == 1

        /*
            TODO: Ticket #25
        */
#pragma region "test Pack & 3D_object"
            //PACK: DONE
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

            Pack testPack1(testDims, testCoords, testWeight, testID, testFlag); //constructor dowsnt work at all, it just feels like any implementation works.
            
            testDims.X = 1;
            testDims.Y = 1;
            testDims.Z = 1;
            testCoords.X = 1; 
            testCoords.Y = 1;
            testCoords.Z = 1; 

            Pack testPack2(testDims, testCoords, 1, 20, true);
            
            ThreeNum_set<int> extractedDims;
            extractedDims = testPack1.getDims();
            ThreeNum_set<int> extractedCoords;
            extractedCoords = testPack1.getCenterCoords();

            std::string outputStringPack = "";
            outputStringPack = " Pack1 dims are: \n X -> " + std::to_string(extractedDims.X) + "\n Y -> " + std::to_string(extractedDims.Y) + "\n Z -> " + std::to_string(extractedDims.Z) + "\n";
            outputStringPack += "\n Pack1 coords are: \n X -> " + std::to_string(extractedCoords.X) + "\n Y -> " + std::to_string(extractedCoords.Y) + "\n Z -> " + std::to_string(extractedCoords.Z) + "\n";
            outputStringPack += "\n Pack1 Volume: " + std::to_string(testPack1.getVolume());
            outputStringPack += "\n Pack1 ID: " + std::to_string(testPack1.getPackID());
            outputStringPack += "\n Pack1 Density: " + std::to_string(testPack1.getDensity());

            //testPack2 = testPack1;

            extractedDims = testPack2.getDims();
            extractedCoords = testPack2.getCenterCoords();

            outputStringPack += "\n\n Pack2 dims are: \n X -> " + std::to_string(extractedDims.X) + "\n Y -> " + std::to_string(extractedDims.Y) + "\n Z -> " + std::to_string(extractedDims.Z) + "\n";
            outputStringPack += "\n Pack2 coords are: \n X -> " + std::to_string(extractedCoords.X) + "\n Y -> " + std::to_string(extractedCoords.Y) + "\n Z -> " + std::to_string(extractedCoords.Z) + "\n";
            outputStringPack += "\n Pack2 Volume: " + std::to_string(testPack2.getVolume());
            outputStringPack += "\n Pack2 ID: " + std::to_string(testPack2.getPackID());
            outputStringPack += "\n Pack2 Density: " + std::to_string(testPack2.getDensity());
            
            if (testPack1 == testPack2)
            {
                outputStringPack += "\n\n I PACCHI SONO UGUALI :)";
            } else
            {
                outputStringPack += "\n I PACCHI SONO DIVERSI :(";
            }
#pragma endregion

            consoleLog(outputStringPack);

#pragma region "test creazione Grid"
    //TODO
#pragma endregion

#pragma region "test assegnazione Pack su Grid"
    //TODO
#pragma endregion

#pragma region "test eliminazione Pack da Grid"
    //TODO
#pragma endregion

    #else
        //Gets arguments as INPUT
        const std :: string inputJsonPath = argv[1];

        #pragma region "CodeBlock 1 - Startup Routine"
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
            std ::cout << message << "\n" << "-------------------------------------------------" << std::endl;
    }

    void consoleStartMessage ()
    {
        #if TEST_MODE == 1
            std::cout << "\nEPS-M_TEST_MODE: START" << "\n";
            std ::cout << "-------------------------------------------------" << std::endl;

        #else
            inputJsonPath
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
