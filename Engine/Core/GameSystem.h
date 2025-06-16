#pragma once
#include "pch.h"
#include "Singleton.h"
#include "Component.h"
#include "D2DRenderManager.h"

class GameSystem
{
public:
	GameSystem() = default;
	~GameSystem();

	void GetRenderManager(D2DRenderManager* manager); // 임시
	void Regist(Component* comp);
	void UnRegist(Component* comp);

	void Update();	// 컴포넌트 업데이트 실행함수
	void Render(D2DRenderManager* IRenderer);	// 컴포넌트 렌더링 실행함수

private:
	D2DRenderManager* renderManager = nullptr;
	std::vector<Component*> components; // 실제로 Update 될 컴포넌트 데이터들
};

