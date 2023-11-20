#include "Plane.hpp"

/*
Author:
    Tommaso Maruzzo
Description:
    Grid based upon 3 plane objects. 
    Grid is built upon a ThreeNum_set<int> object ("dimensions"),
    which rappresents the max dimensions of the grids.
*/

class Grid
{
private:
    Plane XY, XZ, YZ;

public:
    Grid(ThreeNum_set<int> maxDimensions); //IMPLEMENTATION TODO: assign to Plane objects Planes based upon 0~dimensions
    ~Grid();
};
