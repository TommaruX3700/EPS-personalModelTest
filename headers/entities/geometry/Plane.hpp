#include "Cell.hpp"

//#include "../physical/3D_object.hpp" //TODO: test if this gives back errors 


#include <iostream>
#include <vector>

/*
Author:
    Federico Casarotto
Description:
    Plane object based upon a double dimension Cell object pointer.
    maxX and maxY needs to be compiled in order to always access plane max dimensions, if needed.
*/

class Plane
{
private:
    TwoNum_set<int> maxDimensions;
    Cell** plane;
    void fillArea(TwoNum_set<int> set1, TwoNum_set<int> set2, Pack* inputPack);

public:
    Plane(TwoNum_set<int> maxDimensions) {};
    ~Plane();

    #pragma region "Override Operators"
        Plane& operator=(const Plane& n);
    #pragma endregion

    #pragma region "Get methods"
        TwoNum_set<int> getMaxPlaneDims() const;
    #pragma endregion

    #pragma region "Cells occupation methods"
        //TODO: evaluate if to return some datatype that tells where there are collisions or not.
        int setOccupiedCellsOnPlaneType(Pack* inputPack, int planeType); 
        int freeOccupiedCellsOnPlaneType(Pack* inputPack, int planeType);
    #pragma endregion
};
