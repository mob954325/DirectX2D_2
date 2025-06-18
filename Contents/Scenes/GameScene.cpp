#include "GameScene.h"

#include "Utility/Singleton.h"
#include "Utility/Input.h"
#include "Utility/SceneManager.h"
#include "MenuTextObject.h"

#include "Sun.h"
#include "Earth.h"
#include "Moon.h"
#include "MainCamera.h"
#include "GameTextObject.h"

void GameScene::OnEnterImpl()
{
	m_MainCamera = new MainCamera();
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
}

void GameScene::OnExitImpl()
{
	
}

void GameScene::UpdateImpl()
{
	if (Singleton<Input>::GetInstance().IsKeyPressed(VK_RETURN))
	{
		Singleton<SceneManager>::GetInstance().ChangeScene(0);
	}
}
