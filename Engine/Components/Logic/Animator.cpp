#include "Animator.h"
#include "Utils/DebugUtility.h"

void Animator::Update()
{
	// Update 내용 
	DebugUtility::Print(currentState->name);
}

void Animator::SetAnimationController(const std::wstring& filePath)
{
	AnimationControllerLoader::LoadAnimatorController(filePath, ac);
	currentState = ac.GetState(ac.defaultState);
}
