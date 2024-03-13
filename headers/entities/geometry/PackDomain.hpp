#include "Geometry.hpp"

/*
*   Author: 
*       Tommaso Maruzzo
*   
*   Description:
*       This class is used to display pack domains: each pack has one.
*       
*   Domain characteristics:
*       Space rappresentation of available points, on a grid, where packs should go.
*/

class PackDomain
{
    private:
        
    public:
        PackDomain();
        ~PackDomain();
};
/*   
*   How should I rappresent an interval of points into a XY graph, in C++?
*   IDEA:
*       Copy the idea of Plane class method "findDimsRoutine()" and get then a TwoNum_set of integers, rapresenting both the intervals
*   Every "Interval" will be defined by: 
*       {
*           int height1  //how many is the interval "detatched" by its parallel axis
*           int height2  //height1-pack/
*           TwoNum_set interval //effective interval
*       }
*/

// I need to rapresent make a Datastructure for a "Domain" wich is described by 4 different ints. I then want to make another DataStructure "DomainTotal", made of multiple instances of the "Domain". "DomainTotal" should be 
