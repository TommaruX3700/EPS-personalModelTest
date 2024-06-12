#include "../../../headers/logic/MainMethods/test.hpp"

bool CheckIfPackFits(Pack i_pack, ThreeNum_set<int> pallet_dims, int pallet_max_weight, float* remaining_pallet_area, float full_pallet_area, float* actual_pallet_weight, int* actual_pallet_volume)
{
    // CHECKS se il pacco rispetta le seguenti caratteristiche, per tutte le sue eventuali rotazioni:
    //      - dimensioni massime del pallet.

    // AGGIORNA il valore puntato da "remaining_pallet_area"

    // Height controll: if its higher than max pallet height, rotate untill it fits
    int total_pallet_volume = pallet_dims.num1 * pallet_dims.num2 * pallet_dims.num3;

    for (size_t i = 0; i < 6; i++)
    {
        i_pack.changeObjectOrientation(i+1);
        // fare tutti i controlli e se passano ok, altrimenti ruota
        if (i_pack.getDims().num3 > pallet_dims.num3)
            break;

        if (i_pack.getDims().num1 > pallet_dims.num1 && i_pack.getDims().num2 > pallet_dims.num2)
            break;
        
        if (*actual_pallet_volume > total_pallet_volume) 
            break;

        if ((i_pack.getWeight() + *actual_pallet_weight) > pallet_max_weight)
            break;

        *actual_pallet_volume += i_pack.getDims().num1 * i_pack.getDims().num2 + i_pack.getDims().num3;
        *actual_pallet_weight += i_pack.getWeight();
        // se passano tutti, modfiicare la remaining_pallet_area
    }
    
    return false;
}

void testFunction()
    {
        std::string outputTestString = "";
        /*
            DOING: Ticket #25
        */

        #pragma region "test Pack & 3D_object"
            //PACK: funziona
            ThreeNum_set<int> testDims, testCoords;
            testDims.num1 = 4;
            testDims.num2 = 6;
            testDims.num3 = 2;
            testCoords.num1 = 5; 
            testCoords.num2 = 5;
            testCoords.num3 = 5; 

            float testWeight = 2.4;
            int testID = 10;
            bool testFlag = true;

            Pack testPack1(testDims, testCoords, testWeight, testID, testFlag, false);

            testDims.num1 = 2;
            testDims.num2 = 2;
            testDims.num3 = 2;
            testCoords.num1 = 1; 
            testCoords.num2 = 1;
            testCoords.num3 = 1; 

            Pack testPack2(testDims, testCoords, 1, 20, true, true);
                    
            ThreeNum_set<int> extractedDims;
            extractedDims = testPack1.getDims();
            ThreeNum_set<int> extractedCoords;
            extractedCoords = testPack1.getCenterCoords();

            outputTestString = " Pack1 dims are: \n X -> " + std::to_string(extractedDims.num1) + "\n Y -> " + std::to_string(extractedDims.num2) + "\n Z -> " + std::to_string(extractedDims.num3) + "\n";
            outputTestString += "\n Pack1 coords are: \n X -> " + std::to_string(extractedCoords.num1) + "\n Y -> " + std::to_string(extractedCoords.num2) + "\n Z -> " + std::to_string(extractedCoords.num3) + "\n";
            outputTestString += "\n Pack1 Volume: " + std::to_string(testPack1.getVolume());
            outputTestString += "\n Pack1 ID: " + std::to_string(testPack1.getPackID());
            outputTestString += "\n Pack1 Density: " + std::to_string(testPack1.getDensity());
                    
            //testPack2 = testPack1;

            extractedDims = testPack2.getDims();
            extractedCoords = testPack2.getCenterCoords();

            outputTestString += "\n\n Pack2 dims are: \n X -> " + std::to_string(extractedDims.num1) + "\n Y -> " + std::to_string(extractedDims.num2) + "\n Z -> " + std::to_string(extractedDims.num3) + "\n";
            outputTestString += "\n Pack2 coords are: \n X -> " + std::to_string(extractedCoords.num1) + "\n Y -> " + std::to_string(extractedCoords.num2) + "\n Z -> " + std::to_string(extractedCoords.num3) + "\n";
            outputTestString += "\n Pack2 Volume: " + std::to_string(testPack2.getVolume());
            outputTestString += "\n Pack2 ID: " + std::to_string(testPack2.getPackID());
            outputTestString += "\n Pack2 Density: " + std::to_string(testPack2.getDensity());
                    
            if (testPack1 == testPack2)
            {
                outputTestString += "\n\n I PACCHI SONO UGUALI :)";
            } else
            {
                outputTestString += "\n I PACCHI SONO DIVERSI :(";
            }
        #pragma endregion

        #pragma region "test creazione Grid"
            //funziona
            ThreeNum_set<int> testMaxDims;
            testMaxDims.num1 = 20;
            testMaxDims.num2 = 20;
            testMaxDims.num3 = 20;

            Grid testGrid(testMaxDims);

        #pragma endregion

        #pragma region "test assegnazione Pack su Grid"
            //funziona
            //funziona ma non fa il suo lavoro correttamente.
            testGrid.setOccupiedCells(&testPack1);
            testGrid.setOccupiedCells(&testPack2);
        #pragma endregion

        #pragma region "test eliminazione Pack da Grid"
            //funziona
            //testGrid.freeOccupiedCells(&testPack1);
            //testGrid.freeOccupiedCells(&testPack2);
        #pragma endregion

        std :: cout << "piano1: XY" << std :: endl;
        testGrid.printGrid(1);
        std :: cout << "piano2: YZ" << std :: endl;
        testGrid.printGrid(2);
        std :: cout << "piano3: XZ" << std :: endl;
        testGrid.printGrid(3);
        //consoleLog(outputTestString);
    }
