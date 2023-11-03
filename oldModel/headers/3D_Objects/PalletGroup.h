// Document: PalletGroup.h
//
// Description: Pallet group class declaration

#pragma once
#ifndef PALLETGROUP_H
#define PALLETGROUP_H

#include <iostream>
#include <vector>
#include ".\Pallet.h"

typedef Pallet* ptrPallet;

class PalletGroup
{
private:
    std ::vector<Pallet *> palletGroup; // vector or a pointers to pallet groups
    int max = 0;                        // Note: "max" indicates the max number of possible pallets. If exceded another PalletGroup should be created. 0 means no limit.

public:
    PalletGroup();        // Note: generic constructor
    PalletGroup(int max); // Note: specific constructor
    ~PalletGroup();

    void set_maximum(int a);

    int add_Pallet(Pallet *pallet);
    void remove_Pallet(int index = NULL);

    int pallet_Count();
};

#endif