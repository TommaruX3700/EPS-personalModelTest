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
    *   Pack vector for scarted packs
    */
    packVector notNestedPacks;
    /*
    *   Convert Vector to Stack, to achive better complexity and operations
    */
    std::stack<Pack*> inputStack;
    for (auto lastPack = this->inputPacks.rbegin(); lastPack != inputPacks.rend(); ++lastPack) {
        inputStack.push(*lastPack);
    }
    /*
    *   Nesting loop, cycling until there are any elements left inside inputStack
    */
    while (!inputStack.empty())
    {   
        /*
        *   Incoming pack
        */
        Pack nextPack;
        try
        {
            /*
            *   Using only "top" pack grants me freedom on iterating a single Pack element again, usually after a domain optimization
            */
            nextPack = *inputStack.top();   

            if (workingPallet.getPackCount() == 0)
            {
                /*
                *   First pack arrived: place at the center.
                */
                placeAtCenter(nextPack);
                inputStack.pop();
            }
            else
            {
                /*
                *   New pack adding to the ROOT config: perform operations
                */
                if (findDomain(workingPallet.getPackVector(), nextPack))
                {
                    /*
                    *   Domain found: proceed to placement
                    */
                    if (startingPlacement())
                    {
                        /*
                        *   Pack placed successfully and new ROOT configuration generated: now moving to nesting
                        */ 
                        if (nestingForMin())
                        {
                            /*
                            *   Minimum exists: all packs placed successfully
                            */ 
                            inputStack.pop();
                        }
                        else
                        {
                            // TODO: il minimo NON esiste, modifica ottimizzazione e ricomincia
                        }
                    }
                    else
                    {
                        /*
                        *   I add not nestable pack to scarted-output vector
                        */
                        notNestedPacks.push_back(&nextPack);
                        inputStack.pop();
                    }
                }
                else
                {
                    /*
                    *   I add not nestable pack to scarted-output vector
                    */                    
                    notNestedPacks.push_back(&nextPack);
                    inputStack.pop();
                }
                
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << "Pacco non piazzabile:" << e.what() << '\n';
            this->outputNotNestedPacks->push_back(&nextPack);
        }
    }

    /*
    *   DUBBIO: ritornare indirizzi di oggetti pacco nei vettori di output, non fa in modo che questi puntatori a oggetti pacco puntino
    *           ancora agli oggetti dichiarati qui dentro, che se cancellati vanno a ritornare risultati nulli?
    */

    /*
    *   Copy the nested configuration in the output referenced pallet location.
    */
    *outputPalletConfig = workingPallet;
    /*
    *   Copy unnestable packs to output referenced pack vector.
    */
    *outputNotNestedPacks = notNestedPacks;
}

void BoxNesting :: placeAtCenter(Pack input)
{
    //TODO
}

bool BoxNesting :: findDomain(packVector packsInsidePallet, Pack incomingPack)
{
    //TODO
    /*
    *   Use here locals this->totalDomain, this->optimization_obj: they will be always stored in the class.
    */
    return true;
}

bool BoxNesting :: startingPlacement() 
{
    //TODO
    return true;
}

bool BoxNesting :: nestingForMin()
{
    //TODO
    return true;
}

