#include "../../../headers/logic/letturaFileJson.hpp"

nlohmann::json convertStringToJson(std::string inputString)
{
    nlohmann::json outputJson;
    outputJson = nlohmann::json::parse(inputString);
    return outputJson;
}

std::vector<Pack*> getInputPacksAndPalletInfos(nlohmann::json inputJson)
{
    nlohmann::json inputJson;
    std::vector<Pack*> outputVector;
    //convert json to pack vector for each object
    
    return outputVector;
}

Pallet getInputPalletInfo(nlohmann::json inputJson)
{
    //get pallet infos and general settings by json "user settings"

}

Pack getPackByJson(nlohmann::json inputJson)
{
    //get info on pack by parsed json
    //create Pack object and return it
}

Pallet getPalletByJson(nlohmann::json inputJson)
{

}

//make a file to read general pallet informations
