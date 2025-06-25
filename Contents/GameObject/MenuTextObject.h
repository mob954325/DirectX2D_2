#pragma once
#include "Component/Base/GameObject.h"
#include "Component/TextRenderer.h"
#include "Component/InputSystem.h"
#include "Component/BoxComponent.h"

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

