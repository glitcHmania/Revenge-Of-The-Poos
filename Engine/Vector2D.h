#pragma once
class Vector2D
{
public:
	Vector2D() = default;
	Vector2D(float in_x, float in_y);
	float GetLength() const;
	float GetLengthSq() const;
	Vector2D& Normalize();
	Vector2D GetNormalized() const;
	bool operator== (const Vector2D& rhs) const;
	bool operator!= (const Vector2D& rhs) const;
	Vector2D operator+ (const Vector2D& rhs) const;
	Vector2D& operator+= (const Vector2D& rhs);
	Vector2D operator- (const Vector2D& rhs) const;
	Vector2D& operator-= (const Vector2D& rhs);
	Vector2D operator* (const float rhs) const;
	Vector2D& operator*=(const float rhs);
	float x;
	float y;
};

