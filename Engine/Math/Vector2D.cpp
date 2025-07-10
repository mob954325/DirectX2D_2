#include "Vector2D.h"

const Vector2D& Vector2D::Down()
{
	static const Vector2D down(0.0f, -1.0f);
	return down;
}

const Vector2D& Vector2D::Left()
{	
	static const Vector2D left(0.0f, -1.0f);
	return left;
}

const Vector2D& Vector2D::One()
{
	static const Vector2D one(0.0f, -1.0f);
	return one;
}

const Vector2D& Vector2D::Right()
{
	static const Vector2D right(0.0f, -1.0f);
	return right;	
}

const Vector2D& Vector2D::Up()
{
	static const Vector2D up(0.0f, -1.0f);
	return up;	
}

const Vector2D& Vector2D::Zero()
{
	static const Vector2D zero(0.0f, -1.0f);
	return zero;	
}
