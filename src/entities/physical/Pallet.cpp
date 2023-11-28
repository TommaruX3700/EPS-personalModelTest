#include "../../headers/entities/physical/Pallet.hpp"

Pallet :: Pallet(ThreeNum_set<float> maxDimensions)
{
    this->maxDims.X = maxDimensions.X;
    this->maxDims.Y = maxDimensions.Y;
    this->maxDims.Z = maxDimensions.Z;
    this->pallet.clear();
}

#pragma region "Set methods"
#pragma endregion

#pragma region "Get methods"
    int Pallet :: getPackCount() const
    {
        return this->pallet.size();
    }

    ThreeNum_set<float> Pallet :: getPalletDims() const
    {
        return this->maxDims;
    }
#pragma endregion

#pragma region "Public methods"
    void Pallet :: addPack(ptrPack packToAddPtr)
    {

    }

    void Pallet :: rmvPack(int index = -1)
    {
        if (index == -1)
        {
            //TODO: delete the last one
        }
        else
        {
            //TODO: delete in the defined position and move all other packs positions
        }
    }

    void Pallet :: rmvPackByID(int packID)
    {
        //TODO: remove pack by his ID and move all other packs position
    }


#pragma endregion