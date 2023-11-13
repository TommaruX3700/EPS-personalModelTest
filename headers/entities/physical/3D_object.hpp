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
    ThreeNum_set<float> oldObject_Dims;
    ThreeNum_set<float> center;
    float weight;
    float density;
    
public:
    ThreeD_object();
    ~ThreeD_object();

#pragma region "Set_methods"
    void setDims(float x, float y, float z);
    void setCenterCoords(ThreeNum_set<float> objectDims); //TODO: verify argument type
    void setWeight(float kg);
    void setOrientation(int orientation);
#pragma endregion

#pragma region "Get_methods"
    ThreeNum_set<float> getDims();
    float getVolume();
    float getDensity();
#pragma endregion

};

#endif
