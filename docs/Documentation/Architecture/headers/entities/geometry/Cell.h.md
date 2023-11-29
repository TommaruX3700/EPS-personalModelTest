## include:
- [[Geometry.h]]
- [[Pack.h]]

```cpp
struct Cell {
	2D_coords<float> coords;
	bool isFree;
	Pack* pack = nullptr;
}
```
---
### TODO:
- [ ] valutare se rimuovere questo elemento e lavorare direttamente con matrici bidimensionali di puntatori a pacco dentro Plane.h, semplificando il progetto ed evitanto di creare 50k di oggetti cella a piano (considerando un pallet di 150cmX150cmX150cm, sono circa 22500 celle per un totale di 67,500 oggetti)
---
### Documentazione: 
Definizione di singola cella.