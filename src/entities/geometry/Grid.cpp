#include "../../../headers/entities/geometry/Grid.hpp"

Grid :: Grid (ThreeNum_set<int> maxDimensions)
{
    TwoNum_set<int> cpySet;

    //XY plane
    cpySet.num1 = maxDimensions.num1;
    cpySet.num2 = maxDimensions.num2;
    this->XY = new Plane(cpySet);

    //XZ plane
    cpySet.num1 = maxDimensions.num1;
    cpySet.num2 = maxDimensions.num3;
    this->XZ = new Plane(cpySet);

    //YZ plane
    cpySet.num1 = maxDimensions.num2;
    cpySet.num2 = maxDimensions.num3;
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

void Grid :: printGrid(int plane)
{
    switch (plane)
    {
        case 1:
            this->XY->printPlane();
            break;
        case 2:
            this->XZ->printPlane();
            break;
        case 3:
            this->YZ->printPlane();
            break;
        default:
            break;
    }
}