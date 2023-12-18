#include "../../../headers/entities/geometry/Grid.hpp"

Grid :: Grid (ThreeNum_set<float> maxDimensions)
{
    TwoNum_set<float> cpySet;

    //XY plane
    cpySet.X = maxDimensions.X;
    cpySet.Y = maxDimensions.Y;
    this->XY = new Plane(cpySet);

    //XZ plane
    cpySet.X = maxDimensions.X;
    cpySet.Y = maxDimensions.Z;
    this->XZ = new Plane(cpySet);

    //YZ plane
    cpySet.X = maxDimensions.Y;
    cpySet.Y = maxDimensions.Z;
    this->YZ = new Plane(cpySet);

}

void Grid :: setOccupiedCells()
{
    //TODO: MAKE A GEOMETRY OBJECT "AREA" 
    //  - make a common object "area" which indentifies an area
    //  - use that object to set those cells to "occupied"
}