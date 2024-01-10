#ifndef CELL_H
#define CELL_H

#include "Geometry.hpp"
#include "../physical/Pack.hpp"

/*
Author: 
    Federico Casarotto
Description:
    Basic geometric grids entity, with few information about:
        - X and Y float coordinates;
        - boolean if the cell is occupied;
        - pointer to Pack, if it's occupied.
*/

using namespace Geometry;

struct Cell
{
    TwoNum_set<int> coords; //this rappresents only position on the plane
    Pack* pack = nullptr;
};

#endif
