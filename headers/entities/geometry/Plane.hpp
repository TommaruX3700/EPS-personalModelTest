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
    TwoNum_set<float> maxDimensions;
    Cell** plane;

public:
    Plane(TwoNum_set<float> maxDimensions) {};
    ~Plane();

    #pragma region "Get methods"
        TwoNum_set<float> getMaxPlaneDims() const;
    #pragma endregion
};
