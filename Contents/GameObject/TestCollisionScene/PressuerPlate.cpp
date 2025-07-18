#include "PressuerPlate.h"

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
}

void PressuerPlate::Update()
{
}

void PressuerPlate::OnDestroy()
{
}

void PressuerPlate::OnTriggerEnter(GameObject* collider)
{
	std::cout << "TriggerEnter!!" << std::endl;
}

void PressuerPlate::OnTriggerStay(GameObject* collider)
{
}

void PressuerPlate::OnTriggerExit(GameObject* collider)
{
}
