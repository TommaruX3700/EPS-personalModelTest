#include <iostream> 
#include <string>
#include <vector>

#include "../entities/physical/Pack.hpp"

#include "../../extLibs/nlohmannJSON/json.hpp"

//output as json object
nlohmann::json convertToJson(std::string inputPath);
std::vector<Pack*> getInputPacks(nlohmann::json inputJson);

