#ifndef THREED_OBJECT
#define THREED_OBJECT

#include "../geometry/Geometry.hpp"

/*
Author:
    Tommaso Maruzzo
Description:
    Basic virtual object for 3D physical entities.
*/

using namespace Geometry;

class ThreeD_object
{
    protected: 
        ThreeNum_set<int> objectDims;     //[m]
        ThreeNum_set<int> centerCoords;   //[m]
        float weight;   //[Kg]
        float density;  //[Kg/m3]
        float m3Volume;   //[m3]

        //TODO:Valutare se creare un oggetto "volume" con riferimenti alle celle occupare in griglia

    private:
        ThreeNum_set<int> originalOrientationDims; //store objectDims values at orientation = 1
        int orientation;    //NB: 1 = originalOrientationDims

        void setOrientation(int orientation);
        void backToOriginalPosition();
        
    public:
        #pragma region "Set methods"
            void setDims(ThreeNum_set<int> dims);
            void setCenterCoords(ThreeNum_set<int> coords); 
            void setWeight(float kg);
        #pragma endregion

        #pragma region "Get methods"
            ThreeNum_set<int> getDims() const;
            ThreeNum_set<int> getCenterCoords() const;
            float getVolume() const;
            float getDensity() const;
            int getOrientation() const;
        #pragma endregion

        void changeObjectOrientation(int orientation);
};

#endif
