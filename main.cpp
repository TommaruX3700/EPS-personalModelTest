// Enable to 1 to execute only "TEST_REGION"
#define TEST_MODE 0

#pragma region "Includes"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>

#include "extLibs/nlohmannJSON/json.hpp"
#include "extLibs/rapidjson/document.h"

#include "headers/entities/physical/Pack.hpp"
#include "headers/entities/physical/PalletGroup.hpp"
#include "headers/entities/geometry/Grid.hpp"

#include "headers/logic/LetturaJson/letturaFileJson.hpp"
#include "headers/logic/OrdinamentoPacchi/ordinamentoPacchi.hpp"

#include "headers/logic/MainMethods/messages.hpp"
#include "headers/logic/MainMethods/test.hpp"
#pragma endregion

int main(int argc, char *argv[])
{
    try
    {
#pragma region "Global Variables"
        std::string inputJsonPath;
        packVector packs;
        Pallet examplePallet;
#pragma endregion

#if TEST_MODE == 1
        /*
         * FOR NESTING DEBUG, LAUNCH OPERATIONS STRAIGHT FROM HERE
         */
        testFunction();
#else
#pragma region "BlockCode 1 - Startup Routine"
        try
        {
            if (argc > 1)
            {
                // Gets arguments as INPUT
                inputJsonPath = argv[1];
                consoleStartMessage(inputJsonPath);
                // Check if file exists
                std::ifstream inputFile(inputJsonPath);
                if (!inputFile)
                {
                    // File doesn't exists: throw error
                    throw std::invalid_argument("Invalid JSON path provided or unable to access file.");
                }
                else
                {
                    // Open the file
                    std::ifstream file(inputJsonPath);
                    // Read the entire file into a string --> https://www.geeksforgeeks.org/rapidjson-file-read-write-in-cpp/
                    std::string jsonStringContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                    ReadJson jsonConverter(jsonStringContent);
                    packs = jsonConverter.getPackVector();
                    examplePallet = Pallet(jsonConverter.getPalletInfos());
                }
            }
            else
            {
                consoleLog("WARNING: NO JSON FILE PROVIDED");
                return -1;
            }
        }
        catch (const std::exception &e)
        {
            return consoleErrorMessage(e.what());
        }

#pragma endregion

#pragma region "BlockCode 2 - Pallet Loop"

#pragma region "BlockCode 2.1 - Ordinamento Input && Scelta pacchi Nesting"
        /*
         *   Il concetto di base è di avere TUTTI i pacchi sul vettore secondario, in modo da iterare successivamente il sortInput()
         *   e lavorare quindi usando il primo vettore come "vettore operativo" ed il secondo come buffer per i pacchi scartati.
         */
        PalletGroup palletGroup;
        Geometry::ThreeNum_set<int> palletDims = examplePallet.getPalletDims();

        packVector pacchiNonPallettizzabiliByFLAG;
        std::pair<packVector, packVector> dividedPacks;

        dividedPacks = isPalletizable(packs);
        pacchiNonPallettizzabiliByFLAG = dividedPacks.second;

#pragma endregion

#pragma region "BlockCode 2.2 - Crea pallet da pacchi non palletizzabili dal flag"
        /*
         *   Aggiungo tutti i pacchi non palletizzabili by flag a dei Pallet dedicati.
         */
        for (auto pack : pacchiNonPallettizzabiliByFLAG)
        {
            Pallet newPallet(palletDims);
            newPallet.addPack(*pack);
            palletGroup.addPallet(&newPallet);
        }
#pragma endregion

#pragma region "BlockCode 2.3 - Nesting loop"
        /*
         *   Raccolgo l'output dei miei threads nel vettore "nestedPallets", mentre in "remainingPacks" i pacchi scartati.
         */
        packVector packsToNest, remainingPacks;
        std::vector<Pallet> nestedPallets;

        packsToNest = dividedPacks.first;

        // MainNestLoops(palletDims, nestedPallets, packsToNest)
        Pallet *newPallet;
        do
        {
            /*
             *   Add pallet vector reference to save reference.
             */
            newPallet = new Pallet(palletDims);

            /*
             *   Execute a sortInput and reorder the packs.
             */
            float area = 0;
            float pack_area = 0;
            float pallet_area = newPallet->getPalletDims().num1 * newPallet->getPalletDims().num2;

            /*
             *  TODO:
             *      - add weight controll
             *      
             */

            quickSort(packsToNest, 0, packsToNest.size() - 1);

            if ((packsToNest[0]->getDims().num1 * packsToNest[0]->getDims().num2) >= pallet_area)
            {
                // do this or skip pack or put in another list
                // newPallet->addPack(*packsToNest[0]);
                remainingPacks.push_back(packsToNest[0]);
                packsToNest.erase(packsToNest.begin());
            }
            else
            {
                int cursor = 0;
                auto it = packsToNest.begin();
                while (it != packsToNest.end())
                {
                    const auto &pack = *it;
                    area += (pack->getDims().num1 * pack->getDims().num2);
                    if (area <= pallet_area)
                    {
                        newPallet->addPack(*pack);
                        it = packsToNest.erase(it); // Erase and update iterator
                    }
                    else
                    {
                        ++it; // Move to the next element
                        cursor++;
                    }
                }
                nestedPallets.push_back(*newPallet);
            }
        } while (packsToNest.size());

        for (Pallet pallet : nestedPallets)
        {
            std::cout << "Pallet " << pallet.getPalletID() << ", containing packs: " << pallet.getPackCount() << std::endl;
            if (pallet.getPackCount())
            {
                std::vector<Pack> retrivedPallet = pallet.getPackVector();
                for (auto pack : retrivedPallet)
                {
                    std::cout << "  - Pack ID -> " << pack.getPackID() << std::endl;
                }
            }
            palletGroup.addPallet(&pallet);
        }
#pragma endregion

#pragma endregion

#pragma region "BlockCode 3 - End Routine"

        nlohmann::json json_output, json_pallets, json_unNestedPacks;
        std::string palletLabel;

        for (auto pallet : nestedPallets)
        {
            nlohmann::json pallet_data, pack_data;
            palletLabel = std::to_string(reinterpret_cast<uintptr_t>(pallet.getPalletID()));
            pallet_data["Pallet"] = palletLabel.substr(palletLabel.length() - 6);
            pallet_data["Packs"];
            // put pallet id to pallet objects and identify them
            for (auto pack : pallet.getPackVector())
            {
                // aggiungere su questo push back l'oggetto pacco intero con tutti i flags
                pack_data.clear();
                pack_data["id"] = pack.getPackID();
                pack_data["rf"] = pack.getRotatableFlag();
                pack_data["rs"] = pack.getSovrapponibileFlag();

                pallet_data["Packs"].push_back(pack_data);
            }
            json_pallets.push_back(pallet_data);
        }

        for (auto pack : remainingPacks)
        {
            json_unNestedPacks.push_back(pack->getPackID());
        }

        json_output["Pallets"] = json_pallets;
        json_output["UnNestedPacks"] = json_unNestedPacks;

        std::string filename = ".\\output.json";

        // Write the JSON object to a file
        std::ofstream ofs(filename);
        if (!ofs.is_open())
        {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return 1;
        }

        ofs << std::setw(4) << json_output << std::endl; // Write formatted JSON to file
        ofs.close();

        std::cout << "JSON data written to " << filename << std::endl;

#pragma endregion

#endif
        return 0;
    }
    catch (const std::invalid_argument &e)
    {
        return consoleErrorMessage(e.what());
    }
    catch (const std::exception &e)
    {
        return consoleErrorMessage(e.what());
    }
}