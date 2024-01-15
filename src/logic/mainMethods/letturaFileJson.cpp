#include "../../../headers/logic/letturaFileJson.hpp"

//implementation here

nlohmann::json convertToJson(std::string inputPath)
{
    nlohmann::json output;
    //convert string to Json
    return output;
}

std::vector<Pack*> getInputPacks (std::string inputPath)
{
    nlohmann::json inputJson;
    std::vector<Pack*> output;
    convertToJson(inputPath);
    //convert json to pack vector for each object
    return output;
}