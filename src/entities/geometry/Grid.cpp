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

void Grid :: setOccupiedCells(Pack* inputPack)
{
    this->XY->setOccupiedCells(inputPack);
    this->XZ->setOccupiedCells(inputPack);
    this->YZ->setOccupiedCells(inputPack);
}

void Grid :: freeOccupiedCells(Pack* inputPack)
{
   this->XY->freeOccupiedCells(inputPack);
   this->XZ->freeOccupiedCells(inputPack);
   this->YZ->freeOccupiedCells(inputPack);
}