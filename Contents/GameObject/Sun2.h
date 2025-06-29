#pragma once
#include "Component/Base/GameObject.h"
#include "Component/BitmapRenderer.h"
#include "Component/InputSystem.h"
#include <vector>

class Sun2 : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestroy() override;

private:
	std::vector<GameObject*> objects;

	BitmapRenderer* bitmapRenderer;
	InputSystem* input;
};

