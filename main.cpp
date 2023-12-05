#pragma region "Includes" 
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>

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

            //Extract packs from it

        #pragma endregion

        #pragma region "CodeBlock 2 - Pallet Loop"

            #pragma region "CodeBlock 2.1 - Ordinamento Input"
                //TODO:
                //  - filters packs by their gets as output a set of 2 vectors: pacchiPalletizzabili & pacchiNonPalletizzabili
            #pragma endregion
        
            #pragma region "CodeBlock 2.2 - Scelta pacchi Nesting"
            
            #pragma endregion

            #pragma region "CodeBlock 2.3 - Nesting loop"
                // Qui dentro vengono usati i CodeBlocks:
                // - 2.3.1;
                // - 2.3.2; 
                // - 2.3.3.

            #pragma endregion

        #pragma endregion

        #pragma region "Code Block 3 - End Routine"
            //Output as json (Plan B: output string)

            //TODO: 
            //  - [ ] Ticket: "main: End Routine - vectorToJson() implementation"
            //  - [ ] Ticket: "End Routine - BlockCode 2.4 - Output pallet"
            //Execute function to prepare the output json
            //nlohmann::json outputJson = vectorToJson(all the arguments needed)
            //std::cout << outputJson << '\n';

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
        << "-------------------------------------------------" << "\n";
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
