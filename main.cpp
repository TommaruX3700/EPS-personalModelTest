#pragma region "Includes" 
    #include <iostream>
    #include <fstream>

    #include "extLibs/nlohmannJSON/json.hpp"

    #include "headers/entities/physical/Pack.hpp"

    #include "headers/logic/ordinamentoPacchi.hpp"
    #include "headers/logic/ottimizzazione.hpp"
    #include "headers/logic/sceltaPacchiNesting.hpp"
    #include "headers/logic/spostaPacchi.hpp"
    #include "headers/logic/trovaDominio.hpp"

#pragma endregion


int main (int argc, char* argv[]) 
{
    try
    {
        #pragma region "Startup Routine"
            std::cout 
            << "#######################" << "\n" 
            << "EPS-MODEL: START" << "\n" 
            << "#######################" << "\n" 
            << "Input argument: " << argv[0] 
            << std::endl;

            //TODO: add input control

        #pragma endregion

        
        
        #pragma region "End Routine"
            //TODO: output as json (use string only as plan B)

        #pragma endregion
        
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "EPS-MODEL: STOPPED BY ERROR" << std::endl;
        std::cerr << e.what() << '\n';
        return -1;
    }   
}