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
	/*
	*	Type for 3 num sets.
	*	Used for coordinates, ranges and similar applications involving 3 values working togheter
	*/
	struct ThreeNum_set { 
		type num1, num2, num3;
		ThreeNum_set() : num1(type(0)), num2(type(0)), num3(type(0)) {}; //general constructor
		ThreeNum_set(type num1_val, type num2_val, type num3_val) : num1(type(num1_val)), num2(type(num2_val)), num3(type(num3_val)) {}; //specific constructor
	};

	template<typename type>
	/*
	*	Type for 2 num sets.
	*	Used for coordinates, ranges and similar applications involving 2 values working togheter
	*/
	struct TwoNum_set { 
		type num1, num2;
		TwoNum_set() : num1(type(0)), num2(type(0)) {};
		TwoNum_set(type num1_val, type num2_val) : num1(type(num1_val)), num2(type(num2_val)) {};
	};

	bool compareThreeNum_set (ThreeNum_set <int> firstSet, ThreeNum_set<int> secondSet);

	struct GraphRange
	{
		int h1;
		int h2;
		TwoNum_set<int> range;
	};
	
}

#endif