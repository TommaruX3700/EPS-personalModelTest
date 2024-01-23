#include "../../../headers/logic/letturaFileJson.hpp"

ReadJson::ReadJson(std::string stringFileContent)
{
    nlohmann::json inputJson = convertStringToJson(stringFileContent.c_str());
    retrivePacksInfos(inputJson);
}

nlohmann::json ReadJson::convertStringToJson(std::string inputString)
{
    nlohmann::json outputJson;
    outputJson = nlohmann::json::parse(inputString);
    return outputJson;
}

void ReadJson::retrivePacksInfos(nlohmann::json inputJson)
{
    //Dichiaro unordered_map in cui copiare il json object
    std::unordered_map<std::string, nlohmann::json> mapPack;
    mapPack = inputJson;

    //TODO: fare un sistema di conteggio pacchi più solido
    int packCount = mapPack.size() - 2;

    std::string userSettings = mapPack["user_settings"].dump(); //instead of this, get values directly from json object 

    Geometry::ThreeNum_set<int> tempDims;
    Geometry::ThreeNum_set<int> tempCoords;
    int tempCollo;
    float tempWeight;
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
                    Pack* newPk;
                    tempDims.X = tempJsonPack["BASE_MAGGIORE"];
                    tempDims.Y = tempJsonPack["BASE_MINORE"];
                    tempDims.Z = tempJsonPack["ALTEZZA"];
                    tempCoords.X = 0;
                    tempCoords.Y = 0;
                    tempCoords.Z = 0;
                    tempCollo = tempJsonPack["NUMERO_COLLO"];
                    std::string weight = tempJsonPack["PESO_NETTO"];
                    tempWeight = std::stof(weight);

                    if (tempJsonPack["FLAG_RUOTABILE"] == "N")
                    {
                        newPk = new Pack(tempDims, tempCoords, tempWeight, tempCollo, false);
                    }
                    else
                    {
                        newPk = new Pack(tempDims, tempCoords, tempWeight, tempCollo, true);
                    }

                    this->outputPackVector.push_back(newPk);
                }
                catch(std::exception& e)
                {
                    std::cout << "Faulted Pack (N_Collo): " << tempJsonPack["NUMERO_COLLO"] << std::endl;
                }                
            }            
        }   
        else
        {
            //get pallet info here instead
            tempJsonPack = nlohmann::json::parse(mapPack[line.first].dump());
            this->outputPalletMaxs.X = tempJsonPack["Lenght"];
            this->outputPalletMaxs.Y = tempJsonPack["Width"];
            this->outputPalletMaxs.Z = tempJsonPack["Height"];
        }
    }
}

bool ReadJson::checkPackInfos(nlohmann::json input)
{
    // Check data and dimensions before operations
        if (input["BASE_MAGGIORE"] == 0 || input["BASE_MINORE"] == 0 || input["ALTEZZA"] == 0)
        {
            std::cout << "Missing Dims, ignore Pack\n";
            return false;   
        }
        if (input["NUMERO_COLLO"] == 0 || input["NUMERO_COLLO"] == NULL)
        {
            std::cout << "Missing Numero di Collo, ignore Pack\n";
            return false;  
        }
        if (input["PESO_NETTO"] == "" || input["PESO_NETTO"] == NULL || input["PESO_NETTO"] == "0")
        {
            std::cout << "Missing Peso Netto, ignore Pack\n";
            return false;
        }
    return true;
}

const std::vector<Pack*> ReadJson::getPackVector()
{
    return this->outputPackVector;
}

const Geometry::ThreeNum_set<int> ReadJson::getPalletInfos()
{
    return this->outputPalletMaxs;
}