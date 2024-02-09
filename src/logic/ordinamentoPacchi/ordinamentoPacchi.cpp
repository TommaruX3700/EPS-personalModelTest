#include "../../../headers/logic/ordinamentoPacchi.hpp"
#include "../../../headers/logic/quickSort.hpp"

// NB: consider to make those "external" varibles in .hpp and use here.
// If you have global variables that need to be shared across multiple files, declare them as extern in header files and define them in a single .cpp file.

output isPalletizable(packVector inputVector)
{
    output output;

    // output.first -> pallettizable
    // output.second -> non-pallettizable

    for(const auto& pack : inputVector){
        if (pack->getPalletizableFlag()){
            output.first.push_back(pack);
        } else {
            output.second.push_back(pack);
        }
    }

    return output;
}

output sortInput(packVector inputVector, Pallet pallet)
{
    output output;

    // output.first -> packable
    // output.second -> not packable (packs that don't fit)

    float area = 0;

    quickSort(inputVector, 0, inputVector.size()-1);

    for(const auto& pack : inputVector){
            area+=(pack->getDims().X*pack->getDims().Y);
            if (area <= (pallet.getPalletDims().X*pallet.getPalletDims().Y)){
                output.first.push_back(pack);
            } else {
                output.second.push_back(pack);
            }
    }

    return output;
}