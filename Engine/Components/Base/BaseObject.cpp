#include "BaseObject.h"

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
