#include "../geometry/Geometry.hpp"
#include "Pack.hpp"
#include <vector>

/*
Author: 
    Tommaso Maruzzo
Description:
    Pallet object.
*/

typedef Pack* ptrPack; //pointer to Pack object

class Pallet : ThreeD_object
{
private:
    float param_Efficency;
    std::vector<ptrPack> pallet;

public:
    Pallet();
    Pallet(ThreeNum_set<float> maxDimensions) {};
    ~Pallet();

    #pragma region "Operators override"
    #pragma endregion
    
    #pragma region "Set methods"
    #pragma endregion

    #pragma region "Get methods"
    #pragma endregion

    #pragma region "Public methods"
    void addPack(ptrPack packToAddPtr); //IMPLEMENTATION: add Pack pointer to the end of the "pallet" vector
    
    //OBSOLETE void addPack(ptrPack packToAddPtr, int vectorPos = -1); //IMPLEMENTATION: add Pack pointer to defined position in the pallet vector list
    
    void rmvPack(int index = -1); //IMPLEMENTATION: delete the pack in the given position from the "pallet" vector
    void rmvPackByID(int packID); //IMPLEMENTATION: default -1 but delete the one in the defined position
    
    int packCount();
    #pragma endregion

};