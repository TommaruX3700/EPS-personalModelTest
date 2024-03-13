#include "Geometry.hpp"
#include "../physical/Pack.hpp" 

/*
*   Author: 
*       Tommaso Maruzzo
*   
*   Description:
*       "PackDomain" is defined by:
*           > root pack, the one Domain is "built" around
*           > incoming pack, with the root defines Domain height and ranges
*/

using namespace Geometry;

class PackDomain
{
    /*
    *   The "PackDomain" is defined by:
    *       > root pack, the one Domain is "built" around
    *       > incoming pack, with the root defines Domain height and ranges
    */
    private:
        //Admited points
        GraphRange pointDomain; 

    public:
        PackDomain(Pack* root_pack, Pack* incoming_pack);
        ~PackDomain();
};

/*   
*   IDEA:
*       Copy the idea of Plane class method "findDimsRoutine()" and get then a TwoNum_set of integers, rapresenting both the intervals
*/