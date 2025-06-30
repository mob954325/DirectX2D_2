#pragma once
#include "Components/Base/GameObject.h"
#include "Components/Rendering/TextRenderer.h"

class InfoTextObject : public GameObject
{
public:
	void Start() override;
	void Update() override;

private:
	TextRenderer* t1{};
};

