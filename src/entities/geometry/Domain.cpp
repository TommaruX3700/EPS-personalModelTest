#include "../../../headers/entities/geometry/Domain.hpp"

Domain::Domain(/* args */)
{   
}

Domain::~Domain()
{
}

bool Domain :: findDomain(packVector packsInsidePallet, Pack incomingPack)
{
    /*
    *   TODO:
    *       Use here locals this->totalDomain, this->optimization_obj: they will be always stored in the class.
    */

    return true;
}

bool Domain :: checkSpace(Pack* packToCheck)
{
    /*
    *   TODO:
    *       Check if packToCheck exits within the Domain points
    */

    for(auto domain : domainComponents)
    {
        // Cicle between all registered domines
        if(domain.isInDomain(packToCheck))
        {
            //Pacco è nel dominio
        }
        else
        {
            //Pacco non è nel dominio
        }
    }

    return true;
}