#pragma once
#include "Base/GameObject.h"
#include "BitmapRenderer.h"

class Sun : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestory() override;

protected:
	BitmapRenderer* bitmapRenderer {};
};

