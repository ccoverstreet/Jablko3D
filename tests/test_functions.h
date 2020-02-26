// Jablko3D Geometry Library: Test Functions
// Cale Overstreet
// February 26, 2020
// Contains functions for evaluating conditions in unit tests: particulary double comparisions

bool double_equals(double a, double b, double epsilon) {
	return std::abs(a - b) < epsilon;
}
