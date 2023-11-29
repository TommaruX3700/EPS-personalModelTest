#ifndef SCELTAPACCHINESTING_HPP
#define SCELTAPACCHINESTING_HPP

#include "../entities/physical/Pack.hpp"
#include <vector>

/*
Author: 
    Tommaso Maruzzo
Description: 
    Pack-choosing routine to use in further nesting operations.
*/

std::vector<Pack*> packsToChoose;   //INPUT
std::vector<Pack*> choosenPacks;    //OUTPUT_1: 
std::vector<Pack*> discardedPacks;  //OUTPUT_2: reuse this packs in the next loops

#endif