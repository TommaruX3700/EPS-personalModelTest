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

    Geometry::ThreeNum_set<int> tempSet;
    nlohmann::json tempJsonPack;

    for (auto line : mapPack)
    {
        if (line != "user_settings")
        {
            Pack tempPack;
            //Remake all this method because it ignores all the other operations made in construction (eg:calcolo volume)
            tempJsonPack = nlohmann::json::parse(mapPack[line.first]);
            tempSet.X = tempJsonPack["BASE_MAGGIORE"];
            tempSet.Y = tempJsonPack["BASE_MINORE"];
            tempSet.Z = tempJsonPack["ALTEZZA"];
            tempPack.setDims(tempSet);
            tempSet.X = 0;
            tempSet.Y = 0;
            tempSet.Z = 0;
            tempPack.setCenterCoords(tempSet);
            tempPack.setPackID(tempJsonPack["NUMERO_COLLO"]);
            if (tempJsonPack["FLAG_RUOTABILE"] == "N")
            {
                tempPack.setRotatableFlag(false);
            }
            else
            {
                tempPack.setRotatableFlag(true);
            }
            tempPack.setWeight(tempJsonPack["PESO_NETTO"]);
            outputVector.push_back(tempPack);
        }   
        else
        {
            //get pallet info here instead
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