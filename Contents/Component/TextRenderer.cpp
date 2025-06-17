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

void TextRenderer::SetPosition(float left, float top)
{
	this->left = left;
	this->top = top;
}
