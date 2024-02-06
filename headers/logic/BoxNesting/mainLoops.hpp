#include <stack>
#include <set>
#include <thread>
#include <iostream>
#include <vector>

#include "BoxNesting.hpp"
#include "../../entities/physical/Pack.hpp"
#include "../../entities/physical/Pallet.hpp"
//Add include to Federico sorting

typedef std::set<Pallet> palletSet;
typedef std::vector<Pack*> packVector;
typedef Geometry::ThreeNum_set<int> dims;
typedef std::pair<packVector, packVector> pairPackVector;

//STACK: (FILO logic, O(1) time complexity in all operations, refers easily to elements, not useless characterisics)
std::stack<std::thread> operatingThreads;

//maybe chage this with a hash table (unordered_set), using as hash (key) the thread pointers 
palletSet outputNestedPallets;

//Nesting loops
palletSet MainNestLoops(dims palletDims, palletSet &outPalletSet, pairPackVector &packs);

