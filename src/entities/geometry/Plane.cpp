#include "../../../headers/entities/geometry/Plane.hpp"

Plane :: Plane (TwoNum_set<int> maxDimensions)
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
            // by using "+0" we will start considering by the down-left corner of the cells
            plane[i][j].coords.X = i+0;
            plane[i][j].coords.Y = j+0;
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
    TwoNum_set<int> Plane :: getMaxPlaneDims() const
    {
        return this->maxDimensions;
    }
#pragma endregion

#pragma region "Cells occupation methods"
    TwoNum_set<int> findDimsRoutine (int center, int dimension)
    {
        TwoNum_set<int> output;
        output.X = abs(center - (dimension/2));
        output.Y = abs(center + (dimension/2));
        return output;
    }

    void Plane :: fillArea (TwoNum_set<int> set1, TwoNum_set<int> set2, Pack* inputPack)
    {
        //Private method: used to fill an area with Pack pointers
        for (int i = set1.X; i < set1.Y; i++)
            {
                for (int j = set2.X; j < set2.Y; j++)
                {
                    plane[i][j].pack = inputPack;
                }
            }
    }

    void Plane :: deleteArea (TwoNum_set<int> set1, TwoNum_set<int> set2, Pack* inputPack) 
    {
        //Private method: used to delete a Pack pointers area
        
    }

    int Plane :: setOccupiedCellsOnPlaneType (Pack* inputPack, int planeType) 
    {
        //This method sets cells as occupied only based on center value position and object dimensions
       try
       {
            switch (planeType)
            {
                case 1:
                    //XY
                        ThreeNum_set<int> center = inputPack->getCenterCoords();
                        ThreeNum_set<int> dimensions = inputPack->getDims();
                        fillArea(findDimsRoutine(center.X, dimensions.X), findDimsRoutine(center.Y, dimensions.Y), inputPack);
                    break;
                
                case 2:
                    //YZ
                        ThreeNum_set<int> center = inputPack->getCenterCoords();
                        ThreeNum_set<int> dimensions = inputPack->getDims();
                        fillArea(findDimsRoutine(center.Y, dimensions.Y), findDimsRoutine(center.Z, dimensions.Z), inputPack);
                    break;

                case 3:
                    //XZ
                        ThreeNum_set<int> center = inputPack->getCenterCoords();
                        ThreeNum_set<int> dimensions = inputPack->getDims();
                        fillArea(findDimsRoutine(center.X, dimensions.X), findDimsRoutine(center.Z, dimensions.Z), inputPack);
                    break;
                
                default:
                    throw std::runtime_error("Use a defined plane type -> 1: XY, 2: YZ, 3: XZ" + '\n');
                    break;
            }
            return 1;
       }
       catch(const std::exception& e)
       {
            std::cerr << "ERROR on Plane.cpp :: setOccupiedCellsOnPLaneType()" << e.what() << '\n';
            return -1;
       }
       
    }

    int Plane :: freeOccupiedCellsOnPlaneType(Pack* inputPack, int planeType)
    {
        /*
        IMPLEMENTATION TODO
            > Set all the selected cells to "nullptr"
            > SETTARE TUTTI I PUNTI CHE OCCUPAVA QUEL PACCO A "nullptr" -> 
                > valutare se racchiudere in un set (interno al pacco) di punti/riferimenti che danno come riferimento area di occupazione, per migliorare e re
        
            Dev_notes:
            > oggettivamente, se ho la coordinata centrale del pacco, mi "basterà" andare sfruttare la procedura simile all'occupazione celle e aggiungere un controllo 
                se le suddette celle siano o meno occupare dal puntatore al pacco di nostro interesse.
        
        */
        try
        {

            return 1;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return -1;
        }
    }

#pragma endregion