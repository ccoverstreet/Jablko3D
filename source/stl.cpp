// Jablko 3D Geometry Library: STL file/format reader and data structure
// Cale Overstreet
// February 24, 2020
// Implementation for reading binary STL files

#include "../jablko3d.h"

#include <string>
#include <vector>
#include <iostream>

jablko3d::triangle::triangle(jablko3d::vect normal_in, jablko3d::vect p1_in, jablko3d::vect p2_in, jablko3d::vect p3_in) {
	normal = normal_in;
	p1 = p1_in;
	p2 = p2_in;
	p3 = p3_in;

	area = 0.5 * jablko3d::cross_product(p2 - p1, p3 - p1).magnitude();
	area_vector = normal * area;
}

jablko3d::stl_object::stl_object(std::string filename) {
	std::cout << filename << "\n";
}

