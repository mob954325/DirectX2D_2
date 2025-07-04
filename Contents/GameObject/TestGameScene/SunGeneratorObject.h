﻿#pragma once
#include "Components/Base/GameObject.h"
#include "Components/Rendering/BitmapRenderer.h"
#include "Components/Logic/InputSystem.h"
#include "Components/Rendering/TextRenderer.h"
#include <vector>

class SunGeneratorObject : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestroy() override;

private:
	std::vector<GameObject*> objects;

	BitmapRenderer* bitmapRenderer{};
	TextRenderer* textRenderer{};
	InputSystem* input{};
};

