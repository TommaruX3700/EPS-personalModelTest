#ifndef ORDINAMENTOPACCHI_HPP
#define ORDINAMENTOPACCHI_HPP

#include "../entities/physical/Pack.hpp"
#include <vector>
#include <set>

/*
Author:
    Tommaso Maruzzo
Description:
    Vector-Pack sorting method to handle Pack vectors to compute in all the other nesting operations
*/

typedef std::vector<Pack*> packVector;
typedef std::set<packVector> output;

packVector packsToSort; //INPUT
packVector sortedPacks; //OUTPUT_1 -> sorted pointers-to-objects vector
packVector notSortablePacks; //OUPUT_2 -> packs flagged with "not packable"

output sortInput(packVector inputVector);

#endif