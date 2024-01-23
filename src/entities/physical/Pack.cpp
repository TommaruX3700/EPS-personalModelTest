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
        empty.X = 0; empty.Y = 0; empty.Z = 0;
        this->packID = 0;
        this->rotatableFlag = 0;
        this->setDims(empty);
        this->setCenterCoords(empty);
        this->setWeight(0);
    }

Pack::Pack(ThreeNum_set<int> dims, ThreeNum_set<int> coords, float packWeight, int packID, bool rotFlag) 
    {
        //TODO: 
        //  - controllare tramite le dimensioni che vengono fornite se la posizione del centro ha senso o meno.
        //  - rilasciare errore di creazione se la creazione è OUT_OF_BOUND o se il pacco entra in CONFLITTO con altri elementi nel piano.
        this->packID = packID;
        this->rotatableFlag = rotFlag;
        this->setDims(dims);
        this->setCenterCoords(coords);
        this->setWeight(packWeight);
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
    int Pack::getPackID() const
    {
        return this->packID;
    }

    std::string Pack::getInfo()
    {
        std::string outputInfos;
        outputInfos.append("Pack_ID: #" + std::to_string(this->getPackID()) + "\n");
        outputInfos.append("Coordinates:\n");
        outputInfos.append("> X: " + std::to_string(this->getCenterCoords().X) + "[cm]\n");
        outputInfos.append("> Y: " + std::to_string(this->getCenterCoords().Y) + "[cm]\n");
        outputInfos.append("> Z: " + std::to_string(this->getCenterCoords().Z) + "[cm]\n");
        outputInfos.append("Dimensions:\n");
        outputInfos.append("> X: " + std::to_string(this->getDims().X) + "[cm]\n");
        outputInfos.append("> Y: " + std::to_string(this->getDims().Y) + "[cm]\n");
        outputInfos.append("> Z: " + std::to_string(this->getDims().Z) + "[cm]\n");
        outputInfos.append("Weight: " + std::to_string(this->weight) + "[kg]\n");
        outputInfos.append("Density: " + std::to_string(this->getDensity()) + "[kg/m3]\n");
        outputInfos.append("Volume: " + std::to_string(this->getVolume()) + "[m3]\n");
        outputInfos.append("Orientation: " + std::to_string(this->getOrientation()) + "\n");
        return outputInfos;
    }
    
#pragma endregion
