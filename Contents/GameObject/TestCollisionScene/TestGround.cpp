﻿#include "TestGround.h"
#include "Datas/EngineData.h"

void TestGround::Start()
{
	transform->SetIsUnityCoords(true);

	box = AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetWidth(2.0f);

	Vector2 posVec = transform->GetPosition();
	box->SetRect({ -1024 / 2, -50 / 2, 1024 / 2, 50 / 2 });
	
	aabb = AddComponent<AABBCollider>();
	aabb->SetSize(1024, 50, 1);
}

void TestGround::Update()
{
}

void TestGround::OnDestroy()
{
}
