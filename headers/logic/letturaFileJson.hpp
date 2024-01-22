#include <iostream> 
#include <string>
#include <vector>

#include "../entities/physical/Pack.hpp"
#include "../entities/physical/Pallet.hpp"

#include "../../extLibs/nlohmannJSON/json.hpp"

/*
TODO: Convert all of this into a class with this infos
- json object as public json object: retrived on constructor
*/

// //Gives pallet as Pallet object for infos
// Pallet getInputPalletInfos(nlohmann::json inputJson);

// //Convert jsonObject to Pack
// Pack getPackByJson(nlohmann::json inputJson);

// //get Pallet infos by jsonObject
// Pallet getPalletByJson(nlohmann::json inputJson);

class ReadJson
{
    private:
        std::vector<Pack*> outputVector;
        std::map<std::string, int> outputPalletInfos;

        //Converts string to Json
        nlohmann::json convertStringToJson(std::string inputPath);

        //Gives pack vector as output
        void retrivePacksInfos(nlohmann::json inputJson);

        bool checkPackInfos(nlohmann::json input);

    public:
        ReadJson();
        std::vector<Pack*> getPackVector();
        std::map<std::string, int> getPalletInfos();
};


