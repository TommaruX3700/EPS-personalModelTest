#ifndef PALLETGROUP_H
#define PALLETGROUP_H

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
    PalletGroup(int max);
    
    #pragma region "Set methods"
        void setMax(int max);
    #pragma endregion

    #pragma region "Public methods"
        int addPallet(ptrPallet palletPtr);
        int rmvPallet(int index);
        int palletCount() const;
        void appendPalletVector(std::vector<ptrPallet> input);
    #pragma endregion
};

#endif