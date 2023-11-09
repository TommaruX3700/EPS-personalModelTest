#include <iostream>
#include <string>

#include "extLibs/nlohmannJSON/json.hpp"

#include "headers/entities/physical/Pack.hpp"

#include "headers/logic/ordinamentoPacchi.hpp"
#include "headers/logic/ottimizzazione.hpp"
#include "headers/logic/sceltaPacchiNesting.hpp"
#include "headers/logic/spostaPacchi.hpp"
#include "headers/logic/trovaDominio.hpp"

int main (int argc, char* argv[]) 
{
    try
    {
        std::string outputList = "";

        std::cout 
        << "#######################" << "\n" 
        << "EPS-MODEL: START" << "\n" 
        << "#######################" << "\n" 
        << "Input argument: " << argv[0] 
        << std::endl;

        //TODO: add input control
        //TODO: evaluate json as output or make a function to build correct output string

        std::cout << outputList << std::endl;
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "EPS-MODEL: STOPPED BY ERROR" << std::endl;
        std::cerr << e.what() << '\n';
        return -1;
    }   
}