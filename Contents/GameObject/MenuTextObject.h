#pragma once
#include "Component/Base/GameObject.h"
#include "Component/TextRenderer.h"
#include "Component/InputSystem.h"

class MenuTextObject : public GameObject
{
public:
	MenuTextObject() {};
	~MenuTextObject() {};

	void Start() override;
	void Update() override;
	void OnDestory() override;

private:
	TextRenderer* textRenderer{};
	InputSystem* inputSystem{};
};

