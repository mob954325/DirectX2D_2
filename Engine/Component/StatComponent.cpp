#include "StatComponent.h"

std::function<void(int)> StatComponent::GetValueFunctionObject()
{
	return std::bind(&StatComponent::ChangeStat, this, std::placeholders::_1);
}

void StatComponent::ChangeStat(int value)
{
	statValue = value;
}