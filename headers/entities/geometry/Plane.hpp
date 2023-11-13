#include "Cell.hpp"

/*
Author:
    Tommaso Maruzzo
Description:
    Plane object based upon a double dimension Cell object pointer.
    maxX and maxY needs to be compiled in order to always access plane max dimensions, if needed.
*/

class Plane
{
private:
    TwoNum_set<int> maxDimensions;
    Cell** plane;

public:
    Plane();
    Plane(TwoNum_set<int> maxDimensions) {};
    ~Plane();

    TwoNum_set<int> getMaxPlaneDims();
};
