﻿#pragma once
#include "Components/Base/GameObject.h"
#include "Components/Rendering/TextRenderer.h"
#include "Components/Logic/InputSystem.h"
#include "Components/Rendering/BoxComponent.h"

class GameTextObject : public GameObject
{
public:
	GameTextObject() {};
	~GameTextObject() {};

	void Start() override;
	void Update() override;
	void OnDestroy() override;

private:
	TextRenderer* textRenderer{};
	TextRenderer* textRenderer2{};
	TextRenderer* textRenderer3{};
	TextRenderer* textRenderer4{};

	InputSystem* inputSystem{};
};

