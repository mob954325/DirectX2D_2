#pragma once
#include "Utility/Singleton.h"
#include "ScriptSystem.h"
#include "RenderSystem.h"
#include "Base/Component.h"
#include <vector>

class ScriptSystem;
class RenderSystem;

/// <summary>
/// 엔진부 시스템 관리 클래스
/// </summary>
class SystemManager : public Singleton<SystemManager>
{
public:
	void SetScriptSystem(ScriptSystem* pSystem);
	ScriptSystem* GetScriptSystem();
	void SetRenderSystem(RenderSystem* pSystem);
	RenderSystem* GetRenderSystem();
	void RegisterComponent(Component* comp);
	void UnRegisterComponent(Component* comp);
	void ClearAllSystem();

private:
	ScriptSystem* scriptSystem;
	RenderSystem* renderSystem;
};

