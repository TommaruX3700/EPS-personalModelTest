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
    //This method sets cells as occupied only based on center value position and object dimensions
    /*
        I have: 
            > object center: (X,Y,Z)
            > object dimensions: dimX, dimY, dimZ
        Notes:
            > it is not important to consider Pack rotation: it is 
                already considered in the trasformations
    */

    // passo ai metodi di occupazione delle celle ai PIANI e si arrangiano loro singolarmente.
    // es: XY.occupyCells(input pacco); YZ.occupyCells(input pacco); ...
    // idem x metodi di cancellazione.
}

void Grid :: freeOccupiedCells(Pack* inputPack)
{
    /*
    IMPLEMENTATION TODO
        Set all the selected cells to "nullptr"
    */
}