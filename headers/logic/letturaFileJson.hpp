#include <iostream> 
#include <string>
#include <vector>

#include "../entities/physical/Pack.hpp"

#include "../../extLibs/nlohmannJSON/json.hpp"


//Converts string to Json
nlohmann::json convertToJson(std::string inputPath);
//Gives pack vector as output
std::vector<Pack*> getInputPacks(std::string inputString);
//Removes "Backspace" character from a string
void rmvBackspace(std::string* inputString);

