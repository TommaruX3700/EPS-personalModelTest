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
    /*
    *   Pallet on where I will work in this loop
    */
    Pallet workingPallet = *outputPalletConfig;
    /*
    *   Pack vector for scarted packs
    */
    packVector notNestedPacks;
    /*
    *   Convert Vector to Stack, to achive better complexity and operations
    */
    std::stack<Pack*, std::vector<Pack*>> inputStack(this->inputPacks);

    /*
    *   Nesting loop, cycling until there are any elements left inside inputStack
    */
    while (!inputStack.empty())
    {   
        /*
        *   Incoming pack
        */
        Pack nextPack;
        try
        {
            /*
            *   Using only "top" pack grants me freedom on iterating a single Pack element again, usually after a domain optimization
            */
            nextPack = *inputStack.top();   
            
            /*  
            *  #################################################################### TODO - UNDER DEVELOPMENT: ####################################################################
            *       - aggiungere variabile Dominio_Totale anche se non so quanto utile sia, dato che va ricalcolato ad ogni aggiunta di pacco.
            *       - aggiungere variabile per "ottimizzazione" nel calcolo Dominio_Totale (identificare come fare)
            */

            /*   
            *   OPERATIONS: 
            *       if(is primo pacco nel pallet)
            *           {
            *               placeAtCenter(pacco);
            *               // elimina nextPack dalla stack "inputPacks"
            *           } 
            *       else 
            *           {
            *               if(findDomain(pallet.packVector, pacco_in_entrata, old_DominioTotale, optimization, &Dominio_Totale)) 
            *                   {
            *                       if(startingPlacement()) 
            *                           { 
            *                               //fatto questo, ho generato la mia configurazione ROOT di partenza, che va ora però ottimizzata MUOVENDO i pacchi
            *                               if(nestingForMinN())
            *                                   {
            *                                       // il minimo esiste, pacchi già spostati e nextPack piazzato
            *                                       deletePack(); 
            *                                   }
            *                               else 
            *                                   {
            *                                       // il minimo NON esiste, modifica ottimizzazione e ricomincia
            *                                   }
            *                           }
            *                       else
            *                           {
            *                               addToNotPalletizable(pacco); 
            *                               deletePack(); 
            *                           }
            *                               
            *                   } 
            *               else
            *                   {
            *                       addToNotPalletizable(pacco);
            *                       deletePack(); 
            *                   }
            *           }
            *  ###################################################################################################################################################################
            */
        }
        catch(const std::exception& e)
        {
            std::cerr << "Pacco non piazzabile:" << e.what() << '\n';
            this->outputNotNestedPacks->push_back(&nextPack);
        }
    }
    /*
    *   Copy the nested configuration in the output referenced pallet location.
    */
    *outputPalletConfig = workingPallet;
    /*
    *   Copy unnestable packs to output referenced pack vector.
    */
    *outputNotNestedPacks = notNestedPacks;
}

void BoxNesting :: placeAtCenter(Pack input){

}

bool BoxNesting :: findDomain(packVector packsInsidePallet, Pack incomingPack, PackDomain domain_obj, PackDomain optimization_obj){
    return true;
}

bool BoxNesting :: startingPlacement() 
{
    return true;
}

void BoxNesting :: addToNotPalletizable(Pack invalidPack)
{

}

bool BoxNesting :: nestingForMin()
{
    return true;
}

void BoxNesting :: deletePack()
{

}
