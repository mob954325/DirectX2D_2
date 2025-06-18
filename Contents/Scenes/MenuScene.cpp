#include "MenuScene.h"

#include "Utility/Singleton.h"
#include "Utility/Input.h"
#include "Utility/SceneManager.h"
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
}
