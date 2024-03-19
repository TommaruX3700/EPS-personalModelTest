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
    *   X full range involves 2 X range define "points" (min and max) and the related Y height may be both Y min or max 
    */
    this->pointDomain.Xmin_range.num1 = root_center.num1 - (root_dims.num1/2) - (incoming_dims.num1/2);
    this->pointDomain.Xmin_range.num2 = root_center.num1 + (root_dims.num1/2) + (incoming_dims.num1/2);

    this->pointDomain.Xmax_range.num1 = this->pointDomain.Xmin_range.num1;
    this->pointDomain.Xmax_range.num2 = this->pointDomain.Xmin_range.num2;

    this->pointDomain.Ymin_range.num1 = root_center.num2 - (root_dims.num2/2) - (incoming_dims.num2/2);
    this->pointDomain.Ymin_range.num2 = root_center.num2 + (root_dims.num2/2) + (incoming_dims.num2/2);

    this->pointDomain.Ymax_range.num1 = this->pointDomain.Ymin_range.num1;
    this->pointDomain.Ymax_range.num2 = this->pointDomain.Ymin_range.num2;
}

PackDomain::~PackDomain()
{

}

bool PackDomain :: isInDomain(Pack* inputPack)
{
    /*
    * Single domain 
    */
    ThreeNum_set<int> inputCoords = inputPack->getCenterCoords();
    if (isWithinRange(inputCoords))
        return true;
    else
        // Consider optimization
        return false;
}

bool PackDomain :: isWithinRange(ThreeNum_set<int> coordsToChecks)
{
    int Ymin, Ymax, Xmin, Xmax;
    Ymin = this->pointDomain.Ymin_range.num1;
    Ymax = this->pointDomain.Ymin_range.num2;
    Xmin = this->pointDomain.Xmin_range.num1;
    Xmax = this->pointDomain.Xmin_range.num2;

    if (coordsToChecks.num2 <= Ymin)
    {
        // Controllo il range X inferiore
    } 
    else if(coordsToChecks.num2 >= Ymax)
    {
        // Controllo il range X superiore
    }
    else
    {
        // Controllo altri due range
    }
    

    
}

