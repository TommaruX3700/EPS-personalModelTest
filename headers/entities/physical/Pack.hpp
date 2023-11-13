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
    Pack(/* args */);
    ~Pack();
};

Pack::Pack(/* args */)
{
}

Pack::~Pack()
{
}


