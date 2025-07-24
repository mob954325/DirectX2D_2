#include "PressuerPlate.h"
#include "algorithm"
#include "Components/Base/GameObject.h"

using namespace Test_2QApp;

void PressuerPlate::OnStart()
{
	owner->GetTransform().SetUnityCoords(true);

	box = owner->AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetWidth(2);
	box->SetRect({ -50 / 2, -20 / 2, 50 / 2, 20 / 2 });

	aabb = owner->AddComponent<AABBCollider>();
	aabb->SetSize(50, 20, 1);
	aabb->SetTrigger(true);

	text = owner->AddComponent<TextRenderer>();
	text->SetWorldObject(true);
	text->SetText(L"버튼");

	alarmText = owner->AddComponent<TextRenderer>();
	alarmText->SetText(L"");
	alarmText->SetViewportPosition(0.5f, 0.5f);
}

void PressuerPlate::OnUpdate()
{
}

void PressuerPlate::OnDestroy()
{
}

void PressuerPlate::OnTriggerEnter(GameObject* collider)
{
	std::string::size_type n;
	std::string const s = collider->GetName();
	n = s.find("box");
	if (n != std::string::npos)
	{
		alarmText->SetText(L"[ 버튼 눌림 !!! ]");
	}
}

void PressuerPlate::OnTriggerStay(GameObject* collider)
{
}

void PressuerPlate::OnTriggerExit(GameObject* collider)
{
	std::string::size_type n;
	std::string const s = collider->GetName();
	n = s.find("box");
	if (n != std::string::npos)
	{
		alarmText->SetText(L"[ 버튼 대기 중 ]");
	}
}
