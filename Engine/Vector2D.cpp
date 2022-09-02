#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D(float in_x, float in_y)
{
	x = in_x;
	y = in_y;
}

float Vector2D::GetLength() const
{
	return std::sqrt(GetLengthSq());
}

float Vector2D::GetLengthSq() const
{
	return x * x + y * y;
}

Vector2D& Vector2D::Normalize()
{
	return *this = GetNormalized();
}

Vector2D Vector2D::GetNormalized() const
{
	const float len = GetLength();
	if (len != 0.0f)
	{
		return *this * (1.0f / len);
	}
	return *this;
}

bool Vector2D::operator==(const Vector2D& rhs) const
{
	if (x == rhs.x && y == rhs.y)
	{
		return true;
	}
	return false;
}

bool Vector2D::operator!=(const Vector2D& rhs) const
{
	if (x != rhs.x && y != rhs.y)
	{
		return true;
	}
	return false;
}

Vector2D Vector2D::operator+(const Vector2D& rhs) const
{
	return Vector2D(x + rhs.x, y + rhs.y);
}

Vector2D& Vector2D::operator+=(const Vector2D& rhs)
{
	return *this = *this + rhs;
}

Vector2D Vector2D::operator-(const Vector2D& rhs) const
{
	return Vector2D(x - rhs.x, y - rhs.y);
}

Vector2D& Vector2D::operator-=(const Vector2D& rhs)
{
	return *this = *this - rhs;
}

Vector2D Vector2D::operator*(const float rhs) const
{
	return Vector2D(x * rhs, y * rhs);
}

Vector2D& Vector2D::operator*=(const float rhs)
{
	return *this = *this * rhs;
}
