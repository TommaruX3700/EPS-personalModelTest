#ifndef GEOM_H
#define GEOM_H

/*
Author: 
	Tommaso Maruzzo
Description:
	Generic templates for common type of elements, such as:
		- ThreeD_coords: 3D coordinates XYZ, general defined by float type;
		- TwoD_coords: 2D coordinates XY, general defined by an int type.
*/

template<typename type>
struct ThreeD_coords { //type for 3D coordinates
	type X, Y, Z;
	ThreeD_coords() : X(type(0.0)), Y(type(0.0)), Z(type(0.0)) {}; //general constructor
	ThreeD_coords(type x_val, type y_val, type z_val) : X(type(x_val)), Y(type(y_val)), Z(type(z_val)) {}; //specific constructor
};

template<typename type>
struct TwoD_coords { //type for 2D coordinates
	type X, Y;
	TwoD_coords() : X(type(0)), Y(type(0)) {};
	TwoD_coords(type x_val, type y_val) : X(type(x_val)), Y(type(y_val)) {};
};

#endif