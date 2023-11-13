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

    void setMax(int max);

    int addPallet(ptrPallet palletPtr);
    int addPallet(ptrPallet palletPtr, int vectorPosition = -1);
    int rmvPallet();
    int rmvPallet(int vectorPosition = -1);
    int palletCount();
};
