## include:
- [[Cell.h]]
- 

### Variabili:
```cpp
private:
	int maxX, maxY;
	Cell plane**;
```
---
### Metodi:
```cpp
public:
	Plane();
	Plane(int maxX, int maxY);
	
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