#ifndef GEOM_H
#define GEOM_H

/*
Author: 
	Tommaso Maruzzo
Description:
	Generic templates for common type of elements, such as:
		- ThreeNum_set: 3 values data set, general defined by float type: generally used for 3D coordinates;
		- TwoNum_set: 2 values data set, general defined by an int type: generally used for 2D coordinates or dimensions.
		- Area: identifies an area between 2 diagonal points.

	Remember to use INLINE or STATIC functions
	
    INLINE: 
		Use inline for small, frequently called functions or function templates that you want to avoid duplicating across multiple source files.
		It's a suggestion to the compiler to inline the function's code wherever it's called.

	STATIC: 
		Use static for functions that should be limited to a single translation unit to avoid linkage errors caused by multiple definitions.
		These functions won't be visible outside the file where they're defined.
*/

namespace Geometry {
	template<typename type>
	struct ThreeNum_set { 
		//type for 3 num sets
		type X, Y, Z;
		ThreeNum_set() : X(type(0)), Y(type(0)), Z(type(0)) {}; //general constructor
		ThreeNum_set(type x_val, type y_val, type z_val) : X(type(x_val)), Y(type(y_val)), Z(type(z_val)) {}; //specific constructor
	};

	template<typename type>
	struct TwoNum_set { 
		//type for 2 num sets
		type X, Y;
		TwoNum_set() : X(type(0)), Y(type(0)) {};
		TwoNum_set(type x_val, type y_val) : X(type(x_val)), Y(type(y_val)) {};
	};

	//TODO: make a geometry object "AREA"
	bool compareThreeNum_set (ThreeNum_set <int> firstSet, ThreeNum_set<int> secondSet);

}

#endif