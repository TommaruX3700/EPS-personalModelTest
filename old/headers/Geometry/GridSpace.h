// Document: GridSpace.h
//
// Description: 3D space class declaration

#ifndef GRID_H
#define GRID_H

#include "DefinedGeometry.h"

class GridSpace
{
private:
    planeGraph xyPlane;
    planeGraph xzPlane;
    planeGraph yzPlane;

public:
    GridSpace(int x, int y, int z);
    ~GridSpace();

    void set_occupiedCells(float c1, float c2, float dim1, float dim2);

    // bool isFree(float c1, float c2, float dim1, float dim2);
};

// TODO:
//   funzione per occupazione delle celle, possibilemente utilizzando
//   come base un altro metodo/funzione per l'occupazione singola di una cella.
//
//  es:  occupySpace(coords_t xyz, Pack* pack);

#endif