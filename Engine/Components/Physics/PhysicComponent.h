#pragma once
#include "Components/Base/Component.h"

class PhysicComponent : public Component
{
public:
	virtual void FixedUpdate() = 0;
};