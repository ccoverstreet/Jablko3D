#include <iostream>
#include "../jablko3d.h"

int main() {
	jablko3d::vect x(1, 2, 3);
	jablko3d::vect y(4, 5, 6);
	std::cout << (x - y).vector_string() << "\n";
	std::cout << (x + y).vector_string() << "\n";
	std::cout << (y * 2).vector_string() << "\n";
	std::cout << (y * x).vector_string() << "\n";

	std::cout << jablko3d::cross_product(jablko3d::vect(0, 1, 0), jablko3d::vect(1, 0, 0)).vector_string() << "\n";

	jablko3d::triangle mytriangle(jablko3d::vect(1, 0, 0), jablko3d::vect(0, 0, 0), jablko3d::vect(0, 2, 2), jablko3d::vect(0, 2, 0));

	printf("%f %f %f\n", mytriangle.normal.x, mytriangle.normal.y, mytriangle.normal.z);
	printf("%f %f %f\n", mytriangle.p1.x, mytriangle.p1.y, mytriangle.p1.z);
	printf("%f %f %f\n", mytriangle.p2.x, mytriangle.p2.y, mytriangle.p2.z);
	printf("%f %f %f\n", mytriangle.p3.x, mytriangle.p3.y, mytriangle.p3.z);
	printf("Area = %f\n", mytriangle.area);
	printf("Area Vector: %f %f %f\n", mytriangle.area_vector.x, mytriangle.area_vector.y, mytriangle.area_vector.z);

	printf("Area Projection: %f", jablko3d::dot_product(mytriangle.area_vector, jablko3d::vect(1, 1, 0).unit_vector()));

	jablko3d::stl_object mystl("Hello.stl", "mm");
} 
