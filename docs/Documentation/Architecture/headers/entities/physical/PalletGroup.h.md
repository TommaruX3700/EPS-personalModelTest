## include:
- [[Pallet.h]]
### Variabili:
```cpp
//out of class
typedef Pallet* ptrPallet;

//inside class
private:
	std::vector<ptrPallet> palletGroup;
	int max = 0
```
---
### Metodi:
```cpp
PalletGroup();
PalletGroup(int max);
~PalletGroup();

void set_maximum(int a);
int add_Pallet(ptrPallet);
int add_Pallet(ptrPallet, int vectorPosition = -1);
int remove_Pallet(); //deletes the last one
int remove_Pallet(int vectorPosition = -1);
int pallet_Count(); //evaluate if necessary: look at <vector> methods
```
---
### TODO:
* 
---
### Documentazione: 
Questa classe identifica un vettore di puntatori ad oggetti "Pallet" che si raggruppano e formano una serie di pallets pronti per essere esportati in output.