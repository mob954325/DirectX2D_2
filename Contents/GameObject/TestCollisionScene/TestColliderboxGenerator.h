#pragma once
#include "Components/Base/GameObject.h"
#include "Components/Logic/InputSystem.h"
#include "Components/Rendering/TextRenderer.h"
#include <vector>

class TestColliderboxGenerator : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestroy() override;

private:
	InputSystem* input;
	TextRenderer* text;

	std::vector<GameObject*> objects;
};

