#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/BitmapRenderer.h"

class Earth : public MonoBehavior
{
public:
	void OnStart() override;
	void OnUpdate() override;
	void OnDestroy() override;

protected:
	BitmapRenderer* bitmapRenderer{};

	float baseRotateSpeed = 360.0f;
	float earthRotateRatio = 0.5f;
};

