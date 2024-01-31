#include "../../../headers/logic/messages.hpp"

void consoleLog (std::string message)
{
    #if TEST_MODE == 1
        std::cout << "EPS-M_TEST_MODE: " << "\n";
    #else
        std::cout << "EPS-LogMessage: " << "\n\n"; 
    #endif
        std ::cout << message << "\n" << "-------------------------------------------------" << std::endl;
}

void consoleStartMessage (std::string jsonPathString)
{
    #if TEST_MODE == 1
        std::cout << "\nEPS-M_TEST_MODE: START" << "\n";
        std ::cout << "-------------------------------------------------" << std::endl;
    #else
        std::cout << "\nEPS-M: START" << "\n";
        std::cout << "> Input: " << jsonPathString << "\n" << "-------------------------------------------------" << std::endl;
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