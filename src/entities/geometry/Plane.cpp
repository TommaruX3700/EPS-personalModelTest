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
            // by removing "+0.5" we will start considering by the down-left corner of the cells
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

#pragma region "Get methods"
    TwoNum_set<float> Plane :: getMaxPlaneDims() const
    {
        return this->maxDimensions;
    }
#pragma endregion

#pragma region "Cells occupation methods"
    void Plane :: setOccupiedCellsOnPlaneType(Pack* inputPack, int planeType) 
    {
        //This method sets cells as occupied only based on center value position and object dimensions
        /*
            I have: 
                > object center: (X,Y)
                > object dimensions: dimX, dimY, dimZ
            Notes:
                > it is not important to consider Pack rotation: it is 
                    already considered in the trasformations
        DEV_Notes:
          > valutare dimensione i se positiva o negativa
          > put available planes on a set and decide what to use in the procedures without rewriting code 3 times
            > necessario??: la classe Plane si riferisce ad un plane GENERICO e le variabili dimensionali che ci butto in input dipendono interamente dal tipo di piano
            > ok, quindi il "planeType" serve solo a farmi capire quale valore di dims andare a recuperare.
            > 1: dims.X + dims.Y
            > 2: dims.Y + dims.Z
            > 3: dims.Z + dims.X   
        */

       try
       {
            planeType = planeType - 1; 
            std :: vector<ThreeNum_set<float>> planeList = {};
       }
       catch(const std::exception& e)
       {
            std::cerr << "ERROR on Plane.cpp :: setOccupiedCellsOnPLaneType()" << e.what() << '\n';
       }
       

    }

    void Plane :: freeOccupiedCellsOnPlaneType(Pack* inputPack, int planeType)
    {
        /*
        IMPLEMENTATION TODO
            > Set all the selected cells to "nullptr"
            > SETTARE TUTTI I PUNTI CHE OCCUPAVA QUEL PACCO A "nullptr" -> 
                > valutare se racchiudere in un set (interno al pacco) di punti/riferimenti che danno come riferimento area di occupazione, per migliorare e re
        */
    }

#pragma endregion