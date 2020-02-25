// Jablko 3D Geometry: Vect
// Cale Overstreet
// February 24, 2020
// Contains the implmentation of the Vect class and vector operations. Fundamental data structure.

#include "jablko3d.h"

#include <cmath>

jablko3d::vect::vect() {
	x = 0;
	y = 0;
	z = 0;
}

jablko3d::vect::vect(double x_in, double y_in, double z_in) {
	x = x_in;
	y = y_in;
	z = z_in;
}

jablko3d::vect::~vect() {}

double jablko3d::vect::magnitude() {
	mag = std::sqrt(x * x + y * y + z * z);
	return mag;
}

std::string jablko3d::vect::vector_string() {
	return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
}

jablko3d::vect jablko3d::vect::unit_vector() {
	this->magnitude();
	return jablko3d::vect(x / mag, y / mag, z / mag);
}

void jablko3d::vect::operator = (jablko3d::vect value) {
	x = value.x;
	y = value.y;
	z = value.z;
}

jablko3d::vect jablko3d::operator + (jablko3d::vect a, jablko3d::vect b) {
	return jablko3d::vect(a.x + b.x, a.y + b.y, a.z + b.z);
}

jablko3d::vect jablko3d::operator - (jablko3d::vect a, jablko3d::vect b) {
	return jablko3d::vect(a.x - b.x, a.y - b.y, a.z - b.z);
}

jablko3d::vect jablko3d::operator * (jablko3d::vect a, jablko3d::vect b) {
	return jablko3d::vect(a.x * b.x, a.y * b.y, a.z * b.z);
}

jablko3d::vect jablko3d::operator * (double k, jablko3d::vect v) {
	return jablko3d::vect(v.x * k, v.y * k, v.z * k);
}

jablko3d::vect jablko3d::operator * (jablko3d::vect v, double k) {
	return jablko3d::vect(v.x * k, v.y * k, v.z * k);
}

jablko3d::vect jablko3d::cross_product(jablko3d::vect a, jablko3d::vect b) {
	double x = a.y * b.z - a.z * b.y;
    double y = -1 * (a.x * b.z - a.z * b.x);
    double z = a.x * b.y - a.y * b.x;
    return jablko3d::vect(x, y, z);
}

double jablko3d::dot_product(jablko3d::vect a, jablko3d::vect b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
