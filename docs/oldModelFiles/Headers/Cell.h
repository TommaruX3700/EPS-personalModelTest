// Document: Cell.h
//
// Description: Single cell class declaration

#ifndef CELL_H
#define CELL_H

#include "DefinedGeometry.h"

class Cell // punto della griglia
{
private:
    cellGraph cell;

public:
    Cell();
    Cell(float dim1, float dim2);
};

#endif