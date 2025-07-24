#include "TestPlatformerGameApp.h"

#include "Utils/Singleton.h"
#include "Scene/SceneManager.h"
#include "Test_Platformer/Scene/MainMenu.h"
#include "Test_Platformer/Scene/PlayScene.h"

void Test_PlatformerGame::TestPlatformerGameApp::Initialize()
{
	__super::Initialize();

	// 1. SceneManager에 Scene 추가하기
	menuScene = new MainMenu();	// MainMenu 씬 객체 생성
	Singleton<SceneManager>::GetInstance().AddScene(menuScene); // 씬 추가

	playScene = new PlayScene();
	Singleton<SceneManager>::GetInstance().AddScene(playScene); // 씬 추가
	Singleton<SceneManager>::GetInstance().Init();	// SceneManager 초기화 -> currentScene 초기화 및 RenderSystem의 RenderLayer 초기화
}

void Test_PlatformerGame::TestPlatformerGameApp::Render()
{
	__super::Render();
}

void Test_PlatformerGame::TestPlatformerGameApp::Uninitialize()
{
	__super::Uninitialize();
}

void Test_PlatformerGame::TestPlatformerGameApp::Update()
{
	__super::Update();
}
