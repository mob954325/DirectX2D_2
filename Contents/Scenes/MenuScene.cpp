#include "MenuScene.h"

#include "Utils/Singleton.h"
#include "Systems/Input.h"
#include "Scene/SceneManager.h"
#include "GameObject/MenuScene/MenuTextObject.h"


void MenuScene::OnEnterImpl()
{
	AddGameObject(new MenuTextObject());	
}

void MenuScene::OnExitImpl()
{
}

void MenuScene::UpdateImpl()
{
}
