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

#include "headers/logic/MainMethods/fitIntoPallet.hpp"
#include "headers/logic/MainMethods/messages.hpp"
#include "headers/logic/MainMethods/test.hpp"
#pragma endregion


/*
 * TODO:
 *     - big sexy ENUM for retrun states
 *     - add weight control
 *     - add height control
 *     - test last case
 *     - fix "faultedPacks" ID returns in output .json 
 *     - list all error codes
 * 
 * Test da fare:
 *	test5 - con controllo peso e altezza
 *	
 *	!!! aggiunta sezione "faulted packs" al json di output
 */

int main(int argc, char *argv[])
{
    try
    {
#pragma region "Global Variables"
        std::string inputJsonPath;
        packVector packs, ignoredPacks;
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
                    std::ifstream file(inputJsonPath);
                    std::string jsonStringContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                    ReadJson jsonConverter(jsonStringContent);
                    packs = jsonConverter.getPackVector();
                    if (!packs.size())
                    {
                        consoleErrorMessage("NO VALID PACKS OR PACK WITHOUT LABEL DETECTED, TERMINATING: CHECK INPUT");
                        return 10;
                    }
                    ignoredPacks = jsonConverter.getPackIgnoredPackVector();
                    examplePallet = Pallet(jsonConverter.getPalletInfos(), examplePallet.getMaxPalletWeight());
                    if ((examplePallet.getPalletDims().num1 * examplePallet.getPalletDims().num2 * examplePallet.getPalletDims().num3) <= 0)
                    {
                        consoleErrorMessage("PALLET DIMS ARE NOT VALID, TERMINATING: CHECK PALLET INPUT");
                        return 11;
                    }
                }
            }
            else
            {
                consoleLog("WARNING: NO JSON FILE PROVIDED");
                return -1;
            }

            if (!packs.size())
            {
                consoleErrorMessage("Not a single pack was given!");  
                return 3;
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

        packVector packsToNest, remainingPacks;

#pragma region "BlockCode 2.2 - Gestione pacchi non palletizzabili dal flag"
        /*
         *   Aggiungo tutti i pacchi non palletizzabili by flag a dei Pallet dedicati.
         */
        float pallet_area = palletDims.num1 * palletDims.num2;  
        float remaining_pallet_area = pallet_area;
        float actual_pallet_weight = 0;
        int actual_pallet_volume = 0;

        for (auto pack : pacchiNonPallettizzabiliByFLAG)
        {
            if (pack->getDims().num1*pack->getDims().num2 >= pallet_area)
            {
                // Pacchi non sono palletizzabili e la cui area supera quella presente del pallet.
                if (CheckIfPackFits(*pack, examplePallet.getPalletDims(), examplePallet.getMaxPalletWeight(), &remaining_pallet_area, pallet_area, &actual_pallet_weight, &actual_pallet_volume))
                {
                    Pallet* newPallet = new Pallet(palletDims, examplePallet.getMaxPalletWeight());
                    newPallet->addPack(*pack);
                    palletGroup.addPallet(*newPallet);
                }
                else
                {
                    // Pack doesnt fit in any possible way, discard it
                    remainingPacks.push_back(pack);
                }
            }
            else
            {
                // Pacchi non palletizzabili e che rientrano nell' area del pallet.
                if (CheckIfPackFits(*pack, examplePallet.getPalletDims(), examplePallet.getMaxPalletWeight(), &remaining_pallet_area, pallet_area, &actual_pallet_weight, &actual_pallet_volume))
                {
                    // Pack fully fits and area have been occupied
                    Pallet* newPallet = new Pallet(palletDims, examplePallet.getMaxPalletWeight());
                    newPallet->addPack(*pack);
                    palletGroup.addPallet(*newPallet);
                }
                else
                {
                    // Pack doesnt fit in any possible way, discard it
                    remainingPacks.push_back(pack);
                }
            }
            remaining_pallet_area = pallet_area;
        }
#pragma endregion

#pragma region "BlockCode 2.3 - Gestione pacchi palletizzabili dal flag"
        /*
         *   Raccolgo l'output dei miei threads nel vettore "nestedPallets", mentre in "remainingPacks" i pacchi scartati.
         */
        std::vector<Pallet> nestedPallets;
        if (dividedPacks.first.size())
        {
            packsToNest = dividedPacks.first;

            // MainNestLoops(palletDims, nestedPallets, packsToNest)
            Pallet *newPallet;
            do
            {
                //   Add pallet vector reference to save reference.
                newPallet = new Pallet(palletDims, examplePallet.getMaxPalletWeight());

                //   Execute a sortInput and reorder the packs.
                float area = 0;
                float pack_area = 0;
                float pallet_area = newPallet->getPalletDims().num1 * newPallet->getPalletDims().num2;
                float pallet_height = newPallet->getPalletDims().num3;

                quickSort(packsToNest, 0, packsToNest.size() - 1);

                if ((packsToNest[0]->getDims().num1 * packsToNest[0]->getDims().num2) >= pallet_area)
                {
                    // TODO: ruotare il pacco e controllare se esiste una posizione che rispetta:
                    //      - altezza;
                    //      - peso massimo;
                    //      - dimensioni massime del pallet.

                    // do this or skip pack or put in another list
                    // newPallet->addPack(*packsToNest[0]);
                    remainingPacks.push_back(packsToNest[0]);
                    packsToNest.erase(packsToNest.begin());
                }
                else
                {
                    // TODO: ruotare il pacco e controllare se esiste una posizione che rispetta:
                    //      - altezza;
                    //      - peso massimo;
                    //      - dimensioni massime del pallet.
                 
                    int cursor = 0;
                    auto it = packsToNest.begin();
                    while (it != packsToNest.end())
                    {
                        // Height controll: if its higher than max pallet height, rotate untill it fits
                        const auto &pack = *it;
                        while (pack->getDims().num3 > pallet_height)  
                        {
                            // make a rotation until the pack can stai inside the pallet
                            pack->changeObjectOrientation(pack->getOrientation() + 1);
                            break;
                        }
                        
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
                        std::cout << "  - Pack ID -> " << pack.getPackID() << std::endl;
                }
                palletGroup.addPallet(pallet);
            }
        }

#pragma endregion

#pragma endregion

#pragma region "BlockCode 3 - End Routine"

        nlohmann::json json_output, json_pallets, json_unNestedPacks, json_faultedPacks;
        std::string palletLabel;
        
        if (!palletGroup.palletCount())
        {
            consoleErrorMessage("No packs could be nested! Pallet is way to small..");
            return 2;
        }
        
        for (auto pallet : palletGroup.getPalletGroup())
        {
            nlohmann::json pallet_data, pack_data;
            palletLabel = std::to_string(reinterpret_cast<uintptr_t>(pallet.getPalletID())+1);
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

        for (auto pack : ignoredPacks)
        {
            json_faultedPacks.push_back(pack->getPackID());
        }
        
        json_output["Pallets"] = json_pallets;
        json_output["UnNestedPacks"] = json_unNestedPacks;
        json_output["FaultedPacks"] = json_faultedPacks;

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