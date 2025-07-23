#include "MenuScene.h"

#include "Utils/Singleton.h"
#include "Platform/Input.h"
#include "Scene/SceneManager.h"
#include <Test_2Q/GameObject/MenuScene/MenuTextObject.h>

void MenuScene::OnEnterImpl()
{
	menuObj = new GameObject();
	menuObj->AddComponent<MenuTextObject>();
	AddGameObject(menuObj);	
}

void MenuScene::OnExitImpl()
{
}

void MenuScene::UpdateImpl()
{
}
