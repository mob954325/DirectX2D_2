#pragma once
#include "Base/RenderComponent.h"

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
	D2D1_RECT_F rect{};
	ID2D1SolidColorBrush* brush{};
	FLOAT width = 1.0f;
	ID2D1StrokeStyle* strokeStyle = (ID2D1StrokeStyle*)0;

	bool isShow = false;
};

