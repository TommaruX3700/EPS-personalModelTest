#include "../geometry/Geometry.hpp"

class ThreeD_object
{
private:
    ThreeD_coords<float> objectDims;
    ThreeD_coords<float> oldObject_Dims;
    ThreeD_coords<float> center;
    float weight;
    float density;
    
public:
    ThreeD_object();
    ~ThreeD_object();

#pragma region "Set_methods"
    void setDims(float x, float y, float z);
    void setCenterCoords(ThreeD_coords<float> objectDims); //TODO: verify argument type
    void setWeight(float kg);
    void setOrientation(int orientation);
#pragma endregion

#pragma region "Get_methods"
    ThreeD_coords<float> getDims();
    float getVolume();
    float getDensity();
#pragma endregion

};