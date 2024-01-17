#include <iostream> 
#include <string>
#include <vector>

#include "../entities/physical/Pack.hpp"
#include "../entities/physical/Pallet.hpp"

#include "../../extLibs/nlohmannJSON/json.hpp"

/*
TODO: Convert all of this into a class with this infos
- json object as public json object: retrived on constructor
*/

//Converts string to Json
nlohmann::json convertStringToJson(std::string inputPath);

//Gives pack vector as output
std::vector<Pack*> getInputPacksInfos(nlohmann::json inputJson);

bool checkPackInfos(nlohmann::json input);

// //Gives pallet as Pallet object for infos
// Pallet getInputPalletInfos(nlohmann::json inputJson);

// //Convert jsonObject to Pack
// Pack getPackByJson(nlohmann::json inputJson);

// //get Pallet infos by jsonObject
// Pallet getPalletByJson(nlohmann::json inputJson);

