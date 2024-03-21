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
        firstSet.num1 == secondSet.num1 && 
        firstSet.num2 == secondSet.num2 && 
        firstSet.num3 == secondSet.num3    
        )
    {
        return true;
    } 
    else 
    {
        return false;
    }
}
