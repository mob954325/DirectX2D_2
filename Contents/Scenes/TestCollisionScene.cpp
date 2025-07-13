#include "TestCollisionScene.h"
#include "GameObject/TestGameScene/TestPlayer.h"
#include "GameObject/TestCollisionScene/TestGround.h"

void TestCollisionScene::OnEnterImpl()
{
	player = new TestPlayer;
	AddGameObject(player);

	dummy = new TestGround;
	AddGameObject(dummy);
}

void TestCollisionScene::OnExitImpl()
{
}

void TestCollisionScene::UpdateImpl()
{
}
