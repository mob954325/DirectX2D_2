#pragma once
#include "Component.h"
#include "BaseScript.h"

/// <summary>
/// 
/// </summary>
class ScriptComponent : public Component
{
public:
	ScriptComponent(BaseScript* pBaseScript) : m_Script(pBaseScript) {};

	void OnStart() override
	{
		if(m_Script) m_Script->OnStart(); 
	};

	void Update() 
	{ 
		if(m_Script) m_Script->OnUpdate(); 
	};	

	void OnDestroy() override
	{
		if(m_Script) m_Script->OnDestroy(); 
	}

protected:
	BaseScript* m_Script;
};