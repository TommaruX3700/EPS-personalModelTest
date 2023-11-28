#include "../../headers/entities/physical/Pallet.hpp"

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

    int Pallet :: packCount()
    {
        return this->pallet.size();
    }
#pragma endregion