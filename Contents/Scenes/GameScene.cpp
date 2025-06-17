#include "GameScene.h"

#include "Utility/Singleton.h"
#include "Utility/Input.h"
#include "Core/SceneManager.h"
#include "MenuTextObject.h"

void GameScene::OnEnterImpl()
{
	//m_Sun = new Sun();
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
