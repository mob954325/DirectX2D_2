#include "AABBCollider.h"
#include "Components/Base/GameObject.h"

void AABBCollider::FixedUpdate(const std::vector<CollisionComponent>& others)
{
	for (auto it = others.begin(); it != others.end(); it++)
	{

	}
}

ColliderType AABBCollider::GetColliderType()
{
	return type;
}

Vector2 AABBCollider::GetCenter() const
{
	return Vector2(owner->transform->GetPosition().x, owner->transform->GetPosition().y);
}

bool AABBCollider::CheckCollision(ICollider* other) const
{
	ColliderType type = other->GetColliderType();
	switch (type)
	{
	case Circle:
		break;
	case AABBCollider:
		break;
	default:
		break;
	}

	return false;
}

void AABBCollider::OnCreate()
{
	box = owner->AddComponent<BoxComponent>();
}

void AABBCollider::SetSize(float width, float height, float size)
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