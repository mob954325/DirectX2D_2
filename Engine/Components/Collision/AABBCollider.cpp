#include "AABBCollider.h"
#include "Components/Base/GameObject.h"

AABBCollider::AABBCollider()
{
	collider = this;
	type = ColliderType::AABB;
}

void AABBCollider::FixedUpdate(const std::vector<CollisionComponent*>& others, std::vector<CollisionInfo>& outInfos)
{
	for (auto it = others.begin(); it != others.end(); it++)
	{
		if ((*it)->owner == this->owner)
		{
			continue;
		}

		ICollider* other = dynamic_cast<ICollider*>((*it)->collider);
		if (other == nullptr)
		{
			continue;
		}

		if (CheckCollision(other))
		{
			std::cout << " ----- " << (*it)->owner->GetName() << ", " << this->owner->GetName() << "충돌됨" << std::endl;

			// TODO: outinfos push_back 하기
		}
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
	case AABB:
		return CheckCollisionWithAABB(other);
	default:
		break;
	}

	return false;
}

bool AABBCollider::CheckCollisionWithAABB(ICollider* other) const
{
	AABBCollider* otherAABB = static_cast<AABBCollider*>(other);
	if (!otherAABB) return false;

	Vector2 aCenter = GetCenter();
	Vector2 bCenter = otherAABB->GetCenter();
	D2D1_RECT_F aRect = GetSize();
	D2D1_RECT_F bRect = otherAABB->GetSize();

	float aMinX = aCenter.x + aRect.left;
	float aMaxX = aCenter.x + aRect.right;
	float aMinY = aCenter.y + aRect.bottom;
	float aMaxY = aCenter.y + aRect.top;

	float bMinX = bCenter.x + bRect.left;
	float bMaxX = bCenter.x + bRect.right;
	float bMinY = bCenter.y + bRect.bottom;
	float bMaxY = bCenter.y + bRect.top;

	bool isColliding =
		(aMinX < bMaxX) &&
		(aMaxX > bMinX) &&
		(aMinY < bMaxY) &&
		(aMaxY > bMinY);

	return isColliding;
}

void AABBCollider::OnCreate()
{
	box = owner->AddComponent<BoxComponent>();
}

void AABBCollider::SetSize(float width, float height, float scale)
{
	this->width = width;
	this->height = height;
	this->size = scale;

	if (box != nullptr)
	{
		D2D1_VECTOR_2F posVec = owner->transform->GetPosition();
		box->SetRect
		({
			posVec.x - width / 2 * scale,
			posVec.y - height / 2 * scale ,
			posVec.x + width / 2 * scale ,
			posVec.y + height / 2 * scale
		});

	}
}

D2D1_RECT_F AABBCollider::GetSize() const
{
	D2D1_RECT_F rect{};
	Vector2 centerVec = GetCenter();
	if (owner->transform->IsUnityCoords())
	{
		rect =
		{
			centerVec.x - width * 0.5f,
			centerVec.y + height * 0.5f,
			centerVec.x + width * 0.5f,
			centerVec.y - height * 0.5f
		};
	}
	else
	{
		rect =
		{
			centerVec.x,
			centerVec.y,
			centerVec.x + width,
			centerVec.y + height
		};
	}

	return rect;
}
