#include "MenuScene.h"

#include "Utility/Singleton.h"
#include "Utility/Input.h"
#include "Core/SceneManager.h"
#include "MenuTextObject.h"


void MenuScene::OnEnterImpl()
{
	AddGameObject(new MenuTextObject());	
}

void MenuScene::OnExitImpl()
{
}

void MenuScene::UpdateImpl()
{
	if (Singleton<Input>::GetInstance().IsKeyPressed(VK_RETURN))
	{
		Singleton<SceneManager>::GetInstance().ChangeScene(1);
	}
}
