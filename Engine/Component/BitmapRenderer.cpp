#include "BitmapRenderer.h"
#include "Core/D2DRenderManager.h"
#include "Base/GameObject.h"
#include "Camera.h"
#include "Utility/SceneManager.h"


void BitmapRenderer::Render(D2DRenderManager* manager)
{
	if (m_bitmap != nullptr)
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

		//D2D1_RECT_F testRect{ 0, 0, 0, 0 };
		manager->DrawBitmap(m_bitmap);
	}
}

void BitmapRenderer::OnStart()
{
	// 유니티 좌표 매트릭스를 위한 스크린크기 불러오기
	D2D1_SIZE_U screenSize = Singleton<SceneManager>::GetInstance().GetScreenSize();
	screenWidth = (int)screenSize.width;
	screenHeight = (int)screenSize.height;
	unityCoordMatrix = D2D1::Matrix3x2F::Scale(1.0f, -1.0f) * D2D1::Matrix3x2F::Translation((FLOAT)(screenWidth / 2), (FLOAT)(screenHeight / 2));
}

void BitmapRenderer::OnDestroy()
{
	m_bitmap.Reset();
}

void BitmapRenderer::CreateBitMap(const wchar_t* path)
{
	HRESULT hr = renderManager->CreateBitmapFromFile(path, m_bitmap.GetAddressOf());
	assert(SUCCEEDED(hr));
}

void BitmapRenderer::SetScreenSize(int width, int height)
{
	screenWidth = width; screenHeight = height;
	unityCoordMatrix = D2D1::Matrix3x2F::Scale(1.0f, -1.0f) * D2D1::Matrix3x2F::Translation((FLOAT)(screenWidth / 2), (FLOAT)(screenHeight / 2));
}

void BitmapRenderer::SetOffSet(float x, float y)
{
	offsetX = x; offsetY = y;
	normalRenderMatrix = D2D1::Matrix3x2F::Scale(1.0f, 1.0f) * D2D1::Matrix3x2F::Translation(offsetX, offsetY);
	unityRenderMatrix = D2D1::Matrix3x2F::Scale(1.0f, -1.0f) * D2D1::Matrix3x2F::Translation(offsetX, -offsetY);
}

Microsoft::WRL::ComPtr<ID2D1Bitmap1> BitmapRenderer::GetBitmap()
{
	return m_bitmap;
}
