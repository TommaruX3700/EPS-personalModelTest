#include "../../../headers/entities/geometry/Domain.hpp"

Domain::Domain(packVector* packsInsidePallet, Pack* incomingPack)
{   
    /*
     *   TODO:
     *       Use here locals this->totalDomain, this->optimization_obj: they will be always stored in the class.
     */
    this->domainComponents.clear();
    PackDomain* tempRoot;
    for (Pack* rootPack : *packsInsidePallet)
    {
        std::unique_ptr<PackDomain> tempRoot(new PackDomain(rootPack, incomingPack));
        this->domainComponents.push_back(std::move(*tempRoot));
    }
}

Domain::~Domain()
{
    this->domainComponents.clear();
}

bool Domain :: checkSpace(Pack* packToCheck)
{
    /*
     *   Simple check if within every single packs' domain.
     *   Consider furtther implementations or optimizations only if needed.
     */
    for(auto domain : domainComponents)
    {
        if(!domain.isInDomain(packToCheck))
            return false;
    }
    return true;
}

ThreeNum_set<int> Domain :: getValidPlacingPoint(Pack* packToInsert)
{
    //get first available coordinate to place the pack, respecting domain condition
    // - lascio spazio qui ad eventuali e future implementazioni per rendere il tutto
    //  *          più specifico.
}
