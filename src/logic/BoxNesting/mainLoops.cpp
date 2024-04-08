#include "../../../headers/logic/BoxNesting/mainLoops.hpp"

void MainNestLoops(dims palletDims, palletVector* outPalletVector, packVector inPacksToNest, packVector* outUnNestablePacks)
{

#pragma region "LOOP_1"
    /*
     *   Questo loop ad ogni ciclo ogni pacco contenuto nel buffer dei pacchi scartati.
     *   > packs.first -> pacchi su cui lanciare il thread di nesting
     *   > packs.second -> pacchi "scartati" dal nesting e che necessitano di tornare sotto elaborazione fino ad un tot massimo.
     */
    std::pair<packVector, packVector> tempPairVector;
    tempPairVector.first.clear();
    tempPairVector.second.clear();
    tempPairVector.second = inPacksToNest;
    do
    {
        /*
         *   Add pallet vector reference to save reference.
         */
        Pallet* newPallet = new Pallet(palletDims);
        
        outPalletVector->push_back(*newPallet);
        /*
         *   Execute a sortInput and reorder the packs.
         */
        tempPairVector = sortInput(tempPairVector.second, *newPallet);
        /*
         *   Define an operation object and pass new parameters to it.
         */
        packVector toNest, notNested;
        toNest = tempPairVector.first;
        /*
         *   Move un-Nested Packs to the second part of the pair to sortInput them in the next phase.
         */
    } while (tempPairVector.second.size());

#pragma endregion

// Gest out in the referenced Pack vector the unNested Packs
    *outUnNestablePacks = tempPairVector.second;
}