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
    //TODO: handle method returns
    this->XY->setOccupiedCellsOnPlaneType(inputPack, 1);
    this->XZ->setOccupiedCellsOnPlaneType(inputPack, 2);
    this->YZ->setOccupiedCellsOnPlaneType(inputPack, 3);
}

void Grid :: freeOccupiedCells(Pack* inputPack)
{
    //TODO: handle method returns
   this->XY->freeOccupiedCellsOnPlaneType(inputPack, 1);
   this->XZ->freeOccupiedCellsOnPlaneType(inputPack, 2);
   this->YZ->freeOccupiedCellsOnPlaneType(inputPack, 3);
}