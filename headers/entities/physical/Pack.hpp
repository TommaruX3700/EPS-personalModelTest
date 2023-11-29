#ifndef PACK_HPP
#define PACK_HPP

#include "../physical/3D_object.hpp"

/*
Author:
    Tommaso Maruzzo
Description:
    Pack object.
*/

class Pack : ThreeD_object
{
private:
    int packID; //pack ID
    bool rotatableFlag; //if its rotatable or not
    bool palletizableFlag; //if its palletizable or not

    //TODO: delete if operator== completed
    //bool packCompare();
    
public:
    Pack(ThreeNum_set<float> dims, ThreeNum_set<float> coords, float packWeight, int packID, bool rotFlag) {};

    #pragma region "Operators override"
        Pack& operator=(const Pack& n);
        bool operator==(const Pack& n);
    #pragma endregion

    #pragma region "Set methods"
        void setRotatableFlag(bool rotFlag);
        void setPackID(int packID);
    #pragma endregion    

    #pragma region "Get methods"
        int getPackID() const;
    #pragma endregion

};

#endif