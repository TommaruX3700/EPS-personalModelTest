#ifndef THREED_OBJECT
#define THREED_OBJECT

#include "../geometry/Geometry.hpp"

/*
Author:
    Tommaso Maruzzo
Description:
    Basic virtual object for 3D physical entities.
*/

class ThreeD_object
{
protected:
    //NB: protected values are usable by derived classes
    ThreeNum_set<float> objectDims;     //[m]
    ThreeNum_set<float> centerCoords;   //[m]
    float weight;   //[Kg]
    float density;  //[Kg/m3]
    float volume;   //[m3]

private:
    ThreeNum_set<float> originalOrientationDims; //store objectDims values at orientation = 1
    int orientation;    //NB: 1 = originalOrientationDims

    #pragma region "Private Methods"
        void setOrientation(int orientation);
        void backToOriginalPosition();
    #pragma endregion
    
public:
    ThreeD_object();
    ~ThreeD_object();

    #pragma region "Set methods"
        void setDims(ThreeNum_set<float> dims);
        void setCenterCoords(ThreeNum_set<float> coords); 
        void setWeight(float kg);
    #pragma endregion

    #pragma region "Get methods"
        ThreeNum_set<float> getDims() const;
        ThreeNum_set<float> getCenterCoords() const;
        float getVolume() const;
        float getDensity() const;
        int getOrientation() const;
    #pragma endregion

    #pragma region "Methods"
        void changeObjectOrientation(int orientation);
    #pragma endregion

};

#endif
