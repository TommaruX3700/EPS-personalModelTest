#include "../geometry/Geometry.hpp"
#include "Pack.hpp"
#include <vector>

/*
Author: 
    Tommaso Maruzzo
Description:
    Pallet object.
*/

typedef Pack* ptrPack; //pointer to Pack object

class Pallet : ThreeD_object
{
private:
    float param_Efficency;
    ThreeNum_set<float> maxDims; //[m]
    std::vector<ptrPack> pallet; 

public:
    Pallet(ThreeNum_set<float> maxDimensions);
    ~Pallet();

    //IDEA: add > and < operators 

    #pragma region "Set methods"
    #pragma endregion

    #pragma region "Get methods"
        int getPackCount() const;
        ThreeNum_set<float> getPalletDims() const;
    #pragma endregion

    #pragma region "Public methods"
        void addPack(ptrPack packToAddPtr); //IMPLEMENTATION: add Pack pointer to the end of the "pallet" vector
        void rmvPack(int index = -1); //IMPLEMENTATION: delete the pack in the given position from the "pallet" vector
        void rmvPackByID(int packID); //IMPLEMENTATION: delete pack by ID    
    #pragma endregion

};