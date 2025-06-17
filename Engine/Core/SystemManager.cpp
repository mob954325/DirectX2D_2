#include "SystemManager.h"

void SystemManager::SetScriptSystem(ScriptSystem* pSystem)
{
	scriptSystem = pSystem;
}

ScriptSystem* SystemManager::GetScriptSystem()
{
	return scriptSystem;
}

void SystemManager::SetRenderSystem(RenderSystem* pSystem)
{
	renderSystem = pSystem;
}

RenderSystem* SystemManager::GetRenderSystem()
{
	return renderSystem;
}


void SystemManager::RegisterComponent(Component* comp)
{
	// dynamic cast를 해서 맞는 시스템 찾기
	if (auto rc = dynamic_cast<RenderComponent*>(comp))
	{
		if (renderSystem) renderSystem->Regist(rc);
	}
	else if (auto sc = dynamic_cast<ScriptComponent*>(comp))
	{
		if (scriptSystem) scriptSystem->Regist(sc);
	}
}

void SystemManager::UnRegisterComponent(Component* comp)
{
	if (auto rc = dynamic_cast<RenderComponent*>(comp))
	{
		if (renderSystem) renderSystem->UnRegist(rc);
	}
	else if (auto sc = dynamic_cast<ScriptComponent*>(comp))
	{
		if (scriptSystem) scriptSystem->UnRegist(sc);
	}
}

void SystemManager::ClearAllSystem()
{
	if (renderSystem) renderSystem->ClearAll();
	if (scriptSystem) scriptSystem->ClearAll();
}