#include "../../../headers/logic/BoxNesting/mainLoops.hpp"
#include "../../../headers/logic/OrdinamentoPacchi/quickSort.hpp"

void MainNestLoops(dims palletDims, palletVector *outPalletVector, packVector inPacksToNest, packVector *outUnNestablePacks)
{
    /*
     *   Questo loop ad ogni ciclo ogni pacco contenuto nel buffer dei pacchi scartati.
     *   > packs.first -> pacchi su cui lanciare il thread di nesting
     *   > packs.second -> pacchi "scartati" dal nesting e che necessitano di tornare sotto elaborazione fino ad un tot massimo.
     */
    packVector tempPairVector;
    tempPairVector.clear();
    tempPairVector = inPacksToNest;
    do
    {
        /*
         *   Add pallet vector reference to save reference.
         */
        Pallet* newPallet = new Pallet(palletDims);
        outPalletVector->push_back(newPallet);

        /*
         *   Execute a sortInput and reorder the packs.
         */
        float area = 0;
        float pack_area = 0;
        float pallet_area = newPallet->getPalletDims().num1 * newPallet.getPalletDims().num2;
        quickSort(tempPairVector, 0, tempPairVector.size() - 1);

        if ((tempPairVector[0]->getDims().num1 * tempPairVector[0]->getDims().num2) >= pallet_area)
        {
            // do this or skip pack or put in another list
            newPallet.addPack(*tempPairVector[0]);
            tempPairVector.erase(tempPairVector.begin());
        }
        else
        {
            int cursor = 0;
            auto it = tempPairVector.begin();
            while (it != tempPairVector.end())
            {
                const auto &pack = *it;
                area += (pack->getDims().num1 * pack->getDims().num2);
                if (area <= pallet_area)
                {
                    newPallet.addPack(*pack);
                    it = tempPairVector.erase(it); // Erase and update iterator
                }
                else
                {
                    ++it; // Move to the next element
                    cursor++;
                }
            }
        }
        /*
         *   Move un-Nested Packs to the second part of the pair to sortInput them in the next phase.
         */
    } while (tempPairVector.size());
}