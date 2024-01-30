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

    #include "../entities/physical/Pack.hpp"
    #include "../entities/physical/PalletGroup.hpp"
    #include "../entities/geometry/Grid.hpp"

    #include "letturaFileJson.hpp" 
    #include "ordinamentoPacchi.hpp"
    #include "ottimizzazione.hpp"
    #include "sceltaPacchiNesting.hpp"
    #include "spostaPacchi.hpp"
    #include "trovaDominio.hpp"
#pragma endregion

#pragma region  "Test functions"
void testFunction();
#pragma endregion
