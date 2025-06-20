#pragma once
#include "Component/Base/GameObject.h"
#include "Component/InputSystem.h"
#include "Component/Camera.h"

class MainCamera : public GameObject
{
public:
	MainCamera() {};
	~MainCamera() {};

	void Start() override;
	void Update() override;
	void OnDestroy() override;

private:
	Camera* camera{};
	InputSystem* inputSystem{};

	float cameraMoveSpeed = 5.0f;
};

