#include "CollisionComponent.h"

void Collision::SetTrigger(bool value)
{
	isTrigger = value;
}

bool Collision::IsTrigger()
{
	return isTrigger;
}
