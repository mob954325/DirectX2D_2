#pragma once
#include "Components/Rendering/RenderComponent.h"

// NOTE: 나중에 클래스명을 RectRendererComponent로 바꾸기
class BoxComponent : public RenderComponent
{
public:
	void OnStart() override;
	void OnDestroy() override;

	void Render(D2DRenderManager* render) override;
	void SetRect(D2D1_RECT_F rect);
	void SetWidth(FLOAT width);
	void SetStyle(ID2D1StrokeStyle* style);
	void SetIsShow(bool value);


private:
	D2D1_MATRIX_3X2_F unityCoordMatrix = D2D1::Matrix3x2F::Identity();
	D2D1_MATRIX_3X2_F normalRenderMatrix = D2D1::Matrix3x2F::Scale(1.0f, 1.0f) * D2D1::Matrix3x2F::Translation(offsetX, offsetY);
	D2D1_MATRIX_3X2_F unityRenderMatrix = D2D1::Matrix3x2F::Scale(1.0f, -1.0f) * D2D1::Matrix3x2F::Translation(offsetX, offsetY);
	D2D1_MATRIX_3X2_F finalMatrix = {};

	D2D1_POINT_2F MatrixTransform(const D2D1_POINT_2F& point, const D2D1_MATRIX_3X2_F& matrix);

	D2D1_RECT_F rect{};

	ID2D1SolidColorBrush* brush{};
	FLOAT width = 1.0f;
	ID2D1StrokeStyle* strokeStyle = (ID2D1StrokeStyle*)0;

	bool isShow = false;

	float offsetX = 0.0f;
	float offsetY = 0.0f;
};

