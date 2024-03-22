#include "../../../headers/entities/physical/Pallet.hpp"

Pallet :: Pallet()
{
    this->maxDims.num1 = 0;
    this->maxDims.num2 = 0;
    this->maxDims.num3 = 0;
    this->pallet.clear();
}

Pallet :: Pallet(ThreeNum_set<int> maxDimensions)
{
    this->maxDims.num1 = maxDimensions.num1;
    this->maxDims.num2 = maxDimensions.num2;
    this->maxDims.num3 = maxDimensions.num3;
    this->pallet.clear();
}

#pragma region "Get methods"
    int Pallet :: getPackCount() const
    {
        return this->pallet.size();
    }

    std::vector<Pack*> Pallet :: getPackVector() const
    {
        return this->pallet;
    }


    ThreeNum_set<int> Pallet :: getPalletDims() const
    {
        return this->maxDims;
    }
#pragma endregion

#pragma region "Public methods"
    void Pallet :: addPack(Pack packToAddPtr)
    {
        //Add Pack pointer to the end of the "pallet" vector
        this->pallet.push_back(&packToAddPtr);
    }

    void Pallet :: rmvPack(int index = -1)
    {
        if (index == -1)
        {
            //Index not specified: delete the last one
            this->pallet.pop_back();
        }
        else
        {
            //Index specified: delete in the ptrPack in the specified position
            this->pallet.erase(this->pallet.begin() + index);
        }
    }

    void Pallet :: rmvPackByID(int packID)
    {
        //Remove pack by his ID
        int position = 0;
        while (this->pallet.at(position)->getPackID() != packID && position <= this->pallet.size()) 
        { 
            position++;
        }
        this->pallet.erase(this->pallet.begin() + position);

        //TEST: useless recursive approach (same complexity)
        // static int position = 0;
        // if (this->pallet.at(position)->getPackID() != packID && position <= this->pallet.size())
        // {
        //     position++;
        //     rmvPackByID(packID);
        // }
        // else if (position <= this->pallet.size())
        // {
        //     this->pallet.erase(this->pallet.begin() + position);
        // }
    }
#pragma endregion
