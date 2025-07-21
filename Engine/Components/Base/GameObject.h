#pragma once
#include "pch.h"
#include "Utils/Singleton.h"
#include "Component.h"
#include "Transform.h"
#include "Datas/EngineData.h"
#include "Scene/GameObjectQuery.h"
#include "BaseObject.h"

/// <summary>
/// 모든 게임 오브젝트가 상속받는 클래스로 Component만 담고 Component관련 함수만 포함되어있음
/// </summary>
class GameObject : public BaseObject
{
public:
	GameObject();
	virtual ~GameObject();

	Transform* transform = {};

	template <typename T>
	T* AddComponent()
	{
		static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

		T* comp = new T;
		comp->owner = this;
		components.push_back(comp);

		DispatchComponentToSystem(comp);
		comp->OnStart();

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

		return nullptr; // NOTE: main이랑 merge하고 나서 해당 주석 제거할 것
	}

	void RemoveComponent(Component* targetComp);

	// 오브젝트 제거 관련
	void MarkForRemoval() { shouldRemove = true; };				// 제거할 오브젝트라고 마킹
	bool IsMarkedForRemoval() const { return shouldRemove; }

	// 오브젝트 추가 관련
	void SetEarlyCreated() { earlyCreated = false; };			// 추가된 오브젝트라고 마킹
	bool IsEarlyCreated() const { return earlyCreated; }
	
	// get/set
	EngineData::RenderLayer GetRenderLayer() const { return renderLayer; }
	int GetRenderLayerIndex() const { return (int)renderLayer; }

	void SetQueryInterface(IGameObjectQuery* q) { query = q; }

protected:
	EngineData::RenderLayer renderLayer = EngineData::RenderLayer::None;
	IGameObjectQuery* query = nullptr;

private:
	void DispatchComponentToSystem(Component* comp);
	void RemoveComponentToSystem(Component* comp);

	std::vector<Component*> components; // 컴포넌트를 담는 컨테이너
	bool shouldRemove = false;			// 해당 오브젝트가 다음 프레임에 제거될 대상인지 확인하는 변수 ( 제거예정이면 true )
	bool earlyCreated = true;			// 해당 오브젝트가 이번 프레임에 생성되었는지 확인하는 변수 ( 생성된 후 다음 프레임에 false로 전환 )
};

