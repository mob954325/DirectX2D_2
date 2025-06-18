#pragma once
#include "pch.h"
#include "Utility/Singleton.h"
#include "Base/Component.h"
#include "Transform.h"

/// <summary>
/// 모든 게임 오브젝트가 상속받는 클래스로 Component만 담고 Component관련 함수만 포함되어있음
/// </summary>
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	/// <summary>
	/// Update 실행 전 한 번 실행되는 함수
	/// </summary>
	virtual void Start() = 0;

	/// <summary>
	/// 업데이트 실행
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// 씬 종료시 실행될 함수
	/// </summary>
	virtual void OnDestory() = 0;

	Transform* transform = {};

	template <typename T>
	T* AddComponent()
	{
		static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

		T* comp = new T;
		comp->owner = this;
		components.push_back(comp);

		comp->OnStart();
		RegisterComponentWithScriptSystem(comp);

		return comp;
	}

	template <typename T>
	T* GetComponent()
	{
		for (Component* comp : components)
		{
			if (typeid(*comp) == typeid(T))
			{
				return static_cast<T*>(comp);
			}
		}
	}

	template <typename T>
	void RemoveComponent(T* targetComp)
	{
		for (auto it = components.begin(); it != components.end(); ++it)
		{
			Component* comp = *it;
			if (comp == targetComp)
			{
				delete comp;
				it = components.erase(it); // 벡터에서 삭제
			}
		}
	}
private:
	void RegisterComponentWithScriptSystem(Component* comp);

	std::vector<Component*> components; // 컴포넌트를 담는 컨테이너
};

