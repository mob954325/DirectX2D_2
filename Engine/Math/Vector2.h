#pragma once
#include <float.h>
#include <math.h>


struct Vector2
{
	float x, y;

	Vector2(float valueX, float valueY);
	Vector2(int valueX, int valueY);

	static const Vector2& Down();
	static const Vector2& Left();
	static const Vector2& One();
	static const Vector2& Right();
	static const Vector2& Up();
	static const Vector2& Zero();

	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);

	Vector2 operator*(float other);
	Vector2 operator*(int other);
	Vector2 operator*(float other) const;
	Vector2 operator*(int other) const;

	Vector2 operator/(float other);
	Vector2 operator/(int other);
	Vector2 operator/(float other) const;
	Vector2 operator/(int other) const;

	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);

	bool IsZero();
	float Dot(const Vector2& other);
	Vector2	Lerp(Vector2& start, Vector2& end, float t);
	float Megnituede();
	float SqrMegnitude();
	Vector2 Normalize();
};