#pragma once

#include <cmath>

struct Vector2
{
	bool operator==(const Vector2& other) const = default;

	double x;
	double y;

	double length() const
	{
		return std::sqrt(x * x + y * y);
	}

	double lengthSquared() const
	{
		return x * x + y * y;
	}

	Vector2 operator+(const Vector2& vec) const
	{
		return { x + vec.x, y + vec.y };
	}

	Vector2 operator-(const Vector2& vec) const
	{
		return { x - vec.x, y - vec.y };
	}

	Vector2 operator*(const double multiplier) const
	{
		return { x * multiplier, y * multiplier };
	}
};