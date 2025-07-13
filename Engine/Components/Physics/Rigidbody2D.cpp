#include "Rigidbody2D.h"
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
	if (!isKinematic)
	{
		if (useGravity)
		{
			accelration += gravity;
		}

		velocity += accelration * Singleton<GameTime>::GetInstance().GetDeltaTime();		// ���ӵ� ���
		Vector2 deltaPos = velocity * Singleton<GameTime>::GetInstance().GetDeltaTime();	// transform�� �ݿ��� ��

		D2D1_VECTOR_2F d2d1Vec = { deltaPos.x, deltaPos.y };
		owner->transform->Translate(d2d1Vec);
		accelration = Vector2::Zero();
	}
}