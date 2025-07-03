#include "Animator.h"

void Animator::Update()
{
	// Update 내용 
}

void Animator::SetAnimationController(const std::wstring& filePath)
{
	AnimationControllerLoader::LoadAnimatorController(filePath, ac);
}
