#pragma once
#include "Datas/AnimationControllerDatas.h"
#include "Resources/Loaders/AnimationControllerLoader.h"
#include "Components/Logic/ScriptComponent.h"

class Animator : public ScriptComponent
{
private:
	AnimatorController ac{};
public:
	void Update() override;

	void SetAnimationController(const std::wstring& filePath);

};

