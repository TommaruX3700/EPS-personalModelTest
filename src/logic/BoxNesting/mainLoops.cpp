#include "../../../headers/logic/BoxNesting/mainLoops.hpp"

palletSet MainNestLoops(dims palletDims, palletSet &nestedPallets, pairPackVector &packs)
{
    auto start = std::chrono::steady_clock::now();
    auto partialTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> loopTimer;

    #pragma region "LOOP_1"
        do
        {
            /*
            *   LOOP_1 (do-while) (RESUME INTO A FUNCTION) 
            *       > Questo loop ad ogni ciclo ogni pacco contenuto nel buffer dei pacchi scartati.
            *       > remainingPacks.first -> pacchi su cui lanciare il thread di nesting
            *       > remainingPacks.second -> pacchi "scartati" dal nesting e che necessitano di tornare sotto elaborazione fino ad un tot massimo.
            */
            // remainingPacks = sortInput(remainingPacks.second);
            packVector notNested;
            Pallet newPallet(palletDims);
            //add pallet vector reference to save reference
            nestedPallets.insert(newPallet);
            BoxNesting threadOperation();
            std::thread newThread (&BoxNesting::nesting, &threadOperation, &newPallet, &packs.first, &notNested);
            operatingThreads.push(newThread);
            //TODO:this wont work because it notNested may be compiled or not: use this informations in the join loop
            packs.second.insert(packs.second.end(), notNested.begin(), notNested.end());
            partialTime = std::chrono::steady_clock::now();
            loopTimer = partialTime - start;
            if (loopTimer.count() >= 20)
            {
                throw std::invalid_argument("Threads creation loop took up to 20 seconds for execution: check code");
            }
        } while (packs.second.size());
    #pragma endregion

    #pragma region "LOOP_2"
        start = std::chrono::steady_clock::now();
        while (!operatingThreads.empty())
        {
            /*
            *   LOOP_2 (RESUME INTO A FUNCTION)
            *   7.  take all the FIRST vector objects, add them into a pallet and add the pallet to the Pallet Group
            *   8.  take all the SECOND vector objects and add them to an another vector to recicle (unNestedPacks).
            *   9.  With this new vector, repeat the LOOP_1 with the same operations, for a max of lets say, 5 times (or timeout)
            * 
            *   Make a loop that waits threads to join.
            *   make it not to enlapse too much time
            *   NB: note that execution will be blocked until each thread will join correctly.
            */

            if (operatingThreads.top().joinable())
            {
                std::thread& joinableThread = const_cast<std::thread&>(operatingThreads.top());
                joinableThread.join();
                operatingThreads.pop();
            }
            partialTime = std::chrono::steady_clock::now();
            loopTimer = partialTime - start;

            if (loopTimer.count() >= 20)
            {
                throw std::invalid_argument("Threads join loop took up to 20 seconds for execution: check code");
            }
        }
    #pragma endregion  
}