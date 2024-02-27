/*
*   Author: 
*   Tommaso Maruzzo
*   
*   Description:
*   Class made for nesting operations handling.
*   Class should be destroyed once operations are finished.
*/

#include <iostream>
#include <vector>
#include "../../entities/physical/Pack.hpp"
#include "../../entities/physical/Pallet.hpp"

class BoxNesting
{
    private:
        typedef std::vector<Pack*> packVector;    
        Pallet* outputPalletConfig;
        packVector inputPacks;
        packVector* outputNotNestedPacks;  
        /*
        *   TODO:
        *       > generare variabile ROOT/Config basata sul pallet (recuperare info pallet)
        *       > includere variabili di "ottimizzazione" (domini punti da scartare, varibili di valutazione, etc)
        */  
        
    public:
        BoxNesting(Pallet* outPallet, packVector inPacks, packVector* outNotNested);
        ~BoxNesting();
        void nesting();
};

