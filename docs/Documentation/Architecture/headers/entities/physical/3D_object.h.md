
!! VIRTUAL CLASS
## include:
- [[Geometry.h]]
### Variabili:
```cpp
3D<float> objectDims
3D<float> oldObject_Dims //evaluate
3D<float> center
float weight
float density
```
---
### Metodi:
```cpp
~3D_object() {}
void setDims(float x, float y, float z)
void setCenterCoords(dims)
void setWeight(float kg)
void setOrientation(int orientation)
float getVolume()
float getDensity()
3D<float> out_dims getDims()
```
---
### TODO:
* dentro i metodi "set" posso andare a settare direttamente i valori in template tramite assegnazione "=", gli struct dovrebbero poter assegnarsi tranquillamente.
---
### Documentazione: 
Classe virtuale che definisce tutte le caratteristiche di un oggetto 3D del progetto, più metodi che fanno calcoli semplici e le basi dei metodi "SET".