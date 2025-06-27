#include "DemoGameApp.h"
#include "Core/D2DRenderManager.h"
#include "Utility/SceneManager.h"
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
