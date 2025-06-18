#pragma once
#include "Base/GameObject.h"
#include "InputSystem.h"
#include "Base/Camera.h"

class MainCamera : public GameObject
{
public:
	MainCamera() {};
	~MainCamera() {};

	void Start() override;
	void Update() override;
	void OnDestory() override;

private:
	Camera* camera{};
	InputSystem* inputSystem{};

	float cameraMoveSpeed = 5.0f;
};

