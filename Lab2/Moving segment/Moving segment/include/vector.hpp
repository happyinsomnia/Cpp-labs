#pragma once
#pragma once

namespace geometry
{
	class Vector2f
	{
	public:

		float x = 0;
		float y = 0;

		Vector2f();
		constexpr Vector2f(float x, float y);

		Vector2f operator+(const Vector2f& other) const noexcept;
		Vector2f operator-(const Vector2f& other) const noexcept;
		Vector2f& operator+=(const Vector2f& other) noexcept;
		Vector2f& operator-=(const Vector2f& other) noexcept;
		Vector2f& operator=(const Vector2f& other);
		bool operator==(const Vector2f& other) const noexcept;
		bool operator!=(const Vector2f& other) const noexcept;
	};
}