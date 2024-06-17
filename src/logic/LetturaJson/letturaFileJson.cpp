#include "../../../headers/logic/LetturaJson/letturaFileJson.hpp"

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
    bool undefined_pack_detected = false;
    //Dichiaro unordered_map in cui copiare il json object
    std::map<std::string, nlohmann::json> mapPack;
    mapPack = inputJson;

    Geometry::ThreeNum_set<int> tempDims;
    Geometry::ThreeNum_set<int> tempCoords;
    int tempCollo;
    float tempWeight;
    bool tempRotatableFlag, tempPalletizableFlag, tempSovrapponibileFlag;
    nlohmann::json tempJsonPack;

    for (auto line : mapPack)
    {
        if (line.first != "user_settings")
        {
            // Remake all this method because it ignores all the other operations made in construction (eg:calcolo volume)
            tempJsonPack = nlohmann::json::parse(mapPack[line.first].dump());
            if (checkPackInfos(tempJsonPack))
            {
                Pack* newPk;
                try //remove this once done
                {
                    tempDims.num1 = tempJsonPack["BASE_MAGGIORE"];
                    tempDims.num2 = tempJsonPack["BASE_MINORE"];
                    tempDims.num3 = tempJsonPack["ALTEZZA"];
                    tempCoords.num1 = 0;
                    tempCoords.num2 = 0;
                    tempCoords.num3 = 0;
                    tempCollo = tempJsonPack["NUMERO_COLLO"];
                    std::string weight = tempJsonPack["PESO_NETTO"];
                    tempWeight = std::stof(weight);

                    if (tempJsonPack["FLAG_RUOTABILE"] == "N")
                    {
                        tempRotatableFlag = false;
                    }
                    else
                    {
                        tempRotatableFlag = true;
                    }

                    if (tempJsonPack["FLAG_PALETTIZZABILE"] == "N")
                    {
                        tempPalletizableFlag = false;
                    }
                    else
                    {
                        tempPalletizableFlag = true;
                    }

                    if (tempJsonPack["FLAG_SOVRAPPONIBILE"] == "N")
                        tempSovrapponibileFlag = false;
                    else
                        tempSovrapponibileFlag = true;
                    

                    newPk = new Pack(tempDims, tempCoords, tempWeight, tempCollo, tempRotatableFlag, tempPalletizableFlag);

                    this->outputPackVector.push_back(newPk);
                }
                catch(std::exception& e)
                {
                    std::cout << "Faulted Pack (N_Collo): " << tempJsonPack["NUMERO_COLLO"] << "\n-------------------------------------------------\n";
                    newPk = new Pack(tempDims, tempCoords, tempWeight, tempCollo, tempRotatableFlag, tempPalletizableFlag);
                    this->ingoredPacks.push_back(newPk);
                }                
            }
            else
            {
                if (tempJsonPack["NUMERO_COLLO"] == 0 || tempJsonPack["NUMERO_COLLO"] == NULL)
                {
                    std::cout << "PACCO SENZA IDENTIFICATIVO COLLO RILEVATO, TERMINA APPLICATIVO \n-------------------------------------------------\n";
                    undefined_pack_detected = true;
                }
            }       
        }   
        else
        {
            //get pallet info here instead
            try
            {      
                tempJsonPack = nlohmann::json::parse(mapPack[line.first].dump());
                this->outputPalletMaxs.num1 = tempJsonPack["Lenght"];
                this->outputPalletMaxs.num2 = tempJsonPack["Width"];
                this->outputPalletMaxs.num3 = tempJsonPack["Height"];
                this->maxPalletWeight = tempJsonPack["Max Weight"];
            }
            catch(const std::exception& e)
            {
                this->outputPalletMaxs = {};
            }
        }
    }
    if(undefined_pack_detected == true)
    {
        this->outputPackVector.clear();
    }
}

bool ReadJson::checkPackInfos(nlohmann::json input)
{
    // Check data and dimensions before operations
    Pack* discardedPack;
        if (input["NUMERO_COLLO"] == 0 || input["NUMERO_COLLO"] == NULL)
        {
            std::cout << "PACCO SENZA IDENTIFICATIVO COLLO RILEVATO, TERMINA APPLICATIVO \n-------------------------------------------------\n";
            ingoredPacks.push_back(discardedPack);            
            return false;  
        }

        if (input["BASE_MAGGIORE"] == 0 || input["BASE_MINORE"] == 0 || input["ALTEZZA"] == 0 || input["BASE_MAGGIORE"] == NULL || input["BASE_MINORE"] == NULL || input["ALTEZZA"] == NULL)
        {
            std::cout << "Missing Dims, Pack ignored (N_Collo: " << input["NUMERO_COLLO"] << ")\n-------------------------------------------------\n";
            discardedPack = new Pack();
            discardedPack->setPackID(input["NUMERO_COLLO"]);
            ingoredPacks.push_back(discardedPack);            
            return false;   
        }
        
        if (input["PESO_NETTO"] == "" || input["PESO_NETTO"] == NULL || input["PESO_NETTO"] == "0")
        {
            std::cout << "Missing Peso Netto, Pack ignored (N_Collo: " << input["NUMERO_COLLO"] << ")\n-------------------------------------------------\n";
            discardedPack = new Pack();
            discardedPack->setPackID(input["NUMERO_COLLO"]);
            ingoredPacks.push_back(discardedPack);            
            return false;
        }
    return true;
}

const std::vector<Pack*> ReadJson::getPackVector()
{
    return this->outputPackVector;
}

const std::vector<Pack*> ReadJson::getPackIgnoredPackVector()
{
    return this->ingoredPacks;
}

const Geometry::ThreeNum_set<int> ReadJson::getPalletInfos()
{
    return this->outputPalletMaxs;
}

const int ReadJson::getPalletMaxWeight()
{
    return this->maxPalletWeight;
}

