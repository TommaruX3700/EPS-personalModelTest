#include "../../../headers/logic/MainMethods/test.hpp"

void testFunction()
    {
        std::string outputTestString = "";
        /*
            DOING: Ticket #25
        */

        #pragma region "test Pack & 3D_object"
            //PACK: funziona
            ThreeNum_set<int> testDims, testCoords;
            testDims.X = 4;
            testDims.Y = 6;
            testDims.Z = 2;
            testCoords.X = 5; 
            testCoords.Y = 5;
            testCoords.Z = 5; 

            float testWeight = 2.4;
            int testID = 10;
            bool testFlag = true;

            Pack testPack1(testDims, testCoords, testWeight, testID, testFlag, false);

            testDims.X = 2;
            testDims.Y = 2;
            testDims.Z = 2;
            testCoords.X = 1; 
            testCoords.Y = 1;
            testCoords.Z = 1; 

            Pack testPack2(testDims, testCoords, 1, 20, true, true);
                    
            ThreeNum_set<int> extractedDims;
            extractedDims = testPack1.getDims();
            ThreeNum_set<int> extractedCoords;
            extractedCoords = testPack1.getCenterCoords();

            outputTestString = " Pack1 dims are: \n X -> " + std::to_string(extractedDims.X) + "\n Y -> " + std::to_string(extractedDims.Y) + "\n Z -> " + std::to_string(extractedDims.Z) + "\n";
            outputTestString += "\n Pack1 coords are: \n X -> " + std::to_string(extractedCoords.X) + "\n Y -> " + std::to_string(extractedCoords.Y) + "\n Z -> " + std::to_string(extractedCoords.Z) + "\n";
            outputTestString += "\n Pack1 Volume: " + std::to_string(testPack1.getVolume());
            outputTestString += "\n Pack1 ID: " + std::to_string(testPack1.getPackID());
            outputTestString += "\n Pack1 Density: " + std::to_string(testPack1.getDensity());
                    
            //testPack2 = testPack1;

            extractedDims = testPack2.getDims();
            extractedCoords = testPack2.getCenterCoords();

            outputTestString += "\n\n Pack2 dims are: \n X -> " + std::to_string(extractedDims.X) + "\n Y -> " + std::to_string(extractedDims.Y) + "\n Z -> " + std::to_string(extractedDims.Z) + "\n";
            outputTestString += "\n Pack2 coords are: \n X -> " + std::to_string(extractedCoords.X) + "\n Y -> " + std::to_string(extractedCoords.Y) + "\n Z -> " + std::to_string(extractedCoords.Z) + "\n";
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
            testMaxDims.X = 20;
            testMaxDims.Y = 20;
            testMaxDims.Z = 20;

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
