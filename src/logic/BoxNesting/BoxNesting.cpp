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
        Pack nextPack;
        try
        {
            nextPack = *this->inputPacks.front();   // Using only "front" pack grants me more freedom if I have to iterate itself again with other ops, afther optimization

#pragma region "AlG1: CodeBlock 2.3.1"
            /*
            *   FOCUS:
            *       - trovare nuovo dominio di piazzamento 
            *   
            *   TODO: 
            *       - aggiungere variabile Dominio_Totale anche se non so quanto utile sia, dato che va ricalcolato ad ogni aggiunta di pacco.
            *       - aggiungere variabile per "ottimizzazione" nel calcolo Dominio_Totale (identificare come fare)
            *   
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
            *                               > trovo il min(Ntot), ovvero trovo il valore VERO più vicino al minimo, per cui TUTTI i percorsi che iterconnettono i centri dei pacchi tra loro è il minimo possibile, rispettando le dimensioni dei pacchi, baricentro, limiti del pallet 
            *                               if(nestingForMinN())
            *                                   {
            *                                       // il minimo esiste
            *                                       // pacchi già spostati e nextPack piazzato
            *                                       // elimina nextPack dalla stack "inputPacks"
            *                                   }
            *                               else 
            *                                   {
            *                                       // il minimo NON esiste, modifica ottimizzazione e ricomincia
            *                                   }
            *                           }
            *                       else
            *                           {
            *                               addToNotPalletizable(pacco); 
            *                               // elimina nextPack dalla stack "inputPacks"
            *                           }
            *                               
            *                   } 
            *               else
            *                   {
            *                       addToNotPalletizable(pacco);
            *                       // elimina nextPack dalla stack "inputPacks"
            *                   }
            *           }
            *       
            *   OTHER_FUNCTIONS:
            *       > void placeAtCenter(pacco);________________________________________________________________________________//piazzo al centro del pallet
            *       > bool findDomain(pallet.packVector, pacco_in_entrata, old_DominioTotale, optimization, &Dominio_Totale);___//trovo nuovo dominio di piazzamento rispetto alla configurazione attuale, rispettando anche i domini esclusi da "optimization"
            *       > startingPlacement(pacco, (&Dominio_Totale));______________________________________________________________//funzione che piazza il pacco in un punto del piano ammesso dal Dominio_totale
            *       > addToNotPalletizable(pacco);______________________________________________________________________________//aggiungo pacco a vettore di pacchi non palletizzabili
            */
#pragma endregion

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