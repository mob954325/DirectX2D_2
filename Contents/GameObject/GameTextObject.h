#pragma once
#include "Component/Base/GameObject.h"
#include "Component/TextRenderer.h"
#include "Component/InputSystem.h"

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

	InputSystem* inputSystem{};
};

