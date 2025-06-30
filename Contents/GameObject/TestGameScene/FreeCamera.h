#pragma once
#include "Components/Base/GameObject.h"
#include "Components/Logic/InputSystem.h"
#include "Components/Camera/Camera.h"

class FreeCamera : public GameObject
{
public:
	FreeCamera() {};
	~FreeCamera() {};

	void Start() override;
	void Update() override;
	void OnDestroy() override;

private:
	Camera* camera{};
	InputSystem* inputSystem{};

	float cameraMoveSpeed = 5.0f;
};

