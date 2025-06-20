#pragma once
#include "Core/Application.h"
#include "Base/Component.h"
#include "Base/RenderComponent.h"
#include "Base/Transform.h"

class BitmapRenderer : public RenderComponent
{
public:
	BitmapRenderer() {};
	~BitmapRenderer() {};

	void Render(D2DRenderManager* manager) override;
	void OnStart() override;
	void OnDestroy() override;


	void CreateBitMap(const wchar_t* path);
	void SetScreenSize(int width, int height);
	void SetOffSet(float x, float y);

	Microsoft::WRL::ComPtr<ID2D1Bitmap1> GetBitmap();

protected:
	//D2D1::Matrix3x2F GetRenderMatrix(Transform* transform);

	D2D1_MATRIX_3X2_F unityCoordMatrix = D2D1::Matrix3x2F::Identity(); // 유니티 좌표 전환 메트릭스
	D2D1_MATRIX_3X2_F normalRenderMatrix = D2D1::Matrix3x2F::Scale(1.0f, 1.0f) * D2D1::Matrix3x2F::Translation(offsetX, offsetY);
	D2D1_MATRIX_3X2_F unityRenderMatrix = D2D1::Matrix3x2F::Scale(1.0f, -1.0f) * D2D1::Matrix3x2F::Translation(offsetX, offsetY);

	Microsoft::WRL::ComPtr<ID2D1Bitmap1> m_bitmap;
	D2D1_RECT_F destRect = {};
	D2D1_MATRIX_3X2_F finalMatrix = {};

	Microsoft::WRL::ComPtr<ID2D1Effect> m_skewEffect;
	Microsoft::WRL::ComPtr<ID2D1Effect> m_shadowEffect;

	int screenWidth = 0;
	int screenHeight = 0;
	float offsetX = 0.0f;
	float offsetY = 0.0f;
};

