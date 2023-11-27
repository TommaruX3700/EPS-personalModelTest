#include "../../headers/entities/physical/Pack.hpp"

Pack :: Pack (ThreeNum_set<float> dims, ThreeNum_set<float> coords, float WEIGHT, int CODE, bool ROT) 
{

}

Pack :: ~Pack() 
{

}

#pragma region "Operator overrides"
//Check if this works correctly as intended (eg: not only exchanging pointers)

Pack& Pack :: operator=(const Pack& n) 
{
    if (this != &n)
    {
        //Copy all info to new "Pack" object
        this->setDims(n.getDims());
        this->setCenterCoords(n.getCenterCoords());
        this->setWeight(n.getVolume() * n.getDensity());

        this->packID = n.packID;
        this->rotatableFlag = n.rotatableFlag;
        this->palletizableFlag = n.palletizableFlag;
    }
}

bool Pack :: operator==(const Pack& n) 
{
    //TODO: evaluate if any usefull or to delete
    //Compare object packs in the current orientation (?)
   if (
        compareThreeNum_set(this->objectDims, n.objectDims) &&
        this->weight == n.weight
        )
   {
        return true;
   }
   else
   {
        return false;
   }
}

#pragma endregion