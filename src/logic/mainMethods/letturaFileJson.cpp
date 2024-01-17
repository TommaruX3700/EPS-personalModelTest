#include "../../../headers/logic/letturaFileJson.hpp"

nlohmann::json convertStringToJson(std::string inputString)
{
    nlohmann::json outputJson;
    outputJson = nlohmann::json::parse(inputString);
    return outputJson;
}

std::vector<Pack*> getInputPacksInfos(nlohmann::json inputJson)
{
    std::vector<Pack*> outputVector;

    //Dichiaro unordered_map in cui copiare il json object
    std::unordered_map<std::string, nlohmann::json> mapPack;
    mapPack = inputJson;

    //TODO: fare un sistema di conteggio pacchi più solido
    int packCount = mapPack.size() - 2;
    std::string userSettings = mapPack["user_settings"].dump(); //instead of this, get values directly from json object 

    Pack tempPack();

    for (auto pack : mapPack)
    {
        if (pack != "user_settings")
        {
            std::cout << mapPack[pack.first] << "\n";    
        }   
    }
    //convert json to pack vector for each object
    
    return outputVector;
}

Pallet getInputPalletInfos(nlohmann::json inputJson)
{
    //get pallet infos and general settings by json "user settings"
    return getPalletByJson(inputJson);
}

//"PRIVATE" methods

Pack getPackByJson(nlohmann::json inputJson)
{
    //get info on pack by parsed json
    //create Pack object and return it
}

Pallet getPalletByJson(nlohmann::json inputJson)
{
    //make a file to read general pallet informations

}