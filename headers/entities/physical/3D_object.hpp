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
private:
    ThreeNum_set<float> objectDims;
    //ThreeNum_set<float> oldObject_Dims; //probably not used
    ThreeNum_set<float> centerCoords;
    float weight;
    float density;
    
public:
    ThreeD_object();
    ~ThreeD_object();

    #pragma region "Operators override"
    #pragma endregion

    #pragma region "Set methods"
        void setDims(ThreeNum_set<float> dims);
        void setCenterCoords(ThreeNum_set<float> coords); 
        void setWeight(float kg);
        void setOrientation(int orientation);
    #pragma endregion

    #pragma region "Get methods"
        ThreeNum_set<float> getDims();
        float getVolume();
        float getDensity();
    #pragma endregion

    #pragma region "Methods"
    #pragma endregion

};

#endif
