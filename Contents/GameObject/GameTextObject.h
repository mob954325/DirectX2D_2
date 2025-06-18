#pragma once
#include "Base/GameObject.h"
#include "TextRenderer.h"
#include "InputSystem.h"

class GameTextObject : public GameObject
{
public:
	GameTextObject() {};
	~GameTextObject() {};

	void Start() override;
	void Update() override;
	void OnDestory() override;

private:
	TextRenderer* textRenderer{};
	TextRenderer* textRenderer2{};
	InputSystem* inputSystem{};
};

