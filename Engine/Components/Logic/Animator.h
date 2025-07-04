#pragma once
#include "Datas/AnimationControllerDatas.h"
#include "Resources/Loaders/AnimationControllerLoader.h"
#include "Components/Logic/ScriptComponent.h"

class Animator : public ScriptComponent
{
private:
	AnimatorController ac{};
	State* currentState = nullptr;

	// Param getter/setter
	int GetIntParameter(std::string paramName);
	void SetIntParamter(std::string paramName, int value);

	bool GetBoolParameter(std::string paramName);
	void SetBoolParameter(std::string paramName, bool value);

	float GetFloatParameter(std::string paramName);
	void SetFloatParameter(std::string paramName, float value);

public:
	void Update() override;
	void SetAnimationController(const std::wstring& filePath);
};

