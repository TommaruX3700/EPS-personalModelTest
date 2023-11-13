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
    Pack();
    Pack(float X, float Y, float Z, float WEIGHT, int CODE, bool ROT) {};
    ~Pack();

    Pack &operator=(const Pack &n);
    Pack &operator==(const Pack &n);

    void setRotatable(bool ROT);
    void setPackID(int CODE);
    
    int getPackID();
};
