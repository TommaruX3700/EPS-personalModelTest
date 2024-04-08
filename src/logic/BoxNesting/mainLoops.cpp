#include "../../../headers/logic/BoxNesting/mainLoops.hpp"
#include "../../../headers/logic/OrdinamentoPacchi/quickSort.hpp"


void MainNestLoops(dims palletDims, palletVector* outPalletVector, packVector inPacksToNest, packVector* outUnNestablePacks)
{
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
        output output;
        float area = 0;
        quickSort(tempPairVector.second, 0, tempPairVector.second.size()-1);

        if ((tempPairVector.second[0]->getDims().num1*tempPairVector.second[0]->getDims().num2) >= (newPallet->getPalletDims().num1*newPallet->getPalletDims().num2))
        {
            
        } 
        else 
        {
            for(const auto& pack : tempPairVector.second){
                area+=(pack->getDims().num1*pack->getDims().num2);
                if (area <= (newPallet->getPalletDims().num1*newPallet->getPalletDims().num2))
                    outPalletVector->push_back(pack);
                else
                    output.second.push_back(pack);
            }
        }

        /*
         *   Define an operation object and pass new parameters to it.
         */
        packVector toNest, notNested;
        toNest = tempPairVector.first;

        /*
         *   Move un-Nested Packs to the second part of the pair to sortInput them in the next phase.
         */
    } while (tempPairVector.second.size());

// Gest out in the referenced Pack vector the unNested Packs
    *outUnNestablePacks = tempPairVector.second;
}