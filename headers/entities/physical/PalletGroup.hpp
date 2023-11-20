#include "Pallet.hpp"
#include <vector>

/*
Author:
    Tommaso Maruzzo
Description:
    PalletGroup made upon a vector of pointers to Pallet objects.
    Class provides a max int  parameter to check if the pallet limit is somehow exceeded.
*/

typedef Pallet* ptrPallet;

class PalletGroup
{
private:
    std::vector<ptrPallet> palletGroup;
    int max = 0; 
    
public:
    PalletGroup();
    PalletGroup(int max) {};
    ~PalletGroup();
    
    #pragma region "Operators override"
    #pragma endregion
    
    #pragma region "Set methods"
    void setMax(int max);
    #pragma endregion

    #pragma region "Get methods"
    #pragma endregion

    #pragma region "Methods"
    int addPallet(ptrPallet palletPtr);
    int addPallet(ptrPallet palletPtr, int vectorPosition = -1);
    int rmvPallet();
    int rmvPallet(int vectorPosition = -1);
    int palletCount();
    #pragma endregion
};
