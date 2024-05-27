#include "../../../headers/entities/physical/PalletGroup.hpp"

PalletGroup :: PalletGroup()
{

}

PalletGroup :: PalletGroup (int max) 
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
    int PalletGroup :: addPallet(Pallet palletPtr)
    {
        this->palletGroup.push_back(palletPtr);
        return 1;
    }

    int PalletGroup :: rmvPallet(int index = -1)
    {
        if (index == -1)
            this->palletGroup.pop_back();
        else
            this->palletGroup.erase(this->palletGroup.begin() + index);
        return 1;
    }

    int PalletGroup :: palletCount() const
    {
        return this->palletGroup.size();
    }

    void PalletGroup :: appendPalletVector(std::vector<Pallet> input)
    {
        this->palletGroup.insert(this->palletGroup.end(), input.begin(), input.end());
    }

    std::vector<Pallet> PalletGroup :: getPalletGroup() const
    {
        return this->palletGroup;
    }

#pragma endregion
