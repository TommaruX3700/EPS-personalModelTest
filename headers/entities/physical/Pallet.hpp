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
    
    void addPack(ptrPack packToAddPtr); //IMPLEMENTATION: add Pack pointer to the 
    void addPack(ptrPack packToAddPtr, int vectorPos = NULL); //IMPLEMENTATION: add Pack pointer to defined position in the pallet vector list
    void rmvPack(); //IMPLEMENTATION: delete the last one
    void rmvPack(int vectorPos = -1); //IMPLEMENTATION: default -1 but delete the one in the defined position
    int packCount();

};