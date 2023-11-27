#ifndef GEOM_H
#define GEOM_H

/*
Author: 
	Tommaso Maruzzo
Description:
	Generic templates for common type of elements, such as:
		- ThreeNum_set: 3 values data set, general defined by float type: generally used for 3D coordinates;
		- TwoNum_set: 2 values data set, general defined by an int type: generally used for 2D coordinates or dimensions.
*/

#pragma region "Project templates"
template<typename type>
struct ThreeNum_set { //type for 3D coordinates
	type X, Y, Z;
	ThreeNum_set() : X(type(0.0)), Y(type(0.0)), Z(type(0.0)) {}; //general constructor
	ThreeNum_set(type x_val, type y_val, type z_val) : X(type(x_val)), Y(type(y_val)), Z(type(z_val)) {}; //specific constructor
};

template<typename type>
struct TwoNum_set { //type for 2D coordinates
	type X, Y;
	TwoNum_set() : X(type(0.0)), Y(type(0.0)) {};
	TwoNum_set(type x_val, type y_val) : X(type(x_val)), Y(type(y_val)) {};
};

#pragma endregion

bool compareThreeNum_set (ThreeNum_set <float> firstSet, ThreeNum_set<float> secondSet);

#endif