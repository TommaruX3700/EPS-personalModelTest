#include <iostream> 
#include <string>
#include <vector>

#include "../entities/physical/Pack.hpp"
#include "../entities/physical/Pallet.hpp"

#include "../../extLibs/nlohmannJSON/json.hpp"

class ReadJson
{
    private:
        std::vector<Pack*> outputPackVector;
        Geometry::ThreeNum_set<int> outputPalletMaxs;

        //Converts string to Json
        nlohmann::json convertStringToJson(std::string inputPath);

        //Gives pack vector as output
        void retrivePacksInfos(nlohmann::json inputJson);

        bool checkPackInfos(nlohmann::json input);

    public:
        ReadJson(std::string stringFileContent);
        const std::vector<Pack*> getPackVector();
        const Geometry::ThreeNum_set<int> getPalletInfos();
};


