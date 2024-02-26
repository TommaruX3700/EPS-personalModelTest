/*
*   Author: 
*   Tommaso Maruzzo
*   
*   Description:
*   Class made for nesting operations handling.
*   Class should be destroyed once operations are finished.
*/

#include <vector>
#include "../../entities/physical/Pack.hpp"
#include "../../entities/physical/Pallet.hpp"

class BoxNesting
{
    private:
        typedef std::vector<Pack*> packVector;        
        
    public:
        BoxNesting(Pallet* outPallet, packVector inPacks, packVector* outNotNested);
        ~BoxNesting();
        void nesting();
};

