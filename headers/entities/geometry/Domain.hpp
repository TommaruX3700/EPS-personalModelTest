#include <vector>
#include "PackDomain.hpp"

/*
*   Author: 
*       Tommaso Maruzzo
*   Description:
*       This class is used to display pallet domains.
*/

class Domain
{
    private:
        std::vector<PackDomain> domainComponents;
        
    public:
        Domain(/* args */);
        ~Domain();
};


