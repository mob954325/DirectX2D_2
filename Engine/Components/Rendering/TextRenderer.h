#pragma once
#include "Components/Base/Component.h"
#include "Components/Rendering/RenderComponent.h"
#include <string>

class TextRenderer : public RenderComponent
{
public:
	void Render(D2DRenderManager* manager) override;

	void SetText(const std::wstring& text);
	void SetPosition(float left, float top);

private:
	std::wstring text;
	float left = 0.0f;
	float top = 0.0f;
};

