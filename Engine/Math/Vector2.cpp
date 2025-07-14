#include "Vector2.h"

Vector2::Vector2(float valueX, float valueY)
{
	x = valueX;
	y = valueY;
}

Vector2::Vector2(int valueX, int valueY)
{
	x = (float)valueX;
	y = (float)valueY;
}

const Vector2& Vector2::Down()
{
	static const Vector2 down(0.0f, -1.0f);
	return down;
}

const Vector2& Vector2::Left()
{
	static const Vector2 left(-1.0f, 0.0f);
	return left;
}

const Vector2& Vector2::One()
{
	static const Vector2 one(1.0f, 1.0f);
	return one;
}

const Vector2& Vector2::Right()
{
	static const Vector2 right(1.0f, 0.0f);
	return right;
}

const Vector2& Vector2::Up()
{
	static const Vector2 up(0.0f, 1.0f);
	return up;
}

const Vector2& Vector2::Zero()
{
	static const Vector2 zero(0.0f, 0.0f);
	return zero;
}

Vector2 Vector2::operator+(const Vector2& other)
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other)
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(float other)
{
	return Vector2(x * other, y * other);
}

Vector2 Vector2::operator*(int other)
{
	return Vector2(x * other, y * other);
}

Vector2 Vector2::operator/(float other)
{
	return Vector2(x / other, y / other);
}

Vector2 Vector2::operator/(int other)
{
	return Vector2(x / other, y / other);
}

Vector2& Vector2::operator+=(const Vector2& other)
{
	x += other.x; y += other.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& other)
{
	x -= other.x; y -= other.y;
	return *this;
}

Vector2 operator*(float scalar, const Vector2& vec) // float * vector
{
	return Vector2(vec.x * scalar, vec.y * scalar);
}

Vector2 operator*(int scalar, const Vector2& vec) // int * vector
{
	return Vector2(vec.x * scalar, vec.y * scalar);
}

bool Vector2::IsZero()
{
	return x < FLT_EPSILON + 1.1e-13f && y < FLT_EPSILON + 1.1e-13f;
}

float Vector2::Dot(const Vector2& other)
{
	return x * other.x + y * other.y;
}

float Vector2::Megnituede()
{
	return sqrt(x * x + y * y);
}

float Vector2::SqrMegnitude()
{
	return x * x + y * y;
}

Vector2 Vector2::Normalize()
{
	float len = len = Megnituede();
	if (len < FLT_EPSILON) // or Len == 0
		return Vector2(0.0f, 0.0f);

	return Vector2(x / Megnituede(), y / Megnituede());
}

Vector2	Vector2::Lerp(Vector2& start, Vector2& end, float t)
{
	Vector2 lerpVec = (1.0f - t) * start + t * end;
	return lerpVec;
}
