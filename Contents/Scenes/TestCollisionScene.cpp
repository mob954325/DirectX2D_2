#include "TestCollisionScene.h"
#include "GameObject/TestCollisionScene/TestRigidbodyObject.h"
#include "GameObject/TestGameScene/FreeCamera.h"
#include "GameObject/TestCollisionScene/TestGround.h"
#include "GameObject/TestGameScene/TestPlayer.h"
#include "GameObject/TestGameScene/Sun.h"
#include "Components/Camera/CameraManager.h"
#include "GameObject/TestCollisionScene/TestWall.h"
#include "GameObject/TestCollisionScene/TestColliderboxGenerator.h"
#include "GameObject/TestCollisionScene/PressuerPlate.h"

void TestCollisionScene::OnEnterImpl()
{
	m_MainCamera = new GameObject();
	m_MainCamera->AddComponent<FreeCamera>();
	AddGameObject(m_MainCamera, "MainCamera");

	player = new GameObject();
	player->AddComponent<TestRigidbodyObject>();
	AddGameObject(player, "Player");

	ground = new GameObject();
	ground->AddComponent<TestGround>();
	AddGameObject(ground, "Ground");

	rightWall = new GameObject();
	rightWall->AddComponent<TestWall>();
	AddGameObject(rightWall, "rWall");
	rightWall->GetTransform().SetPosition(400, 0);

	leftWall = new GameObject();
	leftWall->AddComponent<TestWall>();
	AddGameObject(leftWall, "lWall");
	leftWall->GetTransform().SetPosition(-400, 0);

	boxGenerator = new GameObject();TestColliderboxGenerator();
	AddGameObject(boxGenerator, "bxg");

	doorButton = new GameObject();PressuerPlate();
	AddGameObject(doorButton, "doorButton");
	doorButton->GetTransform().SetPosition(200, 30);
}

void TestCollisionScene::OnExitImpl()
{
}

void TestCollisionScene::UpdateImpl()
{

}
