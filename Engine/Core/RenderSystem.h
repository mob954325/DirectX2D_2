﻿#pragma once
#include "Utility/Singleton.h"
#include "Component/Base/RenderComponent.h"
#include "D2DRenderManager.h"
#include <vector>

class RenderSystem : public Singleton<RenderSystem>
{
public:
	RenderSystem() = default;
	~RenderSystem() = default;

	void Init(D2DRenderManager* manager) { renderManager = manager; }
	void Regist(RenderComponent* comp);
	void UnRegist(RenderComponent* comp);
	void ClearAll();

	void Update(D2DRenderManager* manager);	// 컴포넌트 업데이트 실행함수
private:
	D2DRenderManager* renderManager{};
	std::vector<RenderComponent*> components; // 실제로 Update 될 컴포넌트 데이터들
};

