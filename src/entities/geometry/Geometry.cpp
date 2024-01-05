#include "../../../headers/entities/geometry/Geometry.hpp"

/*
    Author:
        Tommaso Maruzzo
    Description:
        Geometry namespace implementations
*/

bool Geometry::compareThreeNum_set(Geometry::ThreeNum_set<int> firstSet, Geometry::ThreeNum_set<int> secondSet)
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
