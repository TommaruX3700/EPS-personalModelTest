// Document: GridSpace.cpp
//
// Description: 3D space class definition

#include "..\..\headers\Geometry\GridSpace.h"
// #include "..\..\headers\Geometry\Cell.h"
// #include "..\..\headers\Geometry\DefinedGeometry.h"

GridSpace::GridSpace(int x, int y, int z)
{
    // Constructor routine:
    //   > selects new plane
    //   > creates new Cell vector of the specified dimension
    //   > for each of these cells, creates another array of the other dimension
    //   > fills every cell information with their POSITION (on the plane) and STATE (occupied or free, free by default)

    xyPlane.cell = new Cell *[x];
    for (int i = 0; i < x; i++)
    {
        xyPlane.cell[i] = new Cell[y];
        for (int j = 0; j < y; j++)
        {
            xyPlane.cell[i][j] = Cell((float)i, (float)j);
        }
    }

    xzPlane.cell = new Cell *[x];
    for (int i = 0; i < x; i++)
    {
        xzPlane.cell[i] = new Cell[y];
        for (int j = 0; j < y; j++)
        {
            xzPlane.cell[i][j] = Cell((float)i, (float)j);
        }
    }

    yzPlane.cell = new Cell *[x];
    for (int i = 0; i < x; i++)
    {
        yzPlane.cell[i] = new Cell[y];
        for (int j = 0; j < y; j++)
        {
            yzPlane.cell[i][j] = Cell((float)i, (float)j);
        }
    }
}

GridSpace::~GridSpace()
{
    delete[] xyPlane.cell;
    delete[] xzPlane.cell;
    delete[] yzPlane.cell;
}
