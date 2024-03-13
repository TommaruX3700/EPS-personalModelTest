#include "../../../headers/entities/geometry/PackDomain.hpp"

PackDomain::PackDomain(Pack* root_pack, Pack* incoming_pack)
{
    ThreeNum_set<int> root_dims, root_center, incoming_dims;
    root_dims = root_pack->getDims();
    root_center = root_pack->getCenterCoords();
    incoming_dims = incoming_pack->getDims();

    /*
    *   Admitted X points
    */
    this->X_range.h1_min = root_center.num2 - (root_dims.num2/2) - (incoming_dims.num2/2);
    this->X_range.h2_max = root_center.num2 + (root_dims.num2/2) + (incoming_dims.num2/2);
    this->X_range.range.num1 = root_center.num1 - (root_dims.num1/2) - (incoming_dims.num1/2);
    this->X_range.range.num2 = root_center.num1 + (root_dims.num1/2) + (incoming_dims.num1/2);
    /*
    *   Admitted Y points
    */
    this->Y_range.h1_min = root_center.num1 - (root_dims.num1/2) - (incoming_dims.num1/2);
    this->Y_range.h2_max = root_center.num1 + (root_dims.num1/2) + (incoming_dims.num1/2);
    this->Y_range.range.num1 = root_center.num2 - (root_dims.num2/2) - (incoming_dims.num2/2);
    this->Y_range.range.num2 = root_center.num2 + (root_dims.num2/2) + (incoming_dims.num2/2);
    /*
    *   Admitted Z points ARE NOT IMPLEMENTED
    */
}

PackDomain::~PackDomain()
{

}