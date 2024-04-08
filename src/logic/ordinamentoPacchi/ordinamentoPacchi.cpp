#include "../../../headers/logic/OrdinamentoPacchi/ordinamentoPacchi.hpp"
#include "../../../headers/logic/OrdinamentoPacchi/quickSort.hpp"

/*
 *   Gives as output a pair of Pack* vectors, based on their flag:
 *   > output.first = palletizable packs;
 *   > output.second = nonPalletizable packs.
 */
output isPalletizable(packVector inputVector)
{
    output output;
    for(const auto& pack : inputVector){
        if (pack->getPalletizableFlag())
            output.first.push_back(pack);
        else
            output.second.push_back(pack);        
    }
    return output;
}

/*
 *   Gives as output a pair of Pack* vectors, based upon their dimensions and pallet area (if they will fit or not, matematically)
 *   > output.first =  nestable packs stack;
 *   > output.second = packs to re-iterate to find a nestable stack;
 */
output sortInput(packVector inputVector, Pallet pallet)
{
    /*
     * TODO:
     *  - mettere in modo che venga sortato anche in base al peso massimo
     *  - se il primo pacco è più grande dell'area, perde di senso e area sarà sempre più grande: devo includere un vettore di output per i pacchi non palletizzabili o con area più grande del pallet stesso.
     */
    output output;
    float area = 0;
    quickSort(inputVector, 0, inputVector.size()-1);
    
    for(const auto& pack : inputVector){
        area+=(pack->getDims().num1*pack->getDims().num2);
        if (area <= (pallet.getPalletDims().num1*pallet.getPalletDims().num2))
            output.first.push_back(pack);
        else
            output.second.push_back(pack);
    }
    return output;
}