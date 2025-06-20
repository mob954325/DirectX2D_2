#pragma once
#include "Component/Base/GameObject.h"
#include "Component/BitmapRenderer.h"

class Moon : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestory() override;

protected:
	BitmapRenderer* bitmapRenderer{};
};

