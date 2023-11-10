// Document: Pack.cpp
//
// Description: Pack class definition

#include "..\..\headers\3D_Objects\Pack.h"

Pack::Pack(float X, float Y, float Z, float WGHT, int n_collo, bool ruotabile)
{
    set_dims(X, Y, Z);
    set_weight(WGHT);
    set_packID(n_collo);
    set_isRotatable(ruotabile);
}

Pack::~Pack() {}

void Pack::set_dims(float x, float y, float z)
{
    this->dims.x = x;
    this->dims.y = y;
    this->dims.z = z;

    this->old_dims = this->dims;
}

void Pack::set_centerCoords(float x, float y, float z)
{
    this->center.x = x;
    this->center.y = y;
    this->center.z = z;
}

void Pack::set_weight(float kg)
{
    this->weight = kg;
    this->density = this->weight / ((this->get_Dims()->x) * (this->get_Dims()->y) * (this->get_Dims()->z));
}

void Pack::set_orientation(int a)
{
    switch (a)
    {
    case 0:
        this->dims.x = this->old_dims.x;
        this->dims.y = this->old_dims.y;
        this->dims.z = this->old_dims.z;
        break;

    case 1:
        this->dims.x = this->old_dims.z;
        this->dims.y = this->old_dims.y;
        this->dims.z = this->old_dims.x;
        break;

    case 2:
        this->dims.x = this->old_dims.x;
        this->dims.y = this->old_dims.z;
        this->dims.z = this->old_dims.y;
        break;

    case 3:
        this->dims.x = this->old_dims.y;
        this->dims.y = this->old_dims.x;
        this->dims.z = this->old_dims.z;
        break;

    case 4:
        this->dims.x = this->old_dims.y;
        this->dims.y = this->old_dims.z;
        this->dims.z = this->old_dims.x;
        break;

    case 5:
        this->dims.x = this->old_dims.z;
        this->dims.y = this->old_dims.x;
        this->dims.z = this->old_dims.y;
        break;

    default:
        break;
    }
}

void Pack::set_isRotatable(bool is_rotatable)
{
    this->rotatable = is_rotatable;
}

void Pack::set_packID(int n_collo)
{
    this->packID = n_collo;
}

definedObject *Pack::get_Dims()
{
    return &this->dims;
}

int Pack::get_PackID()
{
    return this->packID;
}