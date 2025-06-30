#pragma once
#include "Components/Logic/ScriptComponent.h"
#include "Systems/Input.h"
class InputSystem : public ScriptComponent
{
public:
	void OnStart() override;
	void OnDestroy() override;
	void Update();

	bool IsKeyPressed(int vKey);
	bool IsKeyDown(int vKey);
	bool IsKeyRelease(int vKey);

private:
	Input* input{};
};