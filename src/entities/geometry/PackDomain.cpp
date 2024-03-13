#include "../../../headers/entities/geometry/PackDomain.hpp"

PackDomain::PackDomain(Pack* root_pack, Pack* incoming_pack)
{
    ThreeNum_set<int> root_dims, root_center, incoming_dims;
    root_dims = root_pack->getDims();
    root_center = root_pack->getCenterCoords();
    incoming_dims = incoming_pack->getDims();

    /*
    *   Admitted points: each range may be modifiable by the presence of other PackDomains into a TotalDomain.
    *   Z points are not implemented.
    */
    this->pointDomain.Xmin_range.num1 = root_center.num1 - (root_dims.num1/2) - (incoming_dims.num1/2);
    this->pointDomain.Xmin_range.num2 = root_center.num1 + (root_dims.num1/2) + (incoming_dims.num1/2);

    this->pointDomain.Xmax_range.num1 = root_center.num1 - (root_dims.num1/2) - (incoming_dims.num1/2);
    this->pointDomain.Xmax_range.num2 = root_center.num1 + (root_dims.num1/2) + (incoming_dims.num1/2);

    this->pointDomain.Ymin_range.num1 = root_center.num2 - (root_dims.num2/2) - (incoming_dims.num2/2);
    this->pointDomain.Ymin_range.num2 = root_center.num2 + (root_dims.num2/2) + (incoming_dims.num2/2);

    this->pointDomain.Xmax_range.num1 = root_center.num2 - (root_dims.num2/2) - (incoming_dims.num2/2);
    this->pointDomain.Xmax_range.num2 = root_center.num2 + (root_dims.num2/2) + (incoming_dims.num2/2);
}

PackDomain::~PackDomain()
{

}