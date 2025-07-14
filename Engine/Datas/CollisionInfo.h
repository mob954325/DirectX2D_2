#pragma once
#include "Components/Base/GameObject.h"
#include "Math/Vector2.h"

struct CollisionInfo
{
	GameObject* a;
	GameObject* b;
	Vector2 normal; // 충돌한 방향
	float penetrationDepth; // 침투 깊이
};