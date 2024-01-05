#include "../../../headers/entities/physical/Pack.hpp"

/*
    Author:
        Tommaso Maruzzo
    Description:
        Pack implementations
*/

using namespace Geometry;

Pack :: Pack (ThreeNum_set<int> dims, ThreeNum_set<int> coords, float packWeight, int packID, bool rotFlag) 
    {
        this->packID = packID;
        this->rotatableFlag = rotFlag;

        this->setDims(dims);
        this->setCenterCoords(coords);
        this->setWeight(packWeight);

    }

#pragma region "Operator overrides"
//Check if this works correctly as intended (eg: not only exchanging pointers)

    void Pack :: operator=(const Pack& n) 
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
        //Compare object packs in the current orientation (?)
        bool comparison = compareThreeNum_set(this->objectDims, n.objectDims);
        if ( comparison == true && this->weight == n.weight )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

#pragma endregion

#pragma region "Set methods"
    void Pack :: setRotatableFlag(bool rotFlag)
    {
        this->rotatableFlag = rotFlag;
    }

    void Pack :: setPackID(int packID)
    {
        this->packID = packID;
    }
#pragma endregion

#pragma region "Get methods"
    int Pack :: getPackID() const
    {
        return this->packID;
    }
#pragma endregion
