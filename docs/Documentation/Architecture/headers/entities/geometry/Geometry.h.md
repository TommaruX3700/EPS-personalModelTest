### Variabili:

```cpp
template<typename type>
struct 3D_coords { //type for 3D coordinates
	type X, Y, Z;
	3D_coords() : X(type(0.0)), Y(type(0.0)), Z(type(0.0)) {}; //general constructor
	3D_coords(type x_val, type y_val, type z_val) : X(type(x_val)), Y(type(y_val)), Z(type(z_val)) {}; //specific constructor
};

template<typename type>
struct 2D_coords { //type for 2D coordinates
	type X, Y;
	2D_coords() : X(type(0)), Y(type(0)) {};
	2D_coords(type x_val, type y_val) : X(type(x_val)), Y(type(y_val)) {};
};
```

---
### Uso:
Raggruppare sotto uno stesso template tutte le definizioni dei tipi usate nel progetto.
Inizialmente, genera un tipo generico (per permettere la creazione delle istanze virtuali), poi permette la creazione di struct sia di tipo float che di tipo int (o qualsiasi altro tipo, occhio) e la conseguente assegnazione alle variabili definite dalle classi figlie.