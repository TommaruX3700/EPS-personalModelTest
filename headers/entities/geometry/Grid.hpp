#ifndef GRID_H
#define GRID_H

#include "Plane.hpp"

/*
*   Author:
*       Tommaso Maruzzo
*   Description:
*       Grid based upon 3 plane objects. 
*       Grid is built upon a ThreeNum_set<int> object ("dimensions"),
*       which rappresents the max dimensions of the grids.
*   
*   NB: 
*       ORIGIN IS AT O(0, 0, 0) -> "the corner"
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

    int FindAndPlace(Pack* input_pack);
    void printGrid(int plane);
};

#endif