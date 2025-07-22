#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/TextRenderer.h"
#include "Components/Logic/InputSystem.h"
#include "Components/Rendering/BoxComponent.h"

class GameTextObject : public MonoBehavior
{
public:
	GameTextObject() {};
	~GameTextObject() {};

	void OnStart() override;
	void OnUpdate() override;
	void OnDestroy() override;

private:
	TextRenderer* textRenderer{};
	TextRenderer* textRenderer2{};
	TextRenderer* textRenderer3{};
	TextRenderer* textRenderer4{};

	InputSystem* inputSystem{};
};

