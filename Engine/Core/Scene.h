#pragma once
#include "Base/GameObject.h"
#include "Base/Component.h"
#include "ScriptSystem.h"
#include "RenderSystem.h"
#include <vector>

struct SceneState
{
	// ??
};

class Scene
{
public:
	/// <summary>
	/// 등록된 오브젝트의 Start문 실행
	/// </summary>
	void OnEnter();

	/// <summary>
	/// 게임 오브젝트 파괴 리스트 순환 후 UpdateImpl() 호출
	/// </summary>
	void Update();

	/// <summary>
	/// 등록된 오브젝트 OnDestroy() 실행
	/// </summary>
	void OnExit();	

	void AddGameObject(GameObject* gameObject);
	void RemoveObject(GameObject* gameObject);
	void RegisterComponent(Component* comp);

	void SetScriptSystem(ScriptSystem* pSystem);
	void SetRenderSystem(RenderSystem* pSystem);

private:
	void DestroyGameObjects();

	/// <summary>
	/// Scene을 상속 받은 클래스가 씬 시작 시 실행할 내용
	/// </summary>
	virtual void OnEnterImpl() = 0;

	/// <summary>
	/// Scene을 상속 받은 클래스가 씬 종료 시 실행할 내용
	/// </summary>
	virtual void OnExitImpl() = 0;

	/// <summary>
	/// Scene 상속 받은 클래스가 Update문 실행할 내용 ( Scene::Update() 에서 호출 )
	/// </summary>
	virtual void UpdateImpl() = 0;

	std::vector<GameObject*> gameObjects;
	std::vector<GameObject*> destroyList;
};

