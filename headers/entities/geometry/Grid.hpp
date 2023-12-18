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
    Grid(ThreeNum_set<float> maxDimensions); 

    void setOccupiedCells(Pack* inputPack); //IMPLEMENTATION TODO
    void freeOccupiedCells(Pack* inputPack); //IMPLEMENTATION TODO
};
