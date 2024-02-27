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

        // Pallet con inerente configurazione di nestata di pacchi    
        Pallet* outputPalletConfig;
        // Vettore di pacchi palletizzabili
        packVector inputPacks;
        // Vettore di pacchi che non sono riuscito a nestare
        packVector* outputNotNestedPacks;  
        // Configurazione ROOT del pallet
        Pallet rootConfiguration;

        /*
        *   TODO:
        *       > includere variabili di "ottimizzazione" (domini punti da scartare, varibili di valutazione, etc)
        */  
        
    public:
        BoxNesting(Pallet* outPallet, packVector inPacks, packVector* outNotNested);
        ~BoxNesting();
        void nesting();
};

