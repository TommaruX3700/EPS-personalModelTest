// Document: DefinedGeomety.h
//
// Description: user-defined geometric abstracions
// NB: forward declarations (to avoid cirular dependencies)

// NOTA: 
//  non ha senso definire cose "dimensions" come caratteristica generale. perde di senso il concetto di ereditarietà della classe.
//  definisco il vecchio "dimensions" direttamente dentro le classi.
//  utilizzo questo file solo ed unicamente per definire le astrazioni geometriche
//  tuttavia posso definire in un altro tipo di file le astrazioni che definiscono le dimensioni geometriche stesse, per evitare i problemi di inclusione che ora ho

#pragma once
#ifndef GEOM_H
#define GEOM_H

#include "Cell.h"
#include "..\3D_Objects\Pack.h"

class definedGeometry
{
    private:
        /* data */

    public:
        definedGeometry();
        ~definedGeometry();
}; 

// Dimensione dei pacchi
class packDimensions : virtual definedGeometry 
{
    private:
        float x, y, z;

    public:
        packDimensions();
        ~packDimensions();
        
};

// Cella dello spazio 3D
class cellGraph : virtual definedGeometry
{
    private: 
        float centerX, centerY;
        bool isFree;
        Pack *pack = nullptr;

    public:
        cellGraph();
        ~cellGraph();
        
};

// Piani dello spazio 3D
class planeGraph : virtual definedGeometry
{
    private:
        int maxX, maxY;
        Cell** cell;

    public:
        planeGraph();
        ~planeGraph();

};

// Coordinate dello spazio 3D
class coordsGraph : virtual definedGeometry
{
    private:
        float x, y, z;
    
    public:
        coordsGraph();
        ~coordsGraph();

};



// class Pack;

// struct cell_t
// {
//     float centerX, centerY;
//     bool isFree;
//     Pack *pack = nullptr;
// }; 

// struct dimensions_t
// {
//     float x, y, z;
// };

// class Cell;
// struct plane_t
// {
//     int maxX, maxY;
//     Cell **cell;
// };

// // singola cella dello spazio
// class Pack;
// struct coords_t
// {
//     float x, y, z;
// };

#endif