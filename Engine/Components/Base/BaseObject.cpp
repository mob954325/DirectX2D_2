﻿#include "BaseObject.h"

uint64_t BaseObject::nextInstanceID = 1;

uint64_t BaseObject::GetInstanceID()
{
    return instanceID;
}

std::string BaseObject::GetName()
{
    return name;
}

void BaseObject::SetName(std::string str)
{
    name = str;
}

void BaseObject::Destroy(BaseObject obj, float t)
{
    // 파괴
}

void BaseObject::Instantiate(BaseObject original)
{
    // map에서 찾아서 생성
}