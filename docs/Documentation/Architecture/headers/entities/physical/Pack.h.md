!! class Pack : 3D_object
## include:
- [[3D_object.h]]
- 
### Variabili:

```cpp
int packID
bool rotatable
bool palletizable
```
---
### Metodi:
```cpp
Pack()
Pack(ThreeD_coords<float> coords, float WEIGHT, int CODE, bool ROT) {}
~Pack()
Pack &operator=(const Pack &n) //override "=" to make a custom copy constructor
Pack &operator==(const Pack &n) //override "==" to confront two "Pack" objects
void setRotatable(bool ROT)
void setPackID(int CODE)
int getPackID()
```
---
### TODO:
* I metodi sono tutti inerenti alle operazioni che vanno a modificare il singolo pacco, come modificarne le dimensioni, impostare le dimensioni, ruotare il pacco e così via. 
* Necessita di due costruttori separati per permettere l'uso nelle diverse situazioni;
---
### Documentazione: 
Questo oggetto rappresenta il pacco e tutte le sue caratteristiche fisiche e operazioni che vi si possono effettuare.
Notare come sia possibile effettuare operazioni tramite i normali operatori di C++ come il assegnazione diretta tra pacchi tramite " = " o di confronto tramite " == ".