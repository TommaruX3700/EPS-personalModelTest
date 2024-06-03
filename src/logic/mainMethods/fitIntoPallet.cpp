#include "../../../headers/logic/MainMethods/fitIntoPallet.hpp"

int fitIntoPallet(Pack* input_pack, Pallet* input_pallet)
{
    /*
     * TODO:
     * - Pallet needs to have an updated list of each occupated dimension (Use the grid to occupy cells)
     * - Update Pack's dimensions due its current rotation and Pallet current occupied dims
     */

    if (input_pack->getPalletizableFlag())
    {
        //palletizable
        if(!findFittingPlace(input_pack, input_pallet))
        {
            //found a valid position into pack grid: also update pack position's in pallet grid
            input_pallet->addPack(*input_pack);
            return 0;
        }
        else
        {
            //didn't find any valid fit into the pallet area
            return 1;
        }
    }
    else
    {
        if (!findFittingPlace(input_pack, input_pallet))
        {
            //not palletizable
            input_pallet->addPack(*input_pack);
            return 0;
        }
        else
        {
            //didn't find any valid fit into pallet area
            return 1;
        }
    }
}

int findFittingPlace(Pack* input_pack, Pallet* input_pallet)
{
    // check if xyz just fits into pallet dims

        // if it fits thoretically, just try to find a valid place where to put the pack
            // if fits -> add to grid correctly
            // if not fits -> find the correct position 

        // if not fits -> rotate and try again (abort if each rotation is invalid)
    
    //return 0 -> Found position to fit pack on the pallet and changed its position
    //return 1 -> Dindt found any valid position
}
