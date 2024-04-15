#include "../../../headers/entities/physical/Pack.hpp"

/*
    Author:
        Tommaso Maruzzo
    Description:
        Pack implementations
*/

using namespace Geometry;

Pack::Pack()
    {
        Geometry::ThreeNum_set<int> empty;
        empty.num1 = 0; empty.num2 = 0; empty.num3 = 0;
        this->packID = 0;
        this->rotatableFlag = 0;
        this->setDims(empty);
        this->setCenterCoords(empty);
        this->setWeight(0);
    }

Pack::Pack(ThreeNum_set<int> dims, ThreeNum_set<int> coords, float packWeight, int packID, bool rotFlag, bool palletizableFlag) 
    {
        this->packID = packID;
        this->rotatableFlag = rotFlag;
        this->setDims(dims);
        this->setCenterCoords(coords);
        this->setWeight(packWeight);
        this->palletizableFlag = palletizableFlag;
        this->sovrapponibileFlag = true;
    }

#pragma region "Operator overrides"
//Check if this works correctly as intended (eg: not only exchanging pointers)

    void Pack::operator=(const Pack& n) 
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

    bool Pack::operator==(const Pack& n) 
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
    void Pack::setRotatableFlag(bool rotFlag)
    {
        this->rotatableFlag = rotFlag;
    }

    void Pack::setPackID(int packID)
    {
        this->packID = packID;
    }
#pragma endregion

#pragma region "Get methods"
    bool Pack::getSovrapponibileFlag() const
    {
        return this->sovrapponibileFlag;
    }

    int Pack::getPackID() const
    {
        return this->packID;
    }

    bool Pack::getRotatableFlag() const
    {
        return this->rotatableFlag;
    }

    bool Pack::getPalletizableFlag() const
    {
        return this->palletizableFlag;
    }

    std::string Pack::getInfo()
    {
        std::string outputInfos;
        outputInfos.append("Pack_ID: #" + std::to_string(this->getPackID()) + "\n");
        outputInfos.append("Coordinates:\n");
        outputInfos.append("> X: " + std::to_string(this->getCenterCoords().num1) + "[cm]\n");
        outputInfos.append("> Y: " + std::to_string(this->getCenterCoords().num2) + "[cm]\n");
        outputInfos.append("> Z: " + std::to_string(this->getCenterCoords().num3) + "[cm]\n");
        outputInfos.append("Dimensions:\n");
        outputInfos.append("> X: " + std::to_string(this->getDims().num1) + "[cm]\n");
        outputInfos.append("> Y: " + std::to_string(this->getDims().num2) + "[cm]\n");
        outputInfos.append("> Z: " + std::to_string(this->getDims().num3) + "[cm]\n");
        outputInfos.append("Weight: " + std::to_string(this->weight) + "[kg]\n");
        outputInfos.append("Density: " + std::to_string(this->getDensity()) + "[kg/m3]\n");
        outputInfos.append("Volume: " + std::to_string(this->getVolume()) + "[m3]\n");
        outputInfos.append("Orientation: " + std::to_string(this->getOrientation()) + "\n");
        return outputInfos;
    }
    


#pragma endregion
