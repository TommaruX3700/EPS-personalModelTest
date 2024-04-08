#include "../../../headers/logic/BoxNesting/mainLoops.hpp"

void MainNestLoops(dims palletDims, palletVector* outPalletVector, packVector inPacksToNest, packVector* outUnNestablePacks)
{
#pragma region "Initial Preparation"
    /*
    *   2 vettori, uno per lanciare i thread di nesting e uno per raccogliere 
    */
    std::pair<packVector, packVector> packs;
    packs.first = inPacksToNest;
    /*
    *   Aggiungo alla fine del mio second vector il first vector ed eseguo un sortInput sul secondo vettore.
    */
    packs.second.insert(std::end(packs.second), std::begin(packs.first), std::end(packs.first));
#pragma endregion

#pragma region "LOOP_1"
    /*
    *   Questo loop ad ogni ciclo ogni pacco contenuto nel buffer dei pacchi scartati.
    *   > packs.first -> pacchi su cui lanciare il thread di nesting
    *   > packs.second -> pacchi "scartati" dal nesting e che necessitano di tornare sotto elaborazione fino ad un tot massimo.
    */
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
        packs = sortInput(packs.second, *newPallet);
        /*
        *   Define an operation object and pass new parameters to it.
        */
        packVector toNest, notNested;
        toNest = packs.first;
        // BoxNesting operations(newPallet, toNest, &notNested);
        /*
        *   Launch thread nesting operations 
        */
        // std::thread newThread(std::bind(&BoxNesting::nesting, &operations));
        //operatingThreads.push(std::move(newThread));
        /*
        *   Move un-Nested Packs to the second part of the pair to sortInput them in the next phase.
        */
        packs.second.insert(packs.second.end(), notNested.begin(), notNested.end());
        /*
        *   Get current time.
        */
        // partialTime = std::chrono::steady_clock::now();
        // loopTimer = partialTime - start;
        // if (loopTimer.count() >= 20)
        //     throw std::invalid_argument("Threads creation loop took up to 20 seconds for execution: check code");
    } while (packs.second.size());

#pragma endregion

#pragma region "LOOP_2"
    // start = std::chrono::steady_clock::now();
    // while (!operatingThreads.empty())
    // {
    //     /*
    //     *   loop that waits threads to join: all the output is collected in the thread-assigned Pallet in LOOP_1
    //     *   TODO: make a better "joinable" condition: this is too stoopid (method already exits in BoxNesting (isFinished()))
    //     */
    //     if (operatingThreads.top().joinable())
    //     {
    //         std::thread joinableThread = std::move(operatingThreads.top());
    //         joinableThread.join();
    //         operatingThreads.pop();
    //     }
    //     partialTime = std::chrono::steady_clock::now();
    //     loopTimer = partialTime - start;
    //     if (loopTimer.count() >= 20)
    //         throw std::invalid_argument("Threads join loop took up to 20 seconds for execution: check code");
    // }

#pragma endregion  

// Gest out in the referenced Pack vector the unNested Packs
    *outUnNestablePacks = packs.second;
}