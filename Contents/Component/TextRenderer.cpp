#include "TextRenderer.h"
#include "Core/D2DRenderManager.h"

void TextRenderer::Render(D2DRenderManager* manager)
{
	manager->PrintText(text.c_str(), left, top);
}

void TextRenderer::SetText(const std::wstring& text)
{
	this->text = text;
}

/// <summary>
/// 좌측 상단을 0,0으로 한 위치 값 설정
/// </summary>
/// <param name="left">x값</param>
/// <param name="top">y값</param>
void TextRenderer::SetPosition(float left, float top)
{
	this->left = left;
	this->top = top;
}
