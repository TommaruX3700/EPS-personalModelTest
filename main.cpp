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
    int consoleErrorMessage (std::string errorString);
    
    //json vectorToJson (all the arguments needed);

#pragma endregion

int main (int argc, char* argv[]) 
{
    try
    {
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
        
        #pragma region "tests"
            // ThreeNum_set<int> testDims, testCoords;
            // float testWeight;
            // int testID;
            // bool testFlag;
            // Pack testPack(testDims, testCoords, testWeight, testID, testFlag);
            // testPack.getDims(); //inaccessible methods: this means no accessible methods from father class


        #pragma endregion 

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

    void consoleStartMessage (std::string inputString)
    {
        std::cout 
        << "EPS-M: Start" << "\n" 
        << "> Input: " << inputString << "\n"
        << "-------------------------------------------------" << std::endl;
    }

    int consoleErrorMessage (std::string errorString) 
    {
        std::cout 
        << "EPS-M: Error" << "\n" << "> ";
        std::cerr
        << errorString << '\n';
        std::cout
        << "-------------------------------------------------" << "\n" <<
        std::endl;
        ;
        return -1;
    }

#pragma endregion
