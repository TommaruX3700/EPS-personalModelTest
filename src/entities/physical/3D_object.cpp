#include "../../../headers/entities/physical/3D_object.hpp"

/*
Author:
    Tommaso Maruzzo
Description:
    3D physical entities base class implementation.
*/

#pragma region "Constructors"
    // ThreeD_object :: ThreeD_object() 
    // {
    //     //General constructor
    //     this->objectDims.num1 = 0;
    //     this->objectDims.num2 = 0;
    //     this->objectDims.num3 = 0;

    //     this->centerCoords.num1 = 0;
    //     this->centerCoords.num2 = 0;
    //     this->centerCoords.num3 = 0;

    //     this->weight = 0.0;
    //     this->density = 0.0;
    // }

    // ThreeD_object :: ~ThreeD_object() 
    // {
    //     //General distructor
    //     //use this only for dynamical allocated memory and deallocate it here.
    // }

#pragma endregion

#pragma region "Set methods"
    void ThreeD_object :: setDims(ThreeNum_set<int> dims)
    {
        //set object X, Y, Z dimensions (this.objectDims) 
        this->objectDims.num1 = dims.num1;
        this->objectDims.num2 = dims.num2;
        this->objectDims.num3 = dims.num3;

        //set originalOrientationDims X, Y, Z dimensions (this.originOrientationDims)
        this->originalOrientationDims.num1 = dims.num1;
        this->originalOrientationDims.num2 = dims.num2;
        this->originalOrientationDims.num3 = dims.num3;

        //calculate volume (this.volume)
        float x,y,z;
        x=dims.num1/100.00; y=dims.num2/100.0; z=dims.num3/100.0;
        this->m3Volume = (x) * (y) * (z);

        //sets standard orientation
        this->orientation = 1;
    }

    void ThreeD_object :: setCenterCoords(ThreeNum_set<int> coords)
    {
        //set object certer coordinates (this.centerCoords)
        this->centerCoords.num1 = coords.num1;
        this->centerCoords.num2 = coords.num2;
        this->centerCoords.num3 = coords.num3;
    }

    void ThreeD_object :: setWeight(float kg)
    {
        //set object weight (this.weight) and calculate density (this.density)
        this->weight = kg;
        this->density = kg / this->m3Volume;
    }

    void ThreeD_object :: setOrientation(int orientation)
    {
        //PRIVATE: !!! do not use for common orientation-changes, could lead to unwanted pack behaviours
        this->orientation = orientation;
    }

#pragma endregion

#pragma region "Get methods"
    ThreeNum_set<int> ThreeD_object :: getDims() const
    {
        //Return a ThreeNum_set object with this.objectDims
        return this->objectDims;
    }
    
    ThreeNum_set<int> ThreeD_object :: getCenterCoords() const 
    {
        //Return a ThreeNum_set object with this.centerCoords
        return this->centerCoords;
    }

    float ThreeD_object :: getVolume() const
    {
        //Return object volume;
        return this->m3Volume;
    }

    float ThreeD_object :: getDensity() const
    {
        //Return object density;
        return this->density;
    }
    
    int ThreeD_object :: getOrientation() const 
    {
        return this->orientation;
    }

#pragma endregion

#pragma region "Methods"
    void ThreeD_object :: backToOriginalPosition() 
    {
        //brings back to the original Pack dims and position
        this->objectDims.num1 = this->originalOrientationDims.num1;
        this->objectDims.num2 = this->originalOrientationDims.num2;
        this->objectDims.num3 = this->originalOrientationDims.num3;
    }

    void ThreeD_object :: changeObjectOrientation(int orientation)
    {
        //for object orientation changes
        if (orientation != this->orientation) 
        {
            //Pass-Value Variable
            const ThreeNum_set<int> originalDims = this->objectDims; 

            //Need to reset position before any rotation
            backToOriginalPosition();

            //Changes orientation by switching this.objectDims values
            switch (orientation)
            {
                case 1:
                        //case 1 must refer always to original dims
                        setOrientation(1);
                        this->setDims(this->originalOrientationDims);
                    break;
                case 2:
                        setOrientation(2);
                        this->objectDims.num1 = originalDims.num2;
                        this->objectDims.num2 = originalDims.num1;
                        this->objectDims.num3 = originalDims.num3;
                    break;
                case 3:
                        setOrientation(3);
                        this->objectDims.num1 = originalDims.num1;
                        this->objectDims.num2 = originalDims.num3;
                        this->objectDims.num3 = originalDims.num2;
                    break;
                case 4:
                        setOrientation(4);
                        this->objectDims.num1 = originalDims.num2;
                        this->objectDims.num2 = originalDims.num3;
                        this->objectDims.num3 = originalDims.num1;
                    break;
                case 5:
                        setOrientation(5);
                        this->objectDims.num1 = originalDims.num3;
                        this->objectDims.num2 = originalDims.num2;
                        this->objectDims.num3 = originalDims.num1;
                    break;
                case 6:
                        setOrientation(6);
                        this->objectDims.num1 = originalDims.num3;
                        this->objectDims.num2 = originalDims.num1;
                        this->objectDims.num3 = originalDims.num2;
                    break;
                default:
                    setOrientation(1);
                    this->setDims(this->originalOrientationDims);
                    break;
            }
        }
    }
#pragma endregion
