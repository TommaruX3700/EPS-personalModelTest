#pragma region "Includes"
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>
    #include <chrono>
    #include <algorithm>
    #include <regex>

    #include "../../extLibs/nlohmannJSON/json.hpp"
    #include "../../extLibs/rapidjson/document.h"

    #include "../physical/Pack.hpp"
    #include "../physical/PalletGroup.hpp"
    #include "../geometry/Grid.hpp"

    #include "../logic/letturaFileJson.hpp" 
    #include "../logic/ordinamentoPacchi.hpp"
    #include "../logic/ottimizzazione.hpp"
    #include "../logic/sceltaPacchiNesting.hpp"
    #include "../logic/spostaPacchi.hpp"
    #include "../logic/trovaDominio.hpp"
#pragma endregion

#pragma region  "Test functions"
void testFunction();
#pragma endregion
