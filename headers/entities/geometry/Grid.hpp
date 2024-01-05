#ifndef GRID_H
#define GRID_H

#include "Plane.hpp"

/*
Author:
    Federico Casarotto
Description:
    Grid based upon 3 plane objects. 
    Grid is built upon a ThreeNum_set<int> object ("dimensions"),
    which rappresents the max dimensions of the grids.
*/

class Grid
{
private:
    Plane *XY, *XZ, *YZ;

public:
    Grid(ThreeNum_set<int> maxDimensions); 
    //Necessario passare solamente il parametro pacco, in quanto la posizione dipende dal valore del centro del pacco
    void setOccupiedCells(Pack* inputPack); 
    void freeOccupiedCells(Pack* inputPack);

    void printGridPlanes();
    //TODO: metodo x stampare visivamente in console i 3 piani e relative posizioni/aree di occupazione dei pacchi
};

#endif