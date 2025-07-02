#pragma once
#include "Application/Application.h"
#include "Components/Base/Component.h"
#include "Components/Rendering/RenderComponent.h"
#include "Components/Base/Transform.h"
#include "Resources/BitmapResource.h"

class BitmapRenderer : public RenderComponent
{
public:
	BitmapRenderer() {};
	~BitmapRenderer() {};

	void Render(D2DRenderManager* manager) override;
	void OnStart() override;
	void OnDestroy() override;

	void CreateBitmapResource(std::wstring filePath);
	void SetScreenSize(int width, int height);
	void SetOffSet(float x, float y);

	std::shared_ptr<BitmapResource> GetResource();

protected:
	void CalculateFinalMatrix();

	D2D1_MATRIX_3X2_F unityCoordMatrix = D2D1::Matrix3x2F::Identity(); // 유니티 좌표 전환 메트릭스
	D2D1_MATRIX_3X2_F normalRenderMatrix = D2D1::Matrix3x2F::Scale(1.0f, 1.0f) * D2D1::Matrix3x2F::Translation(offsetX, offsetY);
	D2D1_MATRIX_3X2_F unityRenderMatrix = D2D1::Matrix3x2F::Scale(1.0f, -1.0f) * D2D1::Matrix3x2F::Translation(offsetX, offsetY);

	std::shared_ptr<BitmapResource> m_bitmapResource;
	D2D1_RECT_F destRect = {};
	D2D1_MATRIX_3X2_F finalMatrix = {};

	int screenWidth = 0;
	int screenHeight = 0;
	float offsetX = 0.0f;
	float offsetY = 0.0f;

	float timer = 0;
	float maxtimer = 0.2f;
};

