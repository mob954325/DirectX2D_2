#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/TextRenderer.h"

class InfoTextObject : public MonoBehavior
{
public:
	void OnStart() override;
	void OnUpdate() override;

private:
	TextRenderer* t1{};
};

