#include "../../../headers/entities/geometry/Plane.hpp"

Plane :: Plane (TwoNum_set<float> maxDimensions)
{
    this->maxDimensions.X = maxDimensions.X;
    this->maxDimensions.Y = maxDimensions.Y;
}

Plane :: ~Plane ()
{

}

#pragma region "Get methods"
    TwoNum_set<float> Plane :: getMaxPlaneDims() const
    {
        return this->maxDimensions;
    }
#pragma endregion