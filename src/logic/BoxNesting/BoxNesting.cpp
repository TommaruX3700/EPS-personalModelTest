#include "../../../headers/logic/BoxNesting/BoxNesting.hpp"

BoxNesting :: BoxNesting(Pallet* outPallet, packVector inPacks, packVector* outNotNested)
{
    this->outputPalletConfig = outPallet;
    this->inputPacks = inPacks;
    this->outputNotNestedPacks = outNotNested;
}

BoxNesting :: ~BoxNesting()
{
    /*
    *   IMPORTANT: Thread creation routine will create lots of this class object
    *       instances, i must make a good garbage collection to ensure performance 
    *       and avoid memory leaking.
    * 
    *   TODO: 
    *       > Delete all structures used in this class;
    *       > Clean all pointers used and created in this class.
    */
}

void BoxNesting :: nesting()
{
    // TODO: capire che DS implementare x il Dominio di piazzamento. 
    // magari una classe, con metodi per aggiungere automaticamente e sommare i domini, dando come input un oggetto pacco.
    // + metodi tutti per interagire con suddetto dominio.

    while (this->inputPacks.size())
    {
        /*
        *   Prendo next Pacco
        *       - Erasing the first element has totally shit complexity O(n), with std::vector
        *       - Consider Data structure conversione to a more adequated one, based on further operations.
        */
        Pack nextPack = *this->inputPacks.front();      
            
        /*
        *   AlG_1: CodeBlock 2.3.1 
        *       Variabili:
        *           - dominio pacco, dominio totale
        *           - 
        */

        try
        {
                
        }
        catch(const std::exception& e)
        {
            std::cerr << "Pacco non piazzabile:" << e.what() << '\n';
            this->outputNotNestedPacks->push_back(&nextPack);
        }
        
        /*
        *   ALG_2: CodeBlock 2.3.2
        */
    }

    /*
    *    Output: vettore pallettizzato
    */
    
}