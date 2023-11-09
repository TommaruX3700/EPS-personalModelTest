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
    //int vectorToJson (std::vector<Pack*> &outputVector);

#pragma endregion

int main (int argc, char* argv[]) 
{
    try
    {
        #pragma region "Startup Routine"
            //Gets arguments as INPUT
            const std::string inputJsonPath = argv[0];
            consoleStartMessage(inputJsonPath);

            //Check if file exists 
            std::ifstream inputJsonFile;
            inputJsonFile.open(inputJsonPath);
            if (!inputJsonFile)
            {
                //File doesn't exists: throw error
                throw std::invalid_argument("Invalid JSON path provided or unable to access file.");
            }

            //Extract packs from it

        #pragma endregion

        #pragma region "End Routine"
            //Output as json (Plan B: output string)
            
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

#pragma region "Console messages"
    void consoleStartMessage (std::string inputString)
    {
        std::cout 
        << "#######################" << "\n" 
        << "EPS-MODEL: START" << "\n" 
        << "#######################" << "\n" 
        << "Input argument: " << inputString 
        << std::endl;
    }

    int consoleErrorMessage (std::string errorString) 
    {
            std::cout 
            << "#######################" << "\n" 
            << "EPS-MODEL: ERROR" 
            << "#######################" << "\n" <<
            std::endl;
            
            std::cerr
            << errorString << '\n'
            << "#######################" << "\n";
            return -1;
    }
#pragma endregion
