!! class Pallet : 3D_object
## include:
- [[Geometry.h]]
- [[Pack.h]]
### Variabili:
```cpp
//out of class
typedef Pack* ptrPack;

//inside class
private:
	float param_Efficency;
	std::vector<ptrPack> pallet;
```
---
### Metodi:
```cpp
Pallet();
Pallet(float X, float Y, float Z);
~Pallet();

void add_Pack(ptrPack);
void add_Pack(ptrPack, int vectorPosition = NULL);
void remove_Pack(); //deletes the last one
void remove_Pack(int vectorPosition = -1);
int pack_Count(); //evaluate if necessary: look at <vector> methods
```
---
### TODO:
* valutare eventuale implementazione di override degli operatori C++ appositamente x i pallet
* ricordarsi che Pallet eredita tutto 3D_object e che può sfruttare il template 3D dims
---
### Documentazione: 
Andando a ereditare tutte le variabili e metodi (da overriddare) dalla classe virtuale, Pallet.h ottiene già ereditate le dimensioni in quanto oggetto 3D e metodi utili per la successiva valutazione dello stesso/ottenimento di dati e info complessive varie.