#pragma once
#include "Base/GameObject.h"
#include "TextRenderer.h"

class MenuTextObject : public GameObject
{
public:
	void Start() override;
	void OnDestory() override;

private:
	TextRenderer* textRenderer;
};

