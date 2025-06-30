#pragma once
#include "Components/Base/GameObject.h"
#include "Components/Rendering/BitmapRenderer.h"

class Earth : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestroy() override;

protected:
	BitmapRenderer* bitmapRenderer{};

	float baseRotateSpeed = 360.0f;
	float earthRotateRatio = 0.5f;
};

