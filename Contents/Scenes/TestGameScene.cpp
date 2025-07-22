#include "TestGameScene.h"

#include "Utils/Singleton.h"
#include "Platform/Input.h"
#include "Scene/SceneManager.h"

#include "GameObject/TestGameScene/Sun.h"
#include "GameObject/TestGameScene/Earth.h"
#include "GameObject/TestGameScene/Moon.h"
#include "GameObject/TestGameScene/FreeCamera.h"
#include "GameObject/TestGameScene/GameTextObject.h"
#include "GameObject/TestGameScene/TestPlayer.h"
#include "GameObject/TestGameScene/SunGeneratorObject.h"
#include "GameObject/TestCollisionScene/TestGround.h"

void TestGameScene::OnEnterImpl()
{
	m_TestPlayer = new GameObject();
	m_TestPlayer->AddComponent<TestPlayer>();
	AddGameObject(m_TestPlayer, "Player");

	m_MainCamera = new GameObject();
	m_MainCamera->AddComponent<FreeCamera>();
	AddGameObject(m_MainCamera, "MainCamera");
	
	// m_Sun = new GameObject();
	// m_Sun->AddComponent<Sun>();
	// AddGameObject(m_Sun, "Sun");
	//  
	// m_Earth = new GameObject();
	// m_Earth->AddComponent<Earth>();
	// AddGameObject(m_Earth, "Earth");
	// m_Earth->GetTransform().SetParent(&m_Sun->GetTransform());
	// 
	// m_Moon = new GameObject();
	// m_Moon->AddComponent<Moon>();
	// AddGameObject(m_Moon, "Moon");
	// m_Moon->GetTransform().SetParent(&m_Earth->GetTransform());
	
	m_TextObject = new GameObject();
	m_TextObject->AddComponent<GameTextObject>();
	AddGameObject(m_TextObject, "TextUI");

	m_SunGeneratorObject = new GameObject();
	m_SunGeneratorObject->AddComponent<SunGeneratorObject>();
	AddGameObject(m_SunGeneratorObject, "G_Sun");

	// rigidTest = new TestGround;
	// AddGameObject(rigidTest, "Test_rigid");
}

void TestGameScene::OnExitImpl()
{
	
}

void TestGameScene::UpdateImpl()
{

}
