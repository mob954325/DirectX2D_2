#include "BoxComponent.h"
#include "D2DRenderManager.h"
#include "GameObject.h"

void BoxComponent::OnStart()
{
	renderManager->CreateBrush(D2D1::ColorF::Green, &brush);
}

void BoxComponent::OnDestroy()
{
	if (brush)
	{
		brush->Release();
	}
}

void BoxComponent::Render(D2DRenderManager* render)
{
	if (!isShow) return;

	if (brush)
	{
		if (owner->transform->IsUnityCoords())
		{
			// NOTE : 나중에 좌표값 수정할 것
			render->DrawRectangle(rect, brush, width, strokeStyle);
		}
		else
		{
			render->DrawRectangle(rect, brush, width, strokeStyle);
		}
	}
}

void BoxComponent::SetRect(D2D1_RECT_F rect)
{
	this->rect = rect;
}

void BoxComponent::SetWidth(FLOAT width)
{
	this->width = width;
}

void BoxComponent::SetStyle(ID2D1StrokeStyle* style)
{
	this->strokeStyle = style;
}

void BoxComponent::SetIsShow(bool value)
{
	isShow = value;	
}
