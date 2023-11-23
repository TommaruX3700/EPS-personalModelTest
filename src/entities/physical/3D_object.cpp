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
        //set object X, Y, Z dimensions (this.objectDims) 
        this->objectDims.X = dims.X;
        this->objectDims.Y = dims.Y;
        this->objectDims.Z = dims.Z;

        //set originalOrientationDims X, Y, Z dimensions (this.originOrientationDims)
        this->originalOrientationDims.X = dims.X;
        this->originalOrientationDims.Y = dims.Y;
        this->originalOrientationDims.Z = dims.Z;

        //calculate volume (this.volume)
        this->volume = dims.X * dims.Y * dims.Z;

        //sets standard orientation
        this->orientation = 1;
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
        ThreeNum_set<float> originalDims = this->objectDims; //Dummy variable
        
        //Need to reset position before any rotation
        backToOriginalPosition();

        //Changes orientation by switching this.objectDims values
        switch (orientation)
        {
            case 1:
                    //case 1 must refer always to original dims
                break;
            case 2:
                    this->objectDims.X = originalDims.Y;
                    this->objectDims.Y = originalDims.X;
                    this->objectDims.Z = originalDims.Z;
                break;
            case 3:
                    this->objectDims.X = originalDims.X;
                    this->objectDims.Y = originalDims.Z;
                    this->objectDims.Z = originalDims.Y;
                break;
            case 4:
                    this->objectDims.X = originalDims.Y;
                    this->objectDims.Y = originalDims.Z;
                    this->objectDims.Z = originalDims.X;
                break;
            case 5:
                    this->objectDims.X = originalDims.Z;
                    this->objectDims.Y = originalDims.Y;
                    this->objectDims.Z = originalDims.X;
                break;
            case 6:
                    this->objectDims.X = originalDims.Z;
                    this->objectDims.Y = originalDims.X;
                    this->objectDims.Z = originalDims.Y;
                break;
            default:
                break;
        }
    }

#pragma endregion

#pragma region "Get methods"
    ThreeNum_set<float> ThreeD_object :: getDims() const
    {
        //Return a ThreeNum_set object with this.objectDims
        return this->objectDims;
    }

    float ThreeD_object :: getVolume() const
    {
        //Return object volume;
        return this->volume;
    }

    float ThreeD_object :: getDensity() const
    {
        //Return object density;
        return this->density;
    }
    
#pragma endregion

#pragma region "Methods"
    void ThreeD_object :: backToOriginalPosition() 
    {
        //brings back to the original Pack dims and position
        this->objectDims.X = this->originalOrientationDims.X;
        this->objectDims.Y = this->originalOrientationDims.Y;
        this->objectDims.Z = this->originalOrientationDims.Z;
    }
#pragma endregion