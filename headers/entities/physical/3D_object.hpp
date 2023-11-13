#include "../geometry/Geometry.hpp"

class ThreeD_object
{
private:
    
public:
    ThreeD_coords<float> objectDims;
    ThreeD_coords<float> oldObject_Dims;
    ThreeD_coords<float> center;
    float weight;
    float density;

    ThreeD_object();
    ~ThreeD_object();

    void setDims(float x, float y, float z);
    void setCenterCoords(ThreeD_coords<float> objectDims); //TODO: verify argument type
    void setWeight(float kg);
    void setOrientation(int orientation);

    ThreeD_coords<float> getDims();
    float getVolume();
    float getDensity();
    
};

ThreeD_object::ThreeD_object()
{

}

ThreeD_object::~ThreeD_object()
{

}
