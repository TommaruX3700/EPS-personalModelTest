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
        //copy info in new object
        n.getDims();
        this->setDims(n.getDims());
        //perform SET for all Pack and 3D_object values
    }
    
}

Pack& Pack :: operator==(const Pack& n) 
{
    
    
}

#pragma endregion