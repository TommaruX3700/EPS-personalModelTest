/*
*   Author: 
*       Tommaso Maruzzo
*   
*   Description:
*       Class made for nesting operations handling.
*       Class should be destroyed once operations are finished.
*/

#include <iostream>
#include <vector>
#include <stack>
#include "../../entities/physical/Pack.hpp"
#include "../../entities/physical/Pallet.hpp"
#include "../../entities/geometry/Domain.hpp"

class BoxNesting
{
    private:
        typedef std::vector<Pack*> packVector;
        typedef std::stack<Pack*> packStack;

        // Pallet con inerente configurazione di nestata di pacchi    
        Pallet* outputPalletConfig;
        // Stack di pacchi palletizzabili
        packVector inputPacks;
        // Vettore di pacchi che non sono riuscito a nestare
        packVector* outputNotNestedPacks;  
        // Configurazione ROOT del pallet
        Pallet rootConfiguration;
        // Dominio_totale del pallet
        Domain TotalDomain;
        // Variabile di controllo operazioni del thread
        bool ThreadHasFinished;
        

        // TODO: "Ottimizzazione", racchiude il dominio di punti da scartare

        /*
        *   Piazzo al centro del pallet
        */
        void placeAtCenter(Pack input);
        
        /*
        *   Metodo che piazza il pacco in un punto del piano ammesso dal Dominio_totale
        */
        bool startingPlacement();
        /*
        *   Trovo il min(Ntot), ovvero trovo il valore VERO più vicino al minimo, per cui TUTTI i percorsi che iterconnettono i centri dei pacchi tra loro è il minimo possibile, rispettando le dimensioni dei pacchi, baricentro, limiti del pallet 
        */
        bool nestingForMin();


    public:
        BoxNesting(Pallet* outPallet, packVector inPacks, packVector* outNotNested);
        ~BoxNesting();
        void nesting();
        /*
        *   Controlla se tutte le operazioni sono terminate o meno.
        */
        bool isFinished();
};

