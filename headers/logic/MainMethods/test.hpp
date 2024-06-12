#pragma region "Includes"
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>
    #include <chrono>
    #include <algorithm>
    #include <regex>

    #include "../../entities/physical/Pack.hpp"
    #include "../../entities/physical/PalletGroup.hpp"
    #include "../../entities/geometry/Grid.hpp"

#pragma endregion

#pragma region  "Test functions"
bool CheckIfPackFits(Pack i_pack, int pallet_height, int pallet_weight, float* remaining_pallet_area, float full_pallet_area);
void testFunction();
#pragma endregion
