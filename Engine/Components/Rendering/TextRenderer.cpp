﻿#include "TextRenderer.h"
#include "Platform/D2DRenderManager.h"
#include "Datas/EngineData.h"

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

void TextRenderer::SetViewportPosition(float viewportX, float viewportY)
{
	float posX = EngineData::SceenWidth * viewportX;
	float posY = EngineData::SceenHeight * viewportY;

	this->left = posX;
	this->top = posY;
}
