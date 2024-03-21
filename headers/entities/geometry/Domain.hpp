#include <vector>
#include <memory>
#include "PackDomain.hpp"

/*
*   Author: 
*       Tommaso Maruzzo
*   Description:
*       This class is used to display total pallet domain (multiple single domains together).
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
        /*
         *  "Domain" pallet should be re-created every time a pack is added to the pallet configuration.
         */
        Domain(packVector* packsInsidePallet, Pack* incomingPacks);
        ~Domain();
        /*
        *   Controllo se il pacco è in uno spazio valido che rispetta tutte le regole del dominio.
        */
        bool checkSpace(Pack* packToCheck);
};


