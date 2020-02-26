// Jablko3D Geometry Library: Vect struct unit test
// Cale Overstreet
// February 26, 2020
// Verifies that constructor and class members of vect work correctly

#include <assert.h>
#include <cstdio>
#include "../jablko3d.h"
#include "test_functions.h"

#include <cmath>


void vect_constructor_double() {
	// Initialize a vect with doubles and make sure values are set correctly
	
	printf("TEST: vect constructor initialized with doubles\n");
	
	jablko3d::vect x(1.1, 1.2, 1.3); 
	assert(x.x == 1.1);
	assert(x.y == 1.2);
	assert(x.z == 1.3);
}

void vect_constructor_charpointer() {
	// Initialize a vect with a char* and make sure values are set correctly
	
	printf("TEST: vect constructor initialized with char pointer\n");
	float float_data[3] = {1.1, 1.2, 1.3};
	char* char_pointer = ((char*) float_data);
	jablko3d::vect test_vect(char_pointer);	
	assert(double_equals(test_vect.x, 1.1, 0.001) == true);
	assert(double_equals(test_vect.y, 1.2, 0.001) == true);
	assert(double_equals(test_vect.z, 1.3, 0.001) == true);
}

void vect_magnitude() {
	printf("TEST: vect magnitude member function\n");

	jablko3d::vect x(2, 10, 11);
	assert(double_equals(x.magnitude(), 15, 0.001) == true);
}

void vect_unit_vector() {
	printf("TEST: vect unit_vector member function\n");

	jablko3d::vect x(2, 10, 11);
	jablko3d::vect unit_vect = x.unit_vector();
	assert(double_equals(unit_vect.x, double(2) / 15, 0.001) == true);
	assert(double_equals(unit_vect.y, double(10) / 15, 0.001) == true);
	assert(double_equals(unit_vect.z, double(11) / 15, 0.001) == true);
}

void vect_operator_assignment() {
	printf("TEST: vect operator assignment\n");

	jablko3d::vect x(1.1, 1.2, 1.3);
	jablko3d::vect y = x;

	assert(double_equals(x.x, y.x, 0.001) == true);
	assert(double_equals(x.y, y.y, 0.001) == true);
	assert(double_equals(x.z, y.z, 0.001) == true);
}

void vect_operator_addition() {
	printf("TEST: vect operator addition\n");
	
	jablko3d::vect x(1.1, 1.2, 1.3);
	jablko3d::vect y(2.1, 2.2, 2.3);

	jablko3d::vect sum_1 = x + y;
	assert(double_equals(sum_1.x, 1.1 + 2.1, 0.001) == true);
	assert(double_equals(sum_1.y, 1.2 + 2.2, 0.001) == true);
	assert(double_equals(sum_1.z, 1.3 + 2.3, 0.001) == true);
}

void vect_operator_subtraction() {
	printf("TEST: vect operator subtraction\n");
	jablko3d::vect x(1.1, 1.2, 1.3);
	jablko3d::vect y(1, 1, 1);

	jablko3d::vect ans = x - y;

	assert(double_equals(ans.x, 0.1, 0.001) == true);
	assert(double_equals(ans.y, 0.2, 0.001) == true);
	assert(double_equals(ans.z, 0.3, 0.001) == true);
}

void vect_operator_multiplication() {
	printf("TEST: vect operator multiplication\n");

	jablko3d::vect x(1.1, 1.2, 1.3);
	jablko3d::vect y(2, 2, 2);
	jablko3d::vect ans = x * y;

	assert(double_equals(ans.x, 2.2, 0.001) == true);
	assert(double_equals(ans.y, 2.4, 0.001) == true);
	assert(double_equals(ans.z, 2.6, 0.001) == true);
}

void vect_operator_scalar_multiplication() {
	printf("TEST: vector operator scalar multiplication\n");
	
	jablko3d::vect x(1.1, 1.2, 1.3);
	jablko3d::vect ans = x * 2;

	assert(double_equals(ans.x, 2.2, 0.001) == true);
	assert(double_equals(ans.y, 2.4, 0.001) == true);
	assert(double_equals(ans.z, 2.6, 0.001) == true);
}

void vect_test() {
	vect_constructor_double();
	vect_constructor_charpointer();
	vect_magnitude();
	vect_unit_vector();

	vect_operator_assignment();
	vect_operator_addition();
	vect_operator_subtraction();
	vect_operator_multiplication();
	vect_operator_scalar_multiplication();

}
