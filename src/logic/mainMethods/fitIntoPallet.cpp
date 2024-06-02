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
        // check xyz + rotation
        //if fits -> add to grid correctly
        // if not fits, find the correct position 
    }
    else
    {
        //not palletizable
    }
    

    //return 0 -> Pack fitted into pallet (and added it)
    //return 1 -> Pack doents fit into pallet (you should handle it outside this)
}
