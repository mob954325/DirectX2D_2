#pragma once
#include "Component/Base/GameObject.h"
#include "Component/BitmapRenderer.h"

class Sun : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestory() override;

protected:
	BitmapRenderer* bitmapRenderer {};

	float baseRotateSpeed = 360.0f;	
	float sunRotateRatio = 0.1f;
};

