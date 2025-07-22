#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Logic/InputSystem.h"
#include "Components/Rendering/TextRenderer.h"
#include <vector>

class TestColliderboxGenerator : public MonoBehavior
{
public:
	void OnStart() override;
	void OnUpdate() override;
	void OnDestroy() override;

private:
	InputSystem* input;
	TextRenderer* text;

	std::vector<GameObject*> objects;
};

