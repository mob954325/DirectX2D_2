#pragma once
#include "Components/Physics/PhysicComponent.h"
#include "Math/Vector2.h"

/// <summary>
/// 2D ������Ʈ�� ���� ��� �ް� �Ǵ� ������Ʈ`
/// </summary>
class Rigidbody2D : public PhysicComponent
{
public:
	void FixedUpdate() override;

	void SetKinematic(bool value);
	void SetGravity(bool value);

	void ApplyForce(const Vector2& forceVec);
	void Intergrate();

private:
	Vector2 velocity{0,0};
	Vector2 accelration{0,0};

	const Vector2 gravity = { 0.0f, -9.81f }; // NOTE: �ӽ� ��

	float mass = 1.0f;
	bool useGravity = true;
	bool isKinematic = false;
};
