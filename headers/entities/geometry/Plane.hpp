#include "Cell.hpp"

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
    TwoNum_set<float> maxDimensions;
    Cell** plane;

public:
    Plane(TwoNum_set<float> maxDimensions) {};
    ~Plane();

    #pragma region "Override Operators"
        Plane& operator=(const Plane& n);
    #pragma endregion

    #pragma region "Set methods"
        void setOccupiedCells(Pack* inputPack); //TODO: evaluate if to return some datatype that tells where there are collisions or not.
    #pragma endregion

        void freeOccupiedCells(Pack* inputPack);

    #pragma region "Get methods"
        TwoNum_set<float> getMaxPlaneDims() const;
    #pragma endregion
};
