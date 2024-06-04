#include "../../../headers/entities/geometry/Plane.hpp"
#include <iostream>

Plane :: Plane (TwoNum_set<int> maxDimensions)
{
    this->maxDimensions.num1 = maxDimensions.num1;
    this->maxDimensions.num2 = maxDimensions.num2;

    // Inizializzazione del piano con le celle
    int x = static_cast<int>(maxDimensions.num1);
    int y = static_cast<int>(maxDimensions.num2);

    // Allocazione della memoria per il piano
    plane = new Cell*[x];
    for (int i = 0; i < x; ++i) {
        plane[i] = new Cell[y];
    }

    // Inizializzazione delle celle
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            // by using "+0" we will start considering by the down-left corner of the cells
            plane[i][j].coords.num1 = i+0;
            plane[i][j].coords.num2 = j+0;
        }
    }

}

Plane :: ~Plane ()
{
    // Deallocazione della memoria del piano
    int x = static_cast<int>(maxDimensions.num1);
    for (int i = 0; i < x; ++i) {
        delete[] plane[i];
    }
    delete[] plane;
}

#pragma region "Override operator"
    void Plane :: operator=(const Plane& n) 
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
        // Get a range from -x to +x, usually to rapresent a poligon edge or similar.
        TwoNum_set<int> output;
        output.num1 = abs(center - (dimension/2));
        output.num2 = abs(center + (dimension/2));
        return output;
    }

    void Plane :: fillArea (TwoNum_set<int> set1, TwoNum_set<int> set2, Pack* inputPack)
    {
        //Private method: used to fill an area with Pack pointers
        for (int i = set1.num1; i < set1.num2; i++)
        {
            for (int j = set2.num1; j < set2.num2; j++)
            {
                plane[i][j].pack = inputPack;
            }
        }
    }

    void Plane :: freeArea (TwoNum_set<int> set1, TwoNum_set<int> set2, Pack* inputPack) 
    {
        //Private method: used to delete a Pack pointers area
        for (int i = set1.num1; i < set1.num2; i++)
        {
            for (int j = set2.num1; j < set2.num2; j++)
            {
                if (plane[i][j].pack == inputPack)
                {
                    plane[i][j].pack = nullptr;
                }
            }
        }
    }

    int Plane :: setOccupiedCellsOnPlaneType (Pack* inputPack, int planeType) 
    {
        //This method sets cells as occupied using center value position and object dimensions
        try
        {
            ThreeNum_set<int> center;
            ThreeNum_set<int> dimensions;
            switch (planeType)
            {
                case 1:
                    //XY
                        center = inputPack->getCenterCoords();
                        dimensions = inputPack->getDims();
                        fillArea(findDimsRoutine(center.num1, dimensions.num1), findDimsRoutine(center.num2, dimensions.num2), inputPack);
                    break;

                case 2:
                    //YZ
                        center = inputPack->getCenterCoords();
                        dimensions = inputPack->getDims();
                        fillArea(findDimsRoutine(center.num2, dimensions.num2), findDimsRoutine(center.num3, dimensions.num3), inputPack);
                    break; 
                case 3:
                    //XZ
                        center = inputPack->getCenterCoords();
                        dimensions = inputPack->getDims();
                        fillArea(findDimsRoutine(center.num1, dimensions.num1), findDimsRoutine(center.num3, dimensions.num3), inputPack);
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
        //This method frees cells using center position and object dimensions
        try
        {
            ThreeNum_set<int> center;
            ThreeNum_set<int> dimensions;            
            switch (planeType)
            {
                case 1:
                    //XY
                        center = inputPack->getCenterCoords();
                        dimensions = inputPack->getDims();
                        freeArea(findDimsRoutine(center.num1, dimensions.num1), findDimsRoutine(center.num2, dimensions.num2), inputPack);
                    break;

                case 2:
                    //YZ
                        center = inputPack->getCenterCoords();
                        dimensions = inputPack->getDims();
                        freeArea(findDimsRoutine(center.num2, dimensions.num2), findDimsRoutine(center.num3, dimensions.num3), inputPack);
                    break; 
                case 3:
                    //XZ
                        center = inputPack->getCenterCoords();
                        dimensions = inputPack->getDims();
                        freeArea(findDimsRoutine(center.num1, dimensions.num1), findDimsRoutine(center.num3, dimensions.num3), inputPack);
                    break;

                default:
                    throw std::runtime_error("Use a defined plane type -> 1: XY, 2: YZ, 3: XZ" + '\n');
                    break;
            }
            return 1;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return -1;
        }
    }

#pragma endregion

void Plane :: printPlane()
{
    int x = static_cast<int>(this->maxDimensions.num1);
    int y = static_cast<int>(this->maxDimensions.num2);

    std :: cout << "+";
    for (int i = 0; i < x; i++)
    {
        std :: cout << "--";
    }

    std :: cout << ">\n";
    
    for (int i = 0; i < y; ++i) {
        std :: cout << "|";
        for (int j = 0; j < x; ++j) {
            if (plane[i][j].pack == nullptr)
            {
                std :: cout << " X";
            } else
            {
                std :: cout << " O";
            }
            
        }
        std :: cout << "\n";

    }
    std :: cout << "v\n\n";
}