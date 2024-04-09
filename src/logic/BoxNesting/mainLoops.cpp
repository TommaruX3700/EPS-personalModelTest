#include "../../../headers/logic/BoxNesting/mainLoops.hpp"
#include "../../../headers/logic/OrdinamentoPacchi/quickSort.hpp"

void MainNestLoops(dims palletDims, palletVector *outPalletVector, packVector inPacksToNest, packVector *outUnNestablePacks)
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
        Pallet *newPallet = new Pallet(palletDims);
        outPalletVector->push_back(*newPallet);

        /*
         *   Execute a sortInput and reorder the packs.
         */
        float area = 0;
        float pack_area = 0;
        float pallet_area = newPallet->getPalletDims().num1 * newPallet->getPalletDims().num2;
        quickSort(tempPairVector.second, 0, tempPairVector.second.size() - 1);

        if ((tempPairVector.second[0]->getDims().num1 * tempPairVector.second[0]->getDims().num2) >= pallet_area)
        {
            // do this or skip pack or put in another list
            newPallet->addPack(*tempPairVector.second[0]);
            tempPairVector.second.erase(tempPairVector.second.begin());
        }
        else
        {
            int cursor = 0;
            for (const auto &pack : tempPairVector.second)
            {
                area += (pack->getDims().num1 * pack->getDims().num2);
                if (area <= pallet_area)
                {
                    newPallet->addPack(*pack);
                    tempPairVector.second.erase(tempPairVector.second.begin() + cursor);
                    // remove the pack to the tempPairVector
                    //  probabilemnte il valore di cursors fa casino
                    cursor++;
                }
                else
                    break;
            }
        }
        /*
         *   Move un-Nested Packs to the second part of the pair to sortInput them in the next phase.
         */
    } while (tempPairVector.second.size());
}