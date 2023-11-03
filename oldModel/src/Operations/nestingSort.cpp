// functions for the nestingSort

#include "..\..\headers\Operations\nestingSort.h"

int sortBeforeNesting(std::vector<Pack> *input, std::vector<Pack> *output, std::vector<Pack> *notNestable, double *palletArea)
{
    static double tempAreaPacco = 0;
    static int index = 0;
    static Pack *packToCheck = new Pack();

    if (index < input->size())
    {
        *packToCheck = input->at(index);
        tempAreaPacco = packToCheck->get_Dims()->x * packToCheck->get_Dims()->y;
        if (*palletArea - tempAreaPacco)
        {
            output->push_back(*packToCheck);
            *palletArea -= tempAreaPacco;
            index++;
        }
        else
        {
            notNestable->push_back(*packToCheck);
            index++;
        }
        return 1; // I still have packs to controll
    }
    delete packToCheck;
    index = 0;
    return 0; // no more packs to controll
}
