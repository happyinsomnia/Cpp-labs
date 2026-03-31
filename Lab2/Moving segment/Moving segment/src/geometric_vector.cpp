#include "geometric_vector.hpp"

namespace segment::geometry
{
	GeometricVector::GeometricVector() : x{ 0 }, y{ 0 } {}

	GeometricVector::GeometricVector(float x, float y) : x{ x }, y{ y } {}

	GeometricVector GeometricVector::operator+(const GeometricVector& other)
	{
		return GeometricVector(x + other.x, y + other.y);
	}

	GeometricVector GeometricVector::operator-(const GeometricVector& other)
	{
		return GeometricVector(x - other.x, y - other.y);
	}
}