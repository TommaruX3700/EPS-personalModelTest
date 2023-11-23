#ifndef THREED_OBJECT
#define THREED_OBJECT

#include "../geometry/Geometry.hpp"

/*
Author:
    Tommaso Maruzzo
Description:
    Basic virtual object for 3D physical entities.
NB: 
    remember to use Member functions!
*/

class ThreeD_object
{
private:
    ThreeNum_set<float> objectDims; //[m]
    //ThreeNum_set<float> oldObject_Dims; //probably not used
    ThreeNum_set<float> centerCoords;   //[m]
    float weight;   //[Kg]
    float density;  //[Kg/m3]
    float volume;   //[m3]
    
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
        ThreeNum_set<float> getDims() const;
        float getVolume() const;
        float getDensity() const;
    #pragma endregion

    #pragma region "Methods"
    #pragma endregion

};

#endif
