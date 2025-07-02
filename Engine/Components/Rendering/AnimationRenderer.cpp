#include "AnimationRenderer.h"
#include "Components/Camera/Camera.h"
#include "Scene/SceneManager.h"

#include "Utils/GameTime.h"
#include "Utils/JsonUtil.h"
#include "Utils/DebugUtility.h"

void AnimationRenderer::Render(D2DRenderManager* manager)
{
	if (!m_bitmapResource) return;

	if (isPlay)
	{
		timer += Singleton<GameTime>::GetInstance().GetDeltaTime();

		if (clip.loop && timer >= clip.duration)
		{
			frameIndex = 0;
			timer = 0.0f;
		}

		if (frameIndex < clip.frames.size() && timer >= clip.frames[frameIndex].duration)
		{
			frameIndex++;
		}
	}
	
	// 출력할 최종 위치 설정
	CalculateFinalMatrix();
	manager->SetBitmapTransform(finalMatrix);

	// Spirte 정보에 맞게 위치 조정
	Sprite currSprite = sheet.sprites[frameIndex];
	float pivotOffsetX = currSprite.width * currSprite.pivotX;
	float pivotOffsetY = currSprite.height * currSprite.pivotY;
	destRect =
	{
		0 - pivotOffsetX,
		0 - pivotOffsetY,
		currSprite.width - pivotOffsetX,
		currSprite.height - pivotOffsetY
	};

	float invertedY = sheet.textureHeight - currSprite.y - currSprite.height;
	srcRect =
	{
		currSprite.x,
		invertedY,
		currSprite.x + currSprite.width,
		invertedY + currSprite.height
	};

	{
		manager->DrawBitmap(m_bitmapResource.get()->GetBitmap(), destRect, srcRect);
	}
}

void AnimationRenderer::GetSpriteSheet(std::wstring filePath)
{
	JsonUtil::LoadSpriteSheet(filePath, sheet);
}

void AnimationRenderer::GetAnimationClip(std::wstring filePath)
{
	if (sheet.texture == L"")
	{
		throw std::runtime_error("Fail to open animation clip file, sheet is empty");
	}
	else
	{
		JsonUtil::LoadAnimationClip(filePath, clip, sheet);
		maxFrameIndex = clip.frames.size();
	}
}