#include <vector>
#include "PackDomain.hpp"

/*
*   Author: 
*       Tommaso Maruzzo
*   Description:
*       This class is used to display pallet domain.
*/

class Domain
{
    private:
        typedef std::vector<Pack*> packVector;
        /*
        *   Cicle and modify this PackDomain vector. Their whole mix will define the entire Domain.
        */
        std::vector<PackDomain> domainComponents;
        
    public:
        Domain(/* args */);
        ~Domain();
        /*
        *   Trovo nuovo dominio di piazzamento rispetto alla configurazione attuale, rispettando anche i domini esclusi da "optimization"
        */
        bool findDomain(packVector packsInsidePallet, Pack incomingPack);
        /*
        *   Controllo se il pacco è in uno spazio valido che rispetta tutte le regole del dominio.
        */
        bool checkSpace(Pack* packToCheck);
};


