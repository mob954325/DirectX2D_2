#include "TestCollisionScene.h"
#include "GameObject/TestCollisionScene/TestRigidbodyObject.h"
#include "GameObject/TestGameScene/FreeCamera.h"
#include "GameObject/TestCollisionScene/TestGround.h"
#include "GameObject/TestGameScene/TestPlayer.h"
#include "GameObject/TestGameScene/Sun.h"
#include "Components/Camera/CameraManager.h"
#include "GameObject/TestCollisionScene/TestWall.h"
#include "GameObject/TestCollisionScene/TestColliderboxGenerator.h"

void TestCollisionScene::OnEnterImpl()
{
	m_MainCamera = new FreeCamera();
	AddGameObject(m_MainCamera, "MainCamera");

	player = new TestRigidbodyObject();
	AddGameObject(player, "Player");

	ground = new TestGround();
	AddGameObject(ground, "Ground");

	wall = new TestWall();
	AddGameObject(wall, "Wall");

	boxGenerator = new TestColliderboxGenerator();
	AddGameObject(boxGenerator, "bxg");
}

void TestCollisionScene::OnExitImpl()
{
}

void TestCollisionScene::UpdateImpl()
{

}
