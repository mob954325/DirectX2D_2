#include "DemoGameApp.h"
#include "Platform/D2DRenderManager.h"
#include "Scene/SceneManager.h"
#include "Utils/Singleton.h"
#include "Systems/Input.h"
#include "Utils/GameTime.h"

#include "Scenes/MenuScene.h"
#include "Scenes/TestGameScene.h"

void DemoGameApp::Initialize()
{
	__super::Initialize(); // Application 초기화

	Singleton<SceneManager>::GetInstance().AddScene(new MenuScene());
	Singleton<SceneManager>::GetInstance().AddScene(new TestGameScene());
	Singleton<SceneManager>::GetInstance().ChangeScene(0);
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
