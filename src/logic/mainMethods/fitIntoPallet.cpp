#include "../../../headers/logic/MainMethods/fitIntoPallet.hpp"

int fitIntoPallet(Pack* input_pack, Pallet* input_pallet)
{
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
    //REMEMBER:
    // - Pallet needs to have an updated list of each occupated dimension (Use the grid to occupy cells)
    // - Update Pack's dimensions due its current rotation and Pallet current occupied dims

    int rotation = 0;
    do
    {
        // will it ever fit?
        if(!input_pallet->doesItFit(input_pack))
        {
            // it will fit: now find a valid place where to place the pack on the GRID
            if (!input_pallet->findValidPlace(input_pack))
            {
                // found -> add to grid correctly and update pack coords
                return 0; 
            }
            // if not found -> rotate and try again (maybe rotate from 0, dont know for know dont do anything)
        }
        else
        {
            // if it not fits -> rotate and try again (abort if each rotation is invalid)
            input_pack->changeObjectOrientation(rotation);
            rotation++;        
        }
    } while (rotation != 6);

    return 1; // Dind't found any valid position
}
