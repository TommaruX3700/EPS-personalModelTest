#include "../../../headers/entities/physical/PalletGroup.hpp"

PalletGroup :: PalletGroup (int max = 0) 
{
    this->max = max;
}

#pragma region "Set methods"
    void PalletGroup :: setMax(int max)
    {
        this->max = max;
    }
#pragma endregion

#pragma region "Public methods" 
    int PalletGroup :: addPallet(ptrPallet palletPtr)
    {
        //TODO: add error handling
        this->palletGroup.push_back(palletPtr);
        return 1;
    }

    int PalletGroup :: rmvPallet(int index = -1)
    {
        //TODO: add error handling
        if (index == -1)
        {
            //Index not specified: delete the last one
            this->palletGroup.pop_back();
        }
        else
        {
            //Index specified: delete in the ptrPallet in the specified position
            this->palletGroup.erase(this->palletGroup.begin() + index);
        }
        return 1;
    }

    int PalletGroup :: palletCount() const
    {
        return this->palletGroup.size();
    }
#pragma endregion
