#include "GameScene.h"

#include "Utility/Singleton.h"
#include "Utility/Input.h"
#include "Utility/SceneManager.h"
#include "MenuTextObject.h"

#include "Sun.h"
#include "Earth.h"
#include "Moon.h"
#include "FreeCamera.h"
#include "GameTextObject.h"
#include "TestPlayer.h"
#include "SunGeneratorObject.h"

void GameScene::OnEnterImpl()
{
	m_TestPlayer = new TestPlayer();
	AddGameObject(m_TestPlayer);

	m_MainCamera = new FreeCamera();
	AddGameObject(m_MainCamera);
	
	m_Sun = new Sun();
	AddGameObject(m_Sun);
	 
	m_Earth = new Earth();
	AddGameObject(m_Earth);
	m_Earth->transform->SetParent(m_Sun->transform);
	
	m_Moon = new Moon();
	AddGameObject(m_Moon);
	m_Moon->transform->SetParent(m_Earth->transform);
	
	m_TextObject = new GameTextObject();
	AddGameObject(m_TextObject);

	m_SunGeneratorObject = new SunGeneratorObject;
	AddGameObject(m_SunGeneratorObject);
}

void GameScene::OnExitImpl()
{
	
}

void GameScene::UpdateImpl()
{

}
