﻿#pragma once
#include "Component/Base/GameObject.h"
#include "Component/BitmapRenderer.h"
#include "Component/Camera.h"
#include "Component/InputSystem.h"

class TestPlayer : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestroy() override;

private:

	void Move();
	void CamMove();

	Camera* playerMainCam{};
	BitmapRenderer* idleBitmap{};
	InputSystem* input{};

	float speed = 5.0f;
};

