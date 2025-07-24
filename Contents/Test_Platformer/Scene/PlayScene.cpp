#include "PlayScene.h"
#include "Test_Platformer/Scripts/TestPlatformerGame_TestPlayer.h"

void Test_PlatformerGame::PlayScene::OnEnterImpl()
{
	player = new GameObject();
	player->SetName("Player");
	player->AddComponent<TestPlatformerGame_TestPlayer>();
	AddGameObject(player);
}

void Test_PlatformerGame::PlayScene::UpdateImpl()
{

}

void Test_PlatformerGame::PlayScene::OnExitImpl()
{
}
