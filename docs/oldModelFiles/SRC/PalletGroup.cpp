// Document: PalletGroup.cpp
//
// Description: Pallet group class definition

#include "..\..\headers\3D_Objects\PalletGroup.h"

PalletGroup::PalletGroup(int max)
{
    set_maximum(max);
    this->palletGroup.clear();
}

PalletGroup::~PalletGroup()
{
}

void PalletGroup::set_maximum(int a)
{
    this->max = a;
}

int PalletGroup::add_Pallet(Pallet *pallet)
{
    if (this->palletGroup.size() < this->max)
    {
        this->palletGroup.push_back(pallet);
    }
    else
    {
        return 0; // Note: If unable to create another pallet, returns 0.
    }
}

int PalletGroup::pallet_Count()
{
    return this->palletGroup.size();
}