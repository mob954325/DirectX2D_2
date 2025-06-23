#include "AnimationRenderer.h"
#include "Camera.h"
#include "SceneManager.h"

#include "GameTime.h"

void AnimationRenderer::Render(D2DRenderManager* manager)
{
	if (!m_bitmap) return;

	if (isPlay)
	{
		timer += Singleton<GameTime>::GetInstance().GetDeltaTime();

		if (timer > maxtimer)
		{
			timer = 0.0f;
			frame++;
			frame %= maxFrame;
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

	D2D1_RECT_F destRect = { 0,0, (FLOAT)frameWidth, (FLOAT)frameHeight };

	int currFrame = frame % maxFrame;
	int indexX = currFrame % rowCount;
	int indexY = currFrame / rowCount;

	D2D1_RECT_F srcRect = 
	{ 
		(FLOAT)(indexX * frameWidth),
		(FLOAT)(indexY * frameHeight),
		(FLOAT)((indexX + 1) * frameWidth),
		(FLOAT)((indexY + 1) * frameHeight)
	};

	manager->DrawBitmap(m_bitmap, destRect, srcRect);
}

void AnimationRenderer::SetFrameSize(int imageWidth, int imageHeight)
{
	frameWidth = imageWidth;
	frameHeight = imageHeight;
}

void AnimationRenderer::SetFrameCount(int countX, int countY)
{
	rowCount = countX;
	columnCount = countY;

	maxFrame = rowCount * columnCount;
}
