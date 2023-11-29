#include "../../../headers/entities/physical/Pack.hpp"

    Pack :: Pack (ThreeNum_set<float> dims, ThreeNum_set<float> coords, float packWeight, int packID, bool rotFlag) 
    {
        this->packID = packID;
        this->rotatableFlag = rotFlag;
        this->weight = packWeight;

        this->centerCoords.X = coords.X;
        this->centerCoords.Y = coords.Y;
        this->centerCoords.Z = coords.Z;

        this->objectDims.X = dims.X;
        this->objectDims.Y = dims.Y;
        this->objectDims.Z = dims.Z;
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
