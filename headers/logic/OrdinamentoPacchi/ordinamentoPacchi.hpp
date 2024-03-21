#ifndef ORDINAMENTOPACCHI_HPP
#define ORDINAMENTOPACCHI_HPP

#include "../entities/physical/Pack.hpp"
#include "quickSort.hpp"
#include "../entities/physical/Pallet.hpp"
#include <vector>

/*
Author:
    Tommaso Maruzzo
Description:
    Vector-Pack sorting method to handle Pack vectors to compute in all the other nesting operations
*/

typedef std::vector<Pack*> packVector;
typedef std::pair<std::vector<Pack*>, std::vector<Pack*>> output;

output isPalletizable(packVector inputVector);
output sortInput(packVector inputVector, Pallet pallet);

#endif