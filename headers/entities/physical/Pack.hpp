#ifndef PACK_HPP
#define PACK_HPP

#include "../physical/3D_object.hpp"
#include <string>

/*
    Author:
        Tommaso Maruzzo
    Description:
        Pack object.
*/

class Pack : public ThreeD_object
{
private:
    int packID; //N_COLLO
    bool rotatableFlag; //if its rotatable or not
    bool palletizableFlag; //if its palletizable or not
    
public:
    Pack();
    Pack(ThreeNum_set<int> dims, ThreeNum_set<int> coords, float packWeight, int packID, bool rotFlag);

    #pragma region "Operators override"
        void operator=(const Pack& n);
        bool operator==(const Pack& n);
    #pragma endregion

    #pragma region "Set methods"
        void setRotatableFlag(bool rotFlag);
        void setPackID(int packID);
    #pragma endregion    

    #pragma region "Get methods"
        int getPackID() const;
        //getRotatableFlag() missing?
        std::string getInfo();

    #pragma endregion

};

#endif