#include "../../../headers/logic/MainMethods/fitIntoPallet.hpp"

int fitIntoPallet(Pack* input_pack, Pallet* input_pallet)
{
    /*
     * TODO:
     * - Pack needs to be controlled for every rotation and each dimension
     * - Pallet needs to have an updated list of each occupated dimension (subtract it from the main source, making a copy of it in the pallet itself)
     * - Update Pack's dimensions due its current rotation and Pallet current occupied dims
     * 
     * - If pack is not palletizable, just check if it fits in PALLET_X, PALLET_Y and PALLET_Z, if not rotate or signal as NOT FITTING
     * 
     * - If pack is palletizable, check if it fits in PALLET_X, PALLET_Y and PALLET_Z, if not rotate and subcract pack dims from pallet available area
     * - if possible, consider GRID operations(write 'em on Pallet class itself) (such as, get position to insert, insert, etc..)
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
        //not palletizable
        input_pallet->addPack(*input_pack);
        return 0;
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
