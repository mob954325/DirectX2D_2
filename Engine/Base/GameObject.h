#pragma once
#include "pch.h"
#include "Transform.h"

class Component;

/// <summary>
/// 모든 게임 오브젝트가 상속받는 클래스로 Component만 담고 Component관련 함수만 포함되어있음
/// </summary>
class GameObject
{
public:
	GameObject();
	~GameObject();

	/// <summary>
	/// Update 실행 전 한 번 실행되는 함수
	/// </summary>
	virtual void Start() = 0;
	Transform* transform;

	template <typename T>
	T* AddComponent()
	{
		T* comp = new T;
		comp->owner = this;
		components.push_back(comp);

		return comp;
	}

	template <typename T>
	T* GetComponent()
	{
		for (Component* comp : components)
		{
			if (typeid(*comp) == typeid(T)) // ??
			{
				return static_cast<T>(comp);
			}
		}
	}

	// remove

private:
	std::vector<Component*> components; // 컴포넌트를 담는 컨테이너
};

