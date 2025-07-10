#pragma once

struct Vector2D
{
	Vector2D() { x = 0, y = 0; }
	Vector2D(int x, int y) { this->x = static_cast<float>(x); this->y = static_cast<float>(y); }
	Vector2D(float x, float y) { this->x = x; this->y = y; }

	static const Vector2D& Down();
	static const Vector2D& Left();
	static const Vector2D& One();
	static const Vector2D& Right();
	static const Vector2D& Up();
	static const Vector2D& Zero();

	// magnitued
	// normalize
	// sqrmagnitued
	// distance
	// dot
	// lerp
	// 연산자 - * / + == 

	float x;
	float y;
};