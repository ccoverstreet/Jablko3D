// Jablko 3D geometry library
// Cale Overstreet
// February 24, 2020
// Used for 3D physics

#include <string>
#include <vector>

// Vector Definitions
namespace jablko3d {
	struct vect {
		vect();
		vect(double x_in, double y_in, double z_in); // Base constructor, no precomputing
		~vect();

		double x;
		double y;
		double z;
		double mag;

		double magnitude();
		vect unit_vector();
		std::string vector_string();

		void operator = (vect); 
	};

	vect operator + (vect, vect); // Standard vector addition
	vect operator - (vect, vect); // Standard vector subtraction
	vect operator * (vect, vect); // Multiplies each vector element by the corresponding element in the other vector
	vect operator * (double, vect); // Scalar Multiplication
	vect operator * (vect, double); // Scalar Mulitplication

	vect cross_product(vect a, vect b); // a x b
	double dot_product(vect, vect); // Standard vector dot product
}

// STL File Read
namespace jablko3d {
	struct triangle {
		triangle(vect normal_in, vect p1_in, vect p2_in, vect p3_in);

		vect normal;
		vect p1;
		vect p2;
		vect p3;
		vect area_vector;

		double area;
	};

	struct stl_object {
		stl_object();
		stl_object(std::string filename, std::string units);
		std::string header;
		unsigned int n_triangles;
		std::vector<triangle> triangles;
	};
}
