#include "../../../headers/entities/geometry/Plane.hpp"

Plane :: Plane (TwoNum_set<float> maxDimensions)
{
    this->maxDimensions.X = maxDimensions.X;
    this->maxDimensions.Y = maxDimensions.Y;

    // Inizializzazione del piano con le celle
    int x = static_cast<int>(maxDimensions.X);
    int y = static_cast<int>(maxDimensions.Y);

    // Allocazione della memoria per il piano
    plane = new Cell*[x];
    for (int i = 0; i < x; ++i) {
        plane[i] = new Cell[y];
    }

    // Inizializzazione delle celle
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            plane[i][j].isFree = true;
            plane[i][j].coords.X = i+0.5;
            plane[i][j].coords.Y = j+0.5;
        }
    }

}

Plane :: ~Plane ()
{
    // Deallocazione della memoria del piano
    int x = static_cast<int>(maxDimensions.X);
    for (int i = 0; i < x; ++i) {
        delete[] plane[i];
    }
    delete[] plane;
}

#pragma region "Override operator"
    Plane& Plane :: operator=(const Plane& n) 
    {
        if (this != &n)
        {
            this->maxDimensions = n.maxDimensions;
            this->plane = n.plane;
        }
    }
#pragma endregion

#pragma region "Set methods"
    void Plane :: setOccupiedCells(Pack* inputPack) 
    {
        
    }
#pragma endregion

#pragma region "Get methods"
    TwoNum_set<float> Plane :: getMaxPlaneDims() const
    {
        return this->maxDimensions;
    }
#pragma endregion