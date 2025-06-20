#include "InputSystem.h"

void InputSystem::OnStart()
{
	input = new Input();
}

void InputSystem::OnDestroy()
{
}

void InputSystem::Update()
{
	input->Update();
}

bool InputSystem::IsKeyPressed(int vKey)
{
	return input->IsKeyPressed(vKey);
}

bool InputSystem::IsKeyDown(int vKey)
{
	return input->IsKeyDown(vKey);
}

bool InputSystem::IsKeyRelease(int vKey)
{
	return input->IsKeyReleased(vKey);
}
