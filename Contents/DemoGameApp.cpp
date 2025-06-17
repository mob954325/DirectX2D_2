#include "DemoGameApp.h"
#include "Core/D2DRenderManager.h"
#include "Core/SceneManager.h"
#include "Utility/Singleton.h"
#include "Utility/Input.h"
#include "Utility/GameTime.h"

#include "MenuScene.h"
#include "GameScene.h"

void DemoGameApp::Initialize()
{
	__super::Initialize(); // Application 초기화

	Singleton<SceneManager>::GetInstance().AddScene(new MenuScene());
	Singleton<SceneManager>::GetInstance().AddScene(new GameScene());
	Singleton<SceneManager>::GetInstance().ChangeScene(0);
	/*camera = new Transform();
	
	// Sun -> Earth -> Moon
	m_Sun = new Sun(m_D2DRenderManager, m_ScriptSystem);

	m_Earth = new BitmapRenderer();
	m_Earth->GetTransform()->SetScale(0.5f, 0.5f);
	m_Earth->GetTransform()->SetPosition(0.0f, 1000.0f);
	m_Earth->GetTransform()->SetParent(m_Sun->GetTransform());
	m_Earth->GetTransform()->SetCamera(camera);

	ComPtr<ID2D1Bitmap1> outEarthBitmap;
	hr = m_D2DRenderManager->CreateBitmapFromFile(L"../Resource/Earth.png", outEarthBitmap.GetAddressOf());
	m_Earth->SetBitmap(outEarthBitmap);
	m_Earth->SetOffSet(outSunBitmap.Get()->GetSize().width / 2 * -1, outSunBitmap.Get()->GetSize().height / 2 * -1);
	assert(SUCCEEDED(hr));

	m_Moon = new BitmapRenderer();
	m_Moon->GetTransform()->SetScale(0.5f, 0.5f);
	m_Moon->GetTransform()->SetPosition(0.0f, 1000.0f);
	m_Moon->GetTransform()->SetParent(m_Earth->GetTransform());
	m_Moon->GetTransform()->SetCamera(camera);

	ComPtr<ID2D1Bitmap1> outMoonBitamp;
	hr = m_D2DRenderManager->CreateBitmapFromFile(L"../Resource/Moon.png", outMoonBitamp.GetAddressOf());
	m_Moon->SetBitmap(outMoonBitamp);
	m_Moon->SetOffSet(outSunBitmap.Get()->GetSize().width / 2 * -1, outSunBitmap.Get()->GetSize().height / 2 * -1);
	assert(SUCCEEDED(hr));

	objects.push_back(m_Sun);
	objects.push_back(m_Earth);
	objects.push_back(m_Moon);

	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->GetComponent<BitmapRenderer>()->SetScreenSize(m_Width, m_Height);
	}

	m_D2DRenderManager->SetMainCamera(camera); */
}

void DemoGameApp::Render()
{
	__super::Render();
}

void DemoGameApp::Uninitialize()
{
	__super::Uninitialize();

	// delete BitmapRenderer
	//for (int i = 0; i < objects.size(); i++)
	//{
	//	delete objects[i];
	//	objects[i] = nullptr;
	//}

	//objects.clear();
}

void DemoGameApp::Update()
{
	__super::Update();

	//FlagInputUpdate();
	//MoveCamera();
	//SolarSystemUpdate();
}

//void DemoGameApp::FlagInputUpdate()
//{
//	if (Singleton<Input>::GetInstance().IsKeyPressed('R')) // R : 그림 움직임 
//	{		
//		isSolarSystemMove = !isSolarSystemMove;
//	}
//
//	if (Singleton<Input>::GetInstance().IsKeyPressed('T')) // T : 회전 방향 반전
//	{
//		baseRotateSpeed *= -1;
//	}
//
//	if (Singleton<Input>::GetInstance().IsKeyPressed('Y')) // Y : 유니티 좌표계 사용
//	{
//		for (GameObject* comp : objects)
//		{
//			comp->transform->SetIsUnityCoords(!comp->transform->IsUnityCoords());
//		}
//	}
//
//	if (Singleton<Input>::GetInstance().IsKeyPressed('U'))
//	{
//		Reset();
//	}
//}
//
//void DemoGameApp::MoveCamera()
//{
//	if (Singleton<Input>::GetInstance().IsKeyDown('D'))
//	{
//		D2D1_VECTOR_2F position = camera->GetPosition();
//		camera->SetPosition(position.x + cameraMoveSpeed, position.y);
//	}
//	if (Singleton<Input>::GetInstance().IsKeyDown('A'))
//	{
//		D2D1_VECTOR_2F position = camera->GetPosition();
//		camera->SetPosition(position.x - cameraMoveSpeed, position.y);
//	}
//	if (Singleton<Input>::GetInstance().IsKeyDown('W'))
//	{
//		D2D1_VECTOR_2F position = camera->GetPosition();
//		camera->SetPosition(position.x, position.y + cameraMoveSpeed);
//	}
//	if (Singleton<Input>::GetInstance().IsKeyDown('S'))
//	{
//		D2D1_VECTOR_2F position = camera->GetPosition();
//		camera->SetPosition(position.x, position.y - cameraMoveSpeed);
//	}
//}
//
//void DemoGameApp::SolarSystemUpdate()
//{
//	if (!isSolarSystemMove) return;
//
//	float rotation_sun = m_Sun->transform->GetRotation();
//	m_Sun->transform->SetRotation(rotation_sun + baseRotateSpeed * sunRotateRatio * Singleton<GameTime>::GetInstance().GetDeltaTime());
//
//	//float rotation_earth = m_Earth->transform->GetRotation();
//	//m_Earth->transform->SetRotation(rotation_earth + baseRotateSpeed * earthRotateRatio * Singleton<GameTime>::GetInstance().GetDeltaTime());
//
//	//float rotation_moon = transform_Moon->GetRotation();
//	//transform_Moon->SetRotation(rotation_moon + baseRotateSpeed * moonRotateRatio * Singleton<GameTime>::GetInstance().GetDeltaTime());
//}
//
//void DemoGameApp::Reset()
//{
//	m_Sun->transform->SetPosition(0.0f, 0.0f);
//	camera->SetPosition(0.0f, 0.0f);
//}
