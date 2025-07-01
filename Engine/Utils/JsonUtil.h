#pragma once
#include "Resources/SpriteDatas.h"

namespace JsonUtil
{
	void LoadSpriteSheet(const std::wstring& filePath, SpriteSheet& spriteSheet);
	void LoadAnimationClip(const std::wstring& filePath, AnimationClip& clip, const SpriteSheet& spriteSheet);
}