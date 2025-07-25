﻿#pragma once
#include "framework.h"

/// <summary>
/// 모든 객체가 상속받는 클래스 ( 유니티에서의 Object를 담당 )
/// </summary>
class BaseObject
{
private:
	static uint64_t nextInstanceID;
	uint64_t instanceID = 0;

protected:
	std::string name = "";

public:
	BaseObject() : instanceID(nextInstanceID++) {}
	virtual ~BaseObject() {}

	uint64_t GetInstanceID();
	std::string GetName();
	void SetName(std::string str);

	static void Destroy(BaseObject obj, float t = 0.0f);
	static void Instantiate(BaseObject original);

	operator bool() const
	{
		return instanceID == 0 ? false : true;
	}

	bool operator !=(BaseObject rhs) const
	{
		return instanceID != rhs.GetInstanceID();
	}

	bool operator ==(BaseObject rhs) const
	{
		return instanceID == rhs.GetInstanceID();
	}
};