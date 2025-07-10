#include "AABB.h"
#include "Components/Base/GameObject.h"

void AABB::FixedUpdate(const std::vector<Collision> others)
{
	for (auto it = others.begin(); it != others.end(); it++)
	{

	}
}

void AABB::OnCreate()
{
	box = owner->AddComponent<BoxComponent>();
}

void AABB::SetSize(float width, float height, float size)
{
	this->width = width;
	this->height = height;
	this->size = size; 

	if (box != nullptr)
	{
		D2D1_VECTOR_2F posVec = owner->transform->GetPosition();
		box->SetRect
		({
			posVec.x - width / 2 * size,
			posVec.y - height / 2 * size ,
			posVec.x + width / 2 * size ,
			posVec.y + height / 2 * size
		});

	}
}