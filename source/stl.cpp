// Jablko 3D Geometry Library: STL file/format reader and data structure
// Cale Overstreet
// February 24, 2020
// Implementation for reading binary STL files

#include "../jablko3d.h"

#include <string>
#include <vector>
#include <cstdio>
#include <fstream>

jablko3d::triangle::triangle(jablko3d::vect normal_in, jablko3d::vect p1_in, jablko3d::vect p2_in, jablko3d::vect p3_in) {
	normal = normal_in;
	p1 = p1_in;
	p2 = p2_in;
	p3 = p3_in;

	area = 0.5 * jablko3d::cross_product(p2 - p1, p3 - p1).magnitude();
	area_vector = normal * area;
}

jablko3d::triangle::triangle(char* facet) {
	char normal_bin[12] = {facet[0], facet[1], facet[2], facet[3], facet[4], facet[5], facet[6], facet[7], facet[8], facet[9], facet[10], facet[11]};
	normal = jablko3d::vect(normal_bin);	
	p1 = jablko3d::vect(facet + 12);
	p2 = jablko3d::vect(facet + 24);
	p3 = jablko3d::vect(facet + 36);
}

jablko3d::stl_object::stl_object(std::string filepath, std::string units) {
	std::ifstream stl_file(filepath, std::ios::in | std::ios::binary);

	char header_buffer[80];
	stl_file.read(header_buffer, 80);
	header = std::string(header_buffer);

	char ntri_buffer[4];
    stl_file.read(ntri_buffer, 4);
    n_triangles = *((unsigned int*) ntri_buffer);

	for (int i = 0; i < n_triangles; i++) {
		if (stl_file) {
			char facet[50];	
			stl_file.read(facet, 50);
			triangles.push_back(jablko3d::triangle(facet));
		} else {
			printf("ERROR: All triangles not present in file. File may be corrupted");
			return;
		}
	}
	
	stl_file.close();
}
