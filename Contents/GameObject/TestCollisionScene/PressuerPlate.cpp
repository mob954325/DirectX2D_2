#include "PressuerPlate.h"
#include "algorithm"

void PressuerPlate::Start()
{
	transform->SetIsUnityCoords(true);

	box = AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetWidth(2);
	box->SetRect({ -50 / 2, -20 / 2, 50 / 2, 20 / 2 });

	aabb = AddComponent<AABBCollider>();
	aabb->SetSize(50, 20, 1);
	aabb->SetTrigger(true);

	text = AddComponent<TextRenderer>();
	text->SetWorldObject(true);
	text->SetText(L"버튼");

	alarmText = AddComponent<TextRenderer>();
	alarmText->SetText(L"");
	alarmText->SetViewportPosition(0.5f, 0.5f);
}

void PressuerPlate::Update()
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
