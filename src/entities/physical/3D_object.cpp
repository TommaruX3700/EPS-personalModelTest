#include "../../headers/entities/physical/3D_object.hpp"

#pragma region "Constructors"
    ThreeD_object :: ThreeD_object() 
    {
        //General constructor
        this->objectDims.X = 0.0;
        this->objectDims.Y = 0.0;
        this->objectDims.Z = 0.0;

        this->centerCoords.X = 0.0;
        this->centerCoords.Y = 0.0;
        this->centerCoords.Z = 0.0;

        this->weight = 0.0;
        this->density = 0.0;
    }

    ThreeD_object :: ~ThreeD_object() 
    {
        //General distructor
        //use this only for dynamical allocated memory and deallocate it here.
    }

#pragma endregion

#pragma region "Operators override"

#pragma endregion

#pragma region "Set methods"
    void ThreeD_object :: setDims(ThreeNum_set<float> dims)
    {
        //set object X, Y, Z dimensions (this.objectDims) and calculates volume (this.volume)
        this->objectDims.X = dims.X;
        this->objectDims.Y = dims.Y;
        this->objectDims.Z = dims.Z;

        this->volume = dims.X * dims.Y * dims.Z;
    }

    void ThreeD_object :: setCenterCoords(ThreeNum_set<float> coords)
    {
        //set object certer coordinates (this.centerCoords)
        this->centerCoords.X = coords.X;
        this->centerCoords.Y = coords.Y;
        this->centerCoords.Z = coords.Z;
    }

    void ThreeD_object :: setWeight(float kg)
    {
        //set object weight (this.weight) and calculate density (this.density)
        this->weight = kg;
        this->density = kg / this->volume;
    }

    void ThreeD_object :: setOrientation(int orientation)
    {
        //changes orientation by switching this.objectDims values
        switch (orientation)
        {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        default:
            
            break;
        }
    }

#pragma endregion

#pragma region "Get methods"
    ThreeNum_set<float> ThreeD_object :: getDims()
    {
        //Return a ThreeNum_set object with this.objectDims
        return this->objectDims;
    }

    float ThreeD_object :: getVolume()
    {
        //Return object volume;
        return this->volume;
    }

    float ThreeD_object :: getDensity()
    {
        //Return object density;
        return this->density;
    }

#pragma endregion

#pragma region "Methods"

#pragma endregion