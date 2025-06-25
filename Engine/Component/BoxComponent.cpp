#include "BoxComponent.h"
#include "D2DRenderManager.h"
#include "GameObject.h"
#include "EngineData.h"

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

			// NOTE : 유니티 좌표계 추가 계산 후 경계 확인하기
			render->DrawRectangle(rect, brush, width, strokeStyle);
			float topGap = rect.bottom - rect.top;
			D2D1_RECT_F unityRect =
			{
				rect.left + (EngineData::SceenWidth / 2),
				rect.top + (EngineData::SceenHeight / 2),
				rect.right + (EngineData::SceenWidth / 2),
				rect.bottom + (EngineData::SceenHeight / 2)
			};
			render->DrawRectangle(rect, brush, width, strokeStyle);
		}
		else
		{
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
