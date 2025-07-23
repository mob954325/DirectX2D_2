#include "DemoGameApp.h"
#include "Platform/D2DRenderManager.h"
#include "Scene/SceneManager.h"
#include "Utils/Singleton.h"
#include "Platform/Input.h"
#include "Utils/GameTime.h"

#include "Test_2Q/Scenes/MenuScene.h"
#include "Test_2Q/Scenes/TestGameScene.h"
#include "Test_2Q/Scenes/TestCollisionScene.h"

using namespace Test_2QApp;

void DemoGameApp::Initialize()
{
	__super::Initialize(); // Application 초기화

	Singleton<SceneManager>::GetInstance().AddScene(new MenuScene());
	Singleton<SceneManager>::GetInstance().AddScene(new TestGameScene());
	Singleton<SceneManager>::GetInstance().AddScene(new TestCollisionScene());

	// SceneManager 초기화
	Singleton<SceneManager>::GetInstance().Init();
}

void DemoGameApp::Render()
{
	__super::Render();
}

void DemoGameApp::Uninitialize()
{
	__super::Uninitialize();
}

void DemoGameApp::Update()
{
	__super::Update();
}
