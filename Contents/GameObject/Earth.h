#pragma once
#include "Base/GameObject.h"
#include "BitmapRenderer.h"

class Earth : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestory() override;

protected:
	BitmapRenderer* bitmapRenderer{};

	float baseRotateSpeed = 360.0f;
	float earthRotateRatio = 0.5f;
};

