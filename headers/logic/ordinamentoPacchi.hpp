#include "../entities/physical/Pack.hpp"
#include <vector>

/*
Author:
    Tommaso Maruzzo
Description:
    Vector-Pack sorting method to handle Pack vectors to compute in all the other nesting operations
*/

std::vector<Pack*> packsToSort; //INPUT
std::vector<Pack*> sortedPacks; //OUTPUT_1 -> sorted pointers-to-objects vector
std::vector<Pack*> notSortablePacks; //OUPUT_2 -> packs flagged with "not packable"

