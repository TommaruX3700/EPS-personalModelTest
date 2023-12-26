#include "../geometry/Geometry.hpp"
#include "Pack.hpp"
#include <vector>

/*
Author: 
    Tommaso Maruzzo
Description:
    Pallet object.
Notes:
    unordered_set for pallet should be a better use case for performance (insertion and deletion operations), 
    but have to consider all the methods and this problem wont involve a lot of iteration throught pallet items.
*/

typedef Pack* ptrPack; //pointer to Pack object

class Pallet : ThreeD_object
{
private:
    float param_Efficency;
    ThreeNum_set<int> maxDims; //[m]
    std::vector<ptrPack> pallet; 

public:
    Pallet(ThreeNum_set<int> maxDimensions);

    //IDEA: add > and < operators 

    #pragma region "Get methods"
        int getPackCount() const;
        ThreeNum_set<int> getPalletDims() const;
    #pragma endregion

    #pragma region "Public methods"
        void addPack(ptrPack packToAddPtr); 
        void rmvPack(int index = -1); //Delete the pack in the given position from the "pallet" vector
        void rmvPackByID(int packID); //Delete pack by ID    
    #pragma endregion

};