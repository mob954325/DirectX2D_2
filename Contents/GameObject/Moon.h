#pragma once
#include "Component/Base/GameObject.h"
#include "Component/BitmapRenderer.h"

class Moon : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestroy() override;

protected:
	BitmapRenderer* bitmapRenderer{};
};

