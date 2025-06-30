#pragma once
#include "Components/Base/GameObject.h"
#include "Components/Rendering/TextRenderer.h"
#include "Components/Logic/InputSystem.h"
#include "Components/Rendering/BoxComponent.h"

class MenuTextObject : public GameObject
{
public:
	MenuTextObject() {};
	~MenuTextObject() {};

	void Start() override;
	void Update() override;
	void OnDestroy() override;

private:
	TextRenderer* textRenderer{};
	InputSystem* inputSystem{};
	BoxComponent* box{};
};

