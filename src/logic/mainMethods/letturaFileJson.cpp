#include "../../../headers/logic/letturaFileJson.hpp"

//implementation here

nlohmann::json convertToJson(std::string inputString)
{
    nlohmann::json outputJson;
    outputJson = nlohmann::json::parse(inputString);
    return outputJson;
}

std::vector<Pack*> getInputPacks(std::string inputString)
{
    nlohmann::json inputJson;
    std::vector<Pack*> outputVector;
    convertToJson(inputString);
    //convert json to pack vector for each object
    return outputVector;
}