#include "MainMenu.h"
#include "Test_Platformer/Scripts/MenuObj.h"

void Test_PlatformerGame::MainMenu::OnEnterImpl()
{
	menuObj = new GameObject();			// 새로운 GameObject 객체 생성
	menuObj->SetName("MenuObject");		// 오브젝트 이름 설정
	menuObj->AddComponent<MenuObj>();	// MonoBehavior 컴포넌트를 오브젝트에 등록
	AddGameObject(menuObj);				// GameObject를 해당 씬에 추가
}

void Test_PlatformerGame::MainMenu::UpdateImpl()
{
}

void Test_PlatformerGame::MainMenu::OnExitImpl()
{
}

