// Document: Pack.h
//
// Description: Pack class declaration

#ifndef PACK_H //"header guards", they prevents C++ header files from beign included multiple times
#define PACK_H

#include "..\Geometry\DefinedGeometry.h"
#include "..\Geometry\DefinedObjects.h"

// struct dimensions_t;

class Pack : virtual definedObject
        {
        private:
                float weight;  // Unit: [kg]
                float density; // Unit: [kg/m^3]

                // packDimensions dims;
                // packDimensions old_dims;
                // packDimensions center;

                definedObject dims;
                definedObject old_dims;
                definedObject center;


                // dimensions_t dims;     // Note: those are the current dimensions effected by current orientation
                // dimensions_t old_dims; // Note: this old structure is    use to preserve the original orientation of the pack
                // dimensions_t center;

                int packID;
                bool rotatable;
                bool palletizable;

                // int packPalletIndex;    //TODO: this contains the Index of where it is inside a Vector (evaluate if usefull or not)

        public:
                // CONSTRUCTORS
                Pack() {}                                                                 // generic constructor
                Pack(float X, float Y, float Z, float WGHT, int n_collo, bool ruotabile); // specific constructor

                Pack &operator=(const Pack &n) //"=" operator override "copy constructor"
                {
                        if (this != &n)
                        {
                                // if (&weight != 0 && &density != 0 && &dims != 0 && &old_dims != 0 && &center != 0 && &)
                                // {
                                //         // pulisci variabili
                                // }
                                // copia le variabili nel nuovo oggetto
                                weight = n.weight;
                                density = n.density;
                                dims = n.dims;
                                old_dims = n.dims;
                                center = n.center;
                                packID = n.packID;
                                rotatable = n.rotatable;
                                palletizable = n.palletizable;
                                
                        }
                        return *this;
                };

                ~Pack(); // TODO: implement distructor

                // SET-METHODS
                void set_dims(float x, float y, float z); // dimensions are set with real values
                void set_centerCoords(float x, float y, float z);
                void set_weight(float kg);
                void set_orientation(int a); // a = orientation (0~5, with 0 as standard orientation)
                void set_isRotatable(bool is_rotatable);
                void set_packID(int n_collo);

                definedObject *get_Dims(); // outs a pointer to an out stucture (with correct dimensions)

                // GET-METHODS
                int get_PackID();
};

#endif
