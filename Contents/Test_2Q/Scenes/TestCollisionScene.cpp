#include "TestCollisionScene.h"
#include "Test_2Q/GameObject/TestCollisionScene/TestRigidbodyObject.h"
#include "Test_2Q/GameObject/TestGameScene/FreeCamera.h"
#include "Test_2Q/GameObject/TestCollisionScene/TestGround.h"
#include "Test_2Q/GameObject/TestGameScene/Test2QApp_TestPlayer.h"
#include "Test_2Q/GameObject/TestGameScene/Sun.h"
#include "Components/Camera/CameraManager.h"
#include "Test_2Q/GameObject/TestCollisionScene/TestWall.h"
#include "Test_2Q/GameObject/TestCollisionScene/TestColliderboxGenerator.h"
#include "Test_2Q/GameObject/TestCollisionScene/PressuerPlate.h"

using namespace Test_2QApp;

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

	boxGenerator = new GameObject();
	boxGenerator->AddComponent<TestColliderboxGenerator>();
	AddGameObject(boxGenerator, "bxg");

	doorButton = new GameObject();
	doorButton->AddComponent<PressuerPlate>();
	AddGameObject(doorButton, "doorButton");
	doorButton->GetTransform().SetPosition(200, 30);
}

void TestCollisionScene::OnExitImpl()
{
}

void TestCollisionScene::UpdateImpl()
{

}
