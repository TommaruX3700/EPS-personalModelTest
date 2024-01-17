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
            // Remake all this method because it ignores all the other operations made in construction (eg:calcolo volume)
            tempJsonPack = nlohmann::json::parse(mapPack[line.first].dump());
            if (checkPackInfos(tempJsonPack))
            {
                try //remove this once done
                {
                    Pack newPack;
                    tempSet.X = tempJsonPack["BASE_MAGGIORE"];
                    tempSet.Y = tempJsonPack["BASE_MINORE"];
                    tempSet.Z = tempJsonPack["ALTEZZA"];
                    newPack.setDims(tempSet);
                    tempSet.X = 0;
                    tempSet.Y = 0;
                    tempSet.Z = 0;
                    newPack.setCenterCoords(tempSet);
                    newPack.setPackID(tempJsonPack["NUMERO_COLLO"]);
                    if (tempJsonPack["FLAG_RUOTABILE"] == "N")
                    {
                        newPack.setRotatableFlag(false);
                    }
                    else
                    {
                        newPack.setRotatableFlag(true);
                    }
                    std::string weight = tempJsonPack["PESO_NETTO"];
                    newPack.setWeight(std::stof(weight));
                    outputVector.push_back(&newPack);
                }
                catch(const std::exception& e)
                {
                    std::cout << "Faulted Pack: " << tempJsonPack["NUMERO_COLLO"] << std::endl;
                }                
            }            
        }   
        else
        {
            //get pallet info here instead
        }
    }
    //convert json to pack vector for each object
    return outputVector;
}

bool checkPackInfos(nlohmann::json input)
{
    // Check data and dimensions before operations
        if (input["BASE_MAGGIORE"] == 0 || input["BASE_MINORE"] == 0 || input["ALTEZZA"] == 0)
        {
            std::cout << "Missing Dims, ignore Pack";
            return false;  
        }
        if (input["NUMERO_COLLO"] == 0 || input["NUMERO_COLLO"] == NULL)
        {
            std::cout << "Missing Numero di Collo, ignore Pack";
            return false;  
        }
        if (input["PESO_NETTO"] == "" || input["PESO_NETTO"] == NULL || input["PESO_NETTO"] == "0")
        {
            std::cout << "Missing Peso Netto, ignore Pack";
            return false;
        }
    return true;
}

// Pallet getInputPalletInfos(nlohmann::json inputJson)
// {
//     //get pallet infos and general settings by json "user settings"
//     return getPalletByJson(inputJson);
// }

// //"PRIVATE" methods

// Pack getPackByJson(nlohmann::json inputJson)
// {
//     //get info on pack by parsed json
//     //create Pack object and return it
// }

// Pallet getPalletByJson(nlohmann::json inputJson)
// {
//     //make a file to read general pallet informations

// }