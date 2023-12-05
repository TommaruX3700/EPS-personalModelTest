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

output sortInput(packVector inputVector);

#endif