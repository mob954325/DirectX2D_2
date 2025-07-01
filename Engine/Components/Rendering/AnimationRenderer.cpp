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

		// NOTE : clip.loop 처리 안함
		//if (timer > maxtimer)
		if (timer >= clip.duration)
		{
			frameIndex = 0;
			timer = 0.0f;
			//frameIndex++;
			//frameIndex %= maxFrameIndex;
			//timer = 0.0f;
			//maxtimer = 0.4f; // test
			//if (frameIndex == 0)
			//{
			//	maxtimer = clip.frames[frameIndex].duration;
			//}
			//else
			//{
			//	maxtimer = clip.frames[frameIndex - 1].duration - clip.frames[frameIndex].duration;
			//}
		}

		if (frameIndex < clip.frames.size() && timer >= clip.frames[frameIndex].duration)
		{
			frameIndex++;
		}
	}

	Camera* pCam = Singleton<SceneManager>::GetInstance().GetMainCamera();
	D2D1_MATRIX_3X2_F mainCamInvertMatrix = pCam ? pCam->GetInvertMatrix() : D2D1::Matrix3x2F::Identity();

	// 최종 변환 값 계산
	if (owner->transform->IsUnityCoords())
	{
		finalMatrix =
			unityRenderMatrix *					// Render Matrix
			owner->transform->ToWorldMatrix() *	// m_transform world matrix 
			mainCamInvertMatrix *				// MainCamera invert matrix
			unityCoordMatrix;					// unity coord Matrix
	}
	else
	{
		finalMatrix =
			normalRenderMatrix *				// Render Matrix
			owner->transform->ToWorldMatrix() *	// m_transform world matrix 
			mainCamInvertMatrix;				// MainCamera invert matrix	
	}

	manager->SetBitmapTransform(finalMatrix);

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