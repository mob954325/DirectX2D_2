#pragma once
#include "framework.h"
#include "Utility/Singleton.h"
#include "Component/Base/ScriptComponent.h"

class ScriptSystem : public Singleton<ScriptSystem>
{
public:
	ScriptSystem() = default;
	~ScriptSystem();

	void Register(ScriptComponent* comp);
	void UnRegist(ScriptComponent* comp);
	void ClearAll();

	void Update();	// 컴포넌트 업데이트 실행함수
private:
	std::vector<ScriptComponent*> components; // 실제로 Update 될 컴포넌트 데이터들
};

