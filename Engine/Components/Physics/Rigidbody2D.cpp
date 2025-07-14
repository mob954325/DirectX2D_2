﻿#include "Rigidbody2D.h"
#include "Utils/Singleton.h"
#include "Utils/GameTime.h"
#include "Components/Base/GameObject.h"

void Rigidbody2D::FixedUpdate()
{
	Intergrate();
}

void Rigidbody2D::SetKinematic(bool value)
{
	isKinematic = value;
}

void Rigidbody2D::SetGravity(bool value)
{
	useGravity = value;
}

void Rigidbody2D::ApplyForce(const Vector2& forceVec)
{
	accelration = forceVec;
}

void Rigidbody2D::Intergrate()
{
	// NOTE: 적용 시 왠지는 모르겠는데 TestColliderScene에서 모든 오브젝트가 움직임 ?
	if (!isKinematic)
	{
		if (useGravity)
		{
			accelration += gravity;
		}

		velocity += accelration * Singleton<GameTime>::GetInstance().GetDeltaTime();		// 가속도 계산
		Vector2 deltaPos = velocity * Singleton<GameTime>::GetInstance().GetDeltaTime();	// transform에 반영할 값

		D2D1_VECTOR_2F d2d1Vec = { deltaPos.x, deltaPos.y };
		owner->transform->Translate(d2d1Vec);
		accelration = Vector2::Zero();
	}
}