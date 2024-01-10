#include "../../../headers/logic/sceltaPacchiNesting.hpp"

// NB: consider to make those "external" varibles in .hpp and use here.
// If you have global variables that need to be shared across multiple files, declare them as extern in header files and define them in a single .cpp file.
std::vector<Pack*> packsToChoose;   //INPUT
std::vector<Pack*> choosenPacks;    //OUTPUT_1: 
std::vector<Pack*> discardedPacks;  //OUTPUT_2: reuse this packs in the next loops