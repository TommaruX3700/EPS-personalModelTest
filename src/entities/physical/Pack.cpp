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
        //copy all info in new object
        this->setDims(n.getDims());
        this->setCenterCoords(n.getCenterCoords());
        this->setWeight(n.getVolume() * n.getDensity());

        this->packID = n.packID;
        this->rotatableFlag = n.rotatableFlag;
        //TODO: perform SET for all Pack and 3D_object values
    }
}

Pack& Pack :: operator==(const Pack& n) 
{
    //TODO: make function to compare object packs
    
}

#pragma endregion

#pragma region "Set methods"

#pragma endregion

#pragma region "Get methods"

#pragma endregion