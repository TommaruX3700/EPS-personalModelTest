#include <iostream> 
#include <string>
#include <vector>

#include "../entities/physical/Pack.hpp"
#include "../entities/physical/Pallet.hpp"

#include "../../extLibs/nlohmannJSON/json.hpp"

//Converts string to Json
nlohmann::json convertStringToJson(std::string inputPath);

//Gives pack vector as output
std::vector<Pack*> getInputPacksInfos(nlohmann::json inputJson);

//Gives pallet as Pallet object for infos
Pallet getInputPalletInfo(nlohmann::json inputJson);

//Convert jsonObject to Pack
Pack getPackByJson(nlohmann::json inputJson);

//get Pallet infos by jsonObject
Pallet getPalletByJson(nlohmann::json inputJson);

