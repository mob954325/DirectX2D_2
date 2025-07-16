#include "Rigidbody2D.h"
#include "Utils/Singleton.h"
#include "Utils/GameTime.h"
#include "Components/Base/GameObject.h"
#include <math.h>

void Rigidbody2D::FixedUpdate(std::vector<CollisionInfo>& collisions)
{
	std::vector<CollisionInfo> collapsed;

	for (const auto& info : collisions)
	{
		if (info.a == this->owner)
		{
			collapsed.push_back(info);
		}
	}

	Intergrate(collapsed);
}

void Rigidbody2D::SetPhysicsType(PhysicsType value)
{
	physicsType = value;
}

PhysicsType Rigidbody2D::GetPhysicsType()
{
	return physicsType;
}

void Rigidbody2D::SetGravity(bool value)
{
	useGravity = value;
}

void Rigidbody2D::ApplyForce(const Vector2& forceVec)
{
	if (mass <= minMassValue) return;

	// F = ma -> a = F / m
	accelration += forceVec / mass;
}

void Rigidbody2D::SetVelocity(const Vector2& vel)
{
	velocity = vel;
}

void Rigidbody2D::Intergrate(std::vector<CollisionInfo>& collisions)
{
	if (physicsType != PhysicsType::Static)
	{
		Vector2 adjustGravity = Vector2::Zero();
		if (physicsType == PhysicsType::Dynamic && useGravity)
		{
			adjustGravity = gravity;
		}

		// 충돌한 오브젝트 반응 계산
		if (!collisions.empty()) 
		{
			for (const auto& info : collisions)
			{
				Vector2 normal = info.normal;
			
				if(useGravity)
				{ 
					// 중력의 법선 성분 제거
					float gDotN = adjustGravity.Dot(normal);
					if (gDotN < 0)
					{
						adjustGravity -= normal * gDotN;
					}
				}

				if (physicsType == PhysicsType::Dynamic)
				{
					// velocity를 법선 방향으로 투영
					float vDotN = velocity.Dot(normal);

					// 탄성 없음
					// if (vDotN < 0) // 침투 방향일 때만 제거
					// {
					// 	velocity -= normal * vDotN; // 침투 방향 성분 제거 -> 정지 
					// }

					//// 탄성
					//float restitution = 0.5f; // 임시 : 반발(복원) 계수 - 얼마나 잘튀는지 나타내는 값
					//if (vDotN < 0) // 침투 방향일 때만 제거
					//{
					//	Vector2 impulse = -normal * (1 + restitution) * vDotN; // 탄성 테스트 코드
					//	velocity += impulse; // 침투 방향 성분 제거 -> 정지 
					//
					//	std::cout << "impulse : " << impulse.x << ", " << impulse.y << std::endl;
					//}

					// 마찰과 탄성
					if (vDotN < 0) // 침투 방향일 때만 제거
					{
						// 탄성 반응
						float restitution = 0.0f;	 // 탄성 계수
						Vector2 vn = normal * vDotN; // 탄성 속도 벡터
						Vector2 impulseT = -(1 + restitution) * vn;

						// 접선 벡터 구하기
						Vector2 vt = velocity - vn;			 // velocity의 접선 성분
						Vector2 tangent = vt.Normalize();	 // 접선 방향
						float vDotT = velocity.Dot(tangent); // 접속 속도 크기

						// 마찰 반응
						float friction = 1.0f;
						Vector2 impulseN = -friction * vDotT * tangent;

						// 최종 반응
						velocity += impulseN + impulseT;

						// std::cout << "impulseN: " << impulseN.x << ", " << impulseN.y << std::endl;
						// std::cout << "impulseT: " << impulseT.x << ", " << impulseT.y << std::endl;
					}
				}

				// 물체 밀어내기
				if (physicsType != PhysicsType::Static)
				{
					Rigidbody2D* bRigid = info.b->GetComponent<Rigidbody2D>();

					if (bRigid == nullptr) continue;
					if (bRigid->GetPhysicsType() != PhysicsType::Dynamic) continue;

					Vector2 pushDir = -info.normal;
					float force = 100000.0f;

					bRigid->ApplyForce(pushDir * force);
				}
			}

			// std::cout << "adjustGravity : " << adjustGravity.x << ", " << adjustGravity.y << std::endl;
		}

		velocity += adjustGravity; // 계산된 값 추가

		float deltaTime = 0.001f;

		if (physicsType == PhysicsType::Dynamic)
		{
			// 추가된 값 velocity에 반영
			velocity += accelration * deltaTime;

			// drag 추가 ( 충돌이랑 관련 없음 )
			velocity -= velocity * drag * deltaTime;

			std::cout << "velocity : " << velocity.x << ", " << velocity.y << std::endl;
		}

		// 이동 
		owner->transform->Translate(velocity * deltaTime);

		// 가속도 초기화
		accelration = Vector2::Zero();
	}
}

void Rigidbody2D::SetMass(float value)
{
	mass = value;

	if (mass <= minMassValue)
	{
		mass = 0.0f;
		physicsType = PhysicsType::Static;
		useGravity = false;
		std::cout << owner->GetName() << " -> " << "Warning: Mass set to 0. Converted to Static object." << std::endl;
	}
}

/// 물리 상태의 계산
/// 1. 힘 F를 구한다
/// 2. F = ma 이므로 힘 F를 안다면 가속도 a = F/m로 구할 수 있다
/// 3. dv/dt = a 이므로 가속도 a를 안다면 속도의 변화 dv = a dt로 구할 수 있다.
/// 4. dx/dt = v 이므로 속도 v를 알면 위치의 변화를 dx = v dt로 구할 수 있다.
/// -> 따라서 힘을 알면 시간에 대한 적분을 통해 가속도, 속도, 위치를 모두 구할 수 있다.

/// 물리 상태 갱신 절차
/// 1. 전체 힘을 구한다.
/// 2. 가속도를 계산한다. 힘을 질량으로 나누면 가속도를 얻을 수 있다.
/// 3. 속도를 갱신한다. 가속도에 dt를 곱한 값을 속도에 더하면 된다.
/// 4. 위치를 갱신한다. 속도에 dt를 곱한 값을 위치에 더하면된다
/// 응용에 따라서 네 절차 중에 부분적으로 생략하거나 변경할 수 있다.