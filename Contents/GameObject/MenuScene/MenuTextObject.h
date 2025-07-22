#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/TextRenderer.h"
#include "Components/Logic/InputSystem.h"
#include "Components/Rendering/BoxComponent.h"

class MenuTextObject : public MonoBehavior
{
public:
	MenuTextObject() {};
	~MenuTextObject() {};

	void OnStart() override;
	void OnUpdate() override;
	void OnDestroy() override;

private:
	TextRenderer* textRenderer{};
	InputSystem* inputSystem{};
	BoxComponent* box{};
};

