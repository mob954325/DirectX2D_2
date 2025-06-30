#pragma once
#include <functional>
#include "Components/Base/Component.h"

class StatComponent : public Component
{
public:
	StatComponent() = default;
	~StatComponent() = default;

	int GetValue() { return statValue; }

	std::function<void(int)> GetValueFunctionObject();
	void ChangeStat(int value);
private:
	int statValue = 0;
};