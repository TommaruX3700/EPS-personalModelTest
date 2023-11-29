## include:
- [[Cell.h]]
- 

### Variabili:
```cpp
private:
	TwoD_coords<int> maxDimensions;
	Cell plane**;
```
---
### Metodi:
```cpp
public:
	Plane();
	Plane(TwoD_coords<int> maxDimensions);
	
	~Plane();
	
    TwoD_coords<int> getMaxPlaneDims();
```
---
### TODO:
- [ ] definire operazioni su celle (da usare poi direttamente da Grid)
- [ ] 
---
### Documentazione: 
Piano è definito da una singola matrice bidimensionale di variabili Struct Cell.