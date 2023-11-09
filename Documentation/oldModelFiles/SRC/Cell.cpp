// Document: Cell.cpp
//
// Description: Cell class definition

#include "..\..\headers\Geometry\Cell.h"

Cell::Cell()
{
    cell.centerX = 0.5;
    cell.centerY = 0.5;
    cell.isFree = true;
}

Cell::Cell(float dim1, float dim2)
{
    cell.centerX = dim1 + 0.5;
    cell.centerY = dim2 + 0.5;
    cell.isFree = true;
}