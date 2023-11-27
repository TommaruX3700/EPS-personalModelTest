#include "../../headers/entities/geometry/Geometry.hpp"

bool compareThreeNum_set(ThreeNum_set <float> firstSet, ThreeNum_set<float> secondSet)
{
    if (
        firstSet.X == secondSet.X && 
        firstSet.Y == secondSet.Y &&
        firstSet.Z == secondSet.Z
        )
    {
        return true;
    } 
    else 
    {
        return false;
    }
}