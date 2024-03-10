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
    *   Nesting loop, cycling until there are any elements left inside inputPacks
    */
    while (this->inputPacks.size())
    {
        Pack nextPack;
        try
        {
            /*
            *   Using only "front" pack grants me freedom on iterating a single Pack element again, usually after a domain optimization
            */
            nextPack = *this->inputPacks.front();   
            
            /*  
            *   TODO: 
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
            *                       if(firstPlacement()) 
            *                           { 
            *                               //fatto questo, ho generato la mia configurazione ROOT di partenza, che va ora però ottimizzata MUOVENDO i pacchi
            *                               if(nestingForMinN())
            *                                   {
            *                                       // il minimo esiste
            *                                       // pacchi già spostati e nextPack piazzato
            *                                       deleteFrontPack(); 
            *                                   }
            *                               else 
            *                                   {
            *                                       // il minimo NON esiste, modifica ottimizzazione e ricomincia
            *                                   }
            *                           }
            *                       else
            *                           {
            *                               addToNotPalletizable(pacco); 
            *                               deleteFrontPack(); 
            *                           }
            *                               
            *                   } 
            *               else
            *                   {
            *                       addToNotPalletizable(pacco);
            *                       deleteFrontPack(); 
            *                   }
            *           }
            */

            /*
            *   OTHER_FUNCTIONS:
            *       - void placeAtCenter(pacco);
            *               > piazzo al centro del pallet"
            * 
            *       - bool findDomain(pallet.packVector, pacco_in_entrata, old_DominioTotale, optimization, &Dominio_Totale);
            *               > trovo nuovo dominio di piazzamento rispetto alla configurazione attuale, rispettando anche i domini esclusi da "optimization"
            * 
            *       - startingPlacement(pacco, (&Dominio_Totale));
            *               > funzione che piazza il pacco in un punto del piano ammesso dal Dominio_totale
            * 
            *       - addToNotPalletizable(pacco);
            *               > aggiungo pacco a vettore di pacchi non palletizzabili
            * 
            *       - nestingForMinN();
            *               > trovo il min(Ntot), ovvero trovo il valore VERO più vicino al minimo, per cui TUTTI i percorsi che iterconnettono i centri dei pacchi tra loro è il minimo possibile, rispettando le dimensioni dei pacchi, baricentro, limiti del pallet 
            * 
            *       - deleteFrontPack(); 
            *               > elimina nextPack dalla stack "inputPacks"
            */
        }
        catch(const std::exception& e)
        {
            std::cerr << "Pacco non piazzabile:" << e.what() << '\n';
            this->outputNotNestedPacks->push_back(&nextPack);
        }
    }
    /*
    * Copy the nested configuration in the output referenced pallet location.
    */
    *outputPalletConfig = workingPallet;
}