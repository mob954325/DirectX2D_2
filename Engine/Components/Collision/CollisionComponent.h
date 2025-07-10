#pragma once
#include "Components/Base/Component.h"

struct Bounds
{
	// vector3 center;	// bounding box의 중앙
	// vector3 extents;	// bounding box의 범위 -> 항상 bounds 크기의 절반 값
};

class Collision : public Component
{
public:
	virtual void FixedUpdate(const std::vector<Collision>& others) = 0;

	void SetTrigger(bool value);
	bool IsTrigger();
private:
	bool isTrigger = false;
};