#pragma once
class IRenderable
{
public:
	IRenderable() = default;
	~IRenderable() = default;

	virtual void Render(D2DRenderManager* manager) = 0;
};