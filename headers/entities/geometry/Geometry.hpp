#ifndef GEOM_H
#define GEOM_H

template<typename type>
struct ThreeNum_set { //type for 3D coordinates
	type X, Y, Z;
	ThreeNum_set() : X(type(0.0)), Y(type(0.0)), Z(type(0.0)) {}; //general constructor
	ThreeNum_set(type x_val, type y_val, type z_val) : X(type(x_val)), Y(type(y_val)), Z(type(z_val)) {}; //specific constructor
};

template<typename type>
struct TwoD_coords { //type for 2D coordinates
	type X, Y;
	TwoD_coords() : X(type(0)), Y(type(0)) {};
	TwoD_coords(type x_val, type y_val) : X(type(x_val)), Y(type(y_val)) {};
};

#endif