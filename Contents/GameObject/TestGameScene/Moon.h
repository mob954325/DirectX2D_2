#pragma once
#include "Components/Base/GameObject.h"
#include "Components/Rendering/BitmapRenderer.h"

class Moon : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestroy() override;

protected:
	BitmapRenderer* bitmapRenderer{};
};

