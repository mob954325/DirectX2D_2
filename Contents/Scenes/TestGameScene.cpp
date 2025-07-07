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

void TestGameScene::OnEnterImpl() // 질문11
{
	m_TestPlayer = new TestPlayer();
	AddGameObject(m_TestPlayer, "Player");

	m_MainCamera = new FreeCamera();
	AddGameObject(m_MainCamera, "MainCamera");
	
	m_Sun = new Sun();
	AddGameObject(m_Sun, "Sun");
	 
	m_Earth = new Earth();
	AddGameObject(m_Earth, "Earth");
	m_Earth->transform->SetParent(m_Sun->transform);
	
	m_Moon = new Moon();
	AddGameObject(m_Moon, "Moon");
	m_Moon->transform->SetParent(m_Earth->transform);
	
	m_TextObject = new GameTextObject();
	AddGameObject(m_TextObject, "TextUI");

	m_SunGeneratorObject = new SunGeneratorObject;
	AddGameObject(m_SunGeneratorObject, "G_Sun");
}

void TestGameScene::OnExitImpl()
{
	
}

void TestGameScene::UpdateImpl()
{

}
