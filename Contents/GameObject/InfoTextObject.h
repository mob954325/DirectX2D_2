#pragma once
#include "Component/Base/GameObject.h"
#include "Component/TextRenderer.h"

class InfoTextObject : public GameObject
{
public:
	void Start() override;
	void Update() override;

private:
	TextRenderer* t1{};
};

