#include <iostream>
#include <vector>

#include "headers\Geometry\GridSpace.h"

#include "headers\3D_Objects\Pack.h"
#include "headers\3D_Objects\Pallet.h"
#include "headers\3D_Objects\PalletGroup.h"

#include "headers\Operations\nestingSort.h"

#define DEBUG 1   //definisce se verrà emesso un output di debug     1:ON 0:OFF

GridSpace grid = GridSpace(10, 10, 10);

std::vector<Pack> sortedInput; // input, pacchi ordinati dal json
std::vector<Pack> packsToNest; // pacchi da Nestare

std::vector<Pack> outputNOTNested; // pacchi non Nestabili
std::vector<Pack> output;          // nested output

Pallet pallet;

int main()
{
    // TODO: add application loop + error codes
    try
    {
        // nestingSort
        double areaPallet = pallet.get_Dims().x * pallet.get_Dims().y;
        while (sortBeforeNesting(&sortedInput, &packsToNest, &outputNOTNested, &areaPallet))
            ;
    }
    catch (const std::exception &e)
    {
        std::cerr << "main :: nestingSort :: exception caught: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "main :: nestingSort :: unknown exception caught, exiting..." << std::endl;
        return 0;
    }
    std::cout << "main :: All operations done!" << std::endl;
    return 0;

    try
    {
        //
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}