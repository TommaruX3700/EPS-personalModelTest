#include <stack>
#include <set>
#include <thread>
#include <iostream>
#include <vector>
#include <functional>

#include "BoxNesting.hpp"
#include "../../entities/physical/Pack.hpp"
#include "../../entities/physical/Pallet.hpp"
#include "../OrdinamentoPacchi/ordinamentoPacchi.hpp"

typedef std::vector<Pallet> palletVector;
typedef std::vector<Pack*> packVector;
typedef Geometry::ThreeNum_set<int> dims;
typedef std::pair<packVector, packVector> pairPackVector;

//Nesting loops
void MainNestLoops(dims palletDims, palletVector* outPalletVector, packVector inPacksToNest, packVector* outUnNestablePacks);

