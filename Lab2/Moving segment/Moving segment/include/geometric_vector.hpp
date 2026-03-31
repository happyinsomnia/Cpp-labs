#pragma once

namespace segment::geometry
{
	class GeometricVector
	{
	public:
		GeometricVector();
		GeometricVector(float x, float y);

		GeometricVector operator+(const GeometricVector& other);
		GeometricVector operator-(const GeometricVector& other);
	private:
		float x;
		float y;
	};
}