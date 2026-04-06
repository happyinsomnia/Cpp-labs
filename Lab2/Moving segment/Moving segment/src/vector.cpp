#include "vector.hpp"

geometry::Vector2f::Vector2f() = default;

constexpr geometry::Vector2f::Vector2f(float x, float y) : x(x), y(y) {}

geometry::Vector2f geometry::Vector2f::operator+(const Vector2f& other) const noexcept
{
	return Vector2f(x + other.x, y + other.y);
}

geometry::Vector2f geometry::Vector2f::operator-(const Vector2f& other) const noexcept
{
	return Vector2f(x - other.x, y - other.y);
}

geometry::Vector2f& geometry::Vector2f::operator+=(const Vector2f& other) noexcept
{
	x += other.x;
	y += other.y;

	return *this;
}

geometry::Vector2f& geometry::Vector2f::operator-=(const Vector2f& other) noexcept
{
	x -= other.x;
	y -= other.y;

	return *this;
}

geometry::Vector2f& geometry::Vector2f::operator=(const Vector2f& other) = default;

bool geometry::Vector2f::operator==(const Vector2f& other) const noexcept
{
	return x == other.x && y == other.y;
}

bool geometry::Vector2f::operator!=(const Vector2f& other) const noexcept
{
	return !(*this == other);
}