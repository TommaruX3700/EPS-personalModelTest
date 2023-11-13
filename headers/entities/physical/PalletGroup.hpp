#include "Pallet.hpp"
#include <vector>

/*
Author:
    Tommaso Maruzzo
Description:
    PalletGroup made upon a vector of pointers to Pallet objects.
*/

typedef Pallet* ptrPallet;

class PalletGroup
{
private:
    std::vector<ptrPallet> palletGroup;
    int max = 0; 
    
public:
    PalletGroup();
    ~PalletGroup();
};
