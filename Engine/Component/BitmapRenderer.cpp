#include "BitmapRenderer.h"
#include "Core/D2DRenderManager.h"
#include "Base/GameObject.h"
#include "Utility/SceneManager.h"
#include "Core/ResourceManager.h"
#include "Camera.h"
#include "EngineData.h"
#include "BitmapResource.h"

void BitmapRenderer::Render(D2DRenderManager* manager)
{
	if (m_bitmapResource != nullptr) // m_bitmap 사용하면 터짐
	{
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
		manager->DrawBitmap(m_bitmapResource.get()->GetBitmap());
	}
}

void BitmapRenderer::OnStart()
{
	// 유니티 좌표 매트릭스를 위한 스크린크기 불러오기
	screenWidth = EngineData::SceenWidth;
	screenHeight = EngineData::SceenHeight;
	unityCoordMatrix = D2D1::Matrix3x2F::Scale(1.0f, -1.0f) * D2D1::Matrix3x2F::Translation((FLOAT)(screenWidth / 2), (FLOAT)(screenHeight / 2));
}

void BitmapRenderer::OnDestroy()
{
	m_bitmapResource.reset();
}

void BitmapRenderer::CreateBitmapResource(std::wstring filePath)
{
	m_bitmapResource = resourceManager->CreateBitmapResource(filePath);
}

void BitmapRenderer::SetScreenSize(int width, int height)
{
	screenWidth = width; screenHeight = height;
	unityCoordMatrix = D2D1::Matrix3x2F::Scale(1.0f, -1.0f) * D2D1::Matrix3x2F::Translation((FLOAT)(screenWidth / 2), (FLOAT)(screenHeight / 2));
}

void BitmapRenderer::SetOffSet(float x, float y)
{
	offsetX = x; offsetY = y;

	normalRenderMatrix = D2D1::Matrix3x2F::Scale(1.0f, 1.0) * D2D1::Matrix3x2F::Translation(offsetX, -offsetY);
	unityRenderMatrix = D2D1::Matrix3x2F::Scale(1.0f, -1.0f) * D2D1::Matrix3x2F::Translation(offsetX, offsetY);
}

std::shared_ptr<BitmapResource> BitmapRenderer::GetResource()
{
	return m_bitmapResource;
}
