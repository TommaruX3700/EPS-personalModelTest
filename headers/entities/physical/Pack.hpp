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
    int packID;
    bool rotatable;
    bool palletizable;
    
public:
    //Pack(); //probably not used, MUST BE SPECIFIC
    Pack(ThreeNum_set<float> dims, ThreeNum_set<float> coords, float WEIGHT, int CODE, bool ROT) {};
    ~Pack();

    #pragma region "Operators override"
    Pack &operator=(const Pack &n);
    Pack &operator==(const Pack &n);
    #pragma endregion

    #pragma region "Set methods"
    void setRotatable(bool ROT);
    void setPackID(int CODE);
    #pragma endregion    

    #pragma region "Get methods"
    int getPackID();
    #pragma endregion

    #pragma region "Methods"
    #pragma endregion

};
