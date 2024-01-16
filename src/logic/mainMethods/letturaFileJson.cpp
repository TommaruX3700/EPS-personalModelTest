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

void rmvBackspace(std::string &inputString)
{
    std::string toRemove = "\\";
    std::string tempOutput = "";

    for (char character : inputString)
    {
        if (character != '\\' && character != '\r' && character != '\n' && character != '\r\n')
        {
            tempOutput += character;
        }
    }
    
    inputString = tempOutput;

    //modify the main inputString by working with pointers instead of return strings
    
    //std::string::find() --> return the position of the first occurrency of the substring provided as argument


    //TODO: 
    //1. find a way to get rid of all the "\" characters
    //2. why there is an excessive "}" at the EOF?

    //find a way to remove backslash char in currentLine
    //find '\' iterator
    //currentLine.find("'\'");
    //currentLine = std::regex_replace(currentLine, std::regex("\\"), "");
    // currentLine.erase(std::remove(currentLine.begin(), currentLine.end(), toRemove), currentLine.end());
} 