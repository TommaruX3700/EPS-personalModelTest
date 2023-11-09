// Document: Pallet.cpp
//
// Description: Pallet class definition

#include "..\..\headers\3D_Objects\Pallet.h"

Pallet::Pallet(float x, float y, float z)
{
    set_Dims(x, y, z);
    this->pallet.clear();
}

Pallet::~Pallet()
{
    this->pallet.clear();
}

void Pallet::set_Dims(float x, float y, float z)
{
    this->palletDims.x = x;
    this->palletDims.y = y;
    this->palletDims.z = z;
}

definedObject Pallet::Pallet::get_Dims()
{
    definedObject out;
    out.x = this->palletDims.x;
    out.y = this->palletDims.y;
    out.z = this->palletDims.z;
    return out;
}

void Pallet::add_Pack(Pack *a, int index = NULL)
{
    if (index == NULL)
    {
        this->pallet.push_back(a);
    }
    else
    {
        this->pallet.insert(this->pallet.begin() + index, a);
    };
}

void Pallet::remove_Pack(int index)
{
    if (index < 0)
    {
        this->pallet.erase(this->pallet.end());
    }
    else
    {
        this->pallet.erase(this->pallet.begin() + index);
    };
}

int Pallet::pack_Count()
{
    return this->pallet.size();
}