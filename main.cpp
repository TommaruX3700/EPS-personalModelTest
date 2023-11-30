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
        #pragma region "Startup Routine"
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

        #pragma region "End Routine"
            //Output as json (Plan B: output string)

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
    //TODO - Ticket #15
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
        << "------------------------------------------------" << "\n";
    }

    int consoleErrorMessage (std::string errorString) 
    {
        std::cout 
        << "EPS-M: Error" << "\n" << "> ";
        std::cerr
        << errorString << '\n';
        std::cout
        << "------------------------------------------------" << "\n" <<
        std::endl;
        ;
        return -1;
    }

#pragma endregion
