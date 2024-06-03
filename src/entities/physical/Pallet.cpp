#include "../../../headers/entities/physical/Pallet.hpp"

Pallet ::Pallet()
{
    this->maxDims.num1 = 0;
    this->maxDims.num2 = 0;
    this->maxDims.num3 = 0;
    this->pallet.clear();
}

Pallet ::Pallet(ThreeNum_set<int> maxDimensions)
{
    this->maxDims.num1 = maxDimensions.num1;
    this->maxDims.num2 = maxDimensions.num2;
    this->maxDims.num3 = maxDimensions.num3;
    this->pallet_grid = new Grid(this->maxDims);
    this->pallet.clear();
    this->pallet_id = this;
}

#pragma region "Get methods"
int Pallet ::getPackCount() const
{
    return this->pallet.size();
}

std::vector<Pack> Pallet ::getPackVector() const
{
    return this->pallet;
}

ThreeNum_set<int> Pallet ::getPalletDims() const
{
    return this->maxDims;
}

Pallet *Pallet ::getPalletID() const
{
    return this->pallet_id;
}
#pragma endregion

#pragma region "Public methods"
void Pallet ::addPack(Pack packToAddPtr)
{
    // Add Pack pointer to the end of the "pallet" vector
    this->pallet.push_back(packToAddPtr);
}

void Pallet ::rmvPack(int index = -1)
{
    if (index == -1)
    {
        // Index not specified: delete the last one
        this->pallet.pop_back();
    }
    else
    {
        // Index specified: delete in the ptrPack in the specified position
        this->pallet.erase(this->pallet.begin() + index);
    }
}

void Pallet ::rmvPackByID(int packID)
{
    // Remove pack by his ID
    int position = 0;
    while (this->pallet.at(position).getPackID() != packID && position <= this->pallet.size())
    {
        position++;
    }
    this->pallet.erase(this->pallet.begin() + position);
}

int Pallet :: doesItFit(Pack* input_pack)
{
    // Check if CURRENT xyz just fits into pallet dims
    if (input_pack->getDims().num1 <= this->maxDims.num1 && input_pack->getDims().num2 <= this->maxDims.num2 &&input_pack->getDims().num3 <= this->maxDims.num3)
        return 0; // it will theoretically fit
    else
        return 1; // it wont
}

int Pallet :: findValidPlace(Pack* input_pack)
{
    // try to find a valid place where to put the pack inside pallet's grid
    
    // return 0 if found
    // return 1 if not found
}
#pragma endregion
