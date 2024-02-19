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
            *   LOOP_1:
            *       > Questo loop ad ogni ciclo ogni pacco contenuto nel buffer dei pacchi scartati.
            *       > remainingPacks.first -> pacchi su cui lanciare il thread di nesting
            *       > remainingPacks.second -> pacchi "scartati" dal nesting e che necessitano di tornare sotto elaborazione fino ad un tot massimo.
            */
            packVector notNested;
            Pallet newPallet(palletDims);
            /*
            *   Aggiungo alla fine del mio second vector il first vector ed eseguo un sortInput sul secondo vettore.
            */
            packs.second.insert(std::end(packs.second), std::begin(packs.first), std::end(packs.first));
            /*
            *   Add pallet vector reference to save reference.
            */
            nestedPallets.insert(newPallet);
            /*
            *   Creating new nesting thread operation.
            */
            BoxNesting threadOperation();
            std::thread newThread (&BoxNesting::nesting, &threadOperation, &newPallet, &packs.first, &notNested);
            operatingThreads.push(newThread);
            /*
            *   Move un-Nested Packs to the second part of the pair.
            */
            packs.second.insert(packs.second.end(), notNested.begin(), notNested.end());
            /*
            *   Get current time.
            */
            partialTime = std::chrono::steady_clock::now();
            loopTimer = partialTime - start;
            if (loopTimer.count() >= 20)
                throw std::invalid_argument("Threads creation loop took up to 20 seconds for execution: check code");
        } while (packs.second.size());
#pragma endregion

#pragma region "LOOP_2"
        start = std::chrono::steady_clock::now();
        while (!operatingThreads.empty())
        {
            /*
            *   LOOP_2:
            *       loop that waits threads to join.
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
                throw std::invalid_argument("Threads join loop took up to 20 seconds for execution: check code");
        }
#pragma endregion  
}