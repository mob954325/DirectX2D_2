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
	m_MainCamera = new FreeCamera();
	AddGameObject(m_MainCamera, "MainCamera");

	player = new TestRigidbodyObject();
	AddGameObject(player, "Player");

	ground = new TestGround();
	AddGameObject(ground, "Ground");

	rightWall = new TestWall();
	AddGameObject(rightWall, "Wall");
	rightWall->transform->SetPosition(400, 0);

	leftWall = new TestWall();
	AddGameObject(leftWall, "Wall");
	leftWall->transform->SetPosition(-400, 0);

	boxGenerator = new TestColliderboxGenerator();
	AddGameObject(boxGenerator, "bxg");

	doorButton = new PressuerPlate();
	AddGameObject(doorButton, "doorButton");
	doorButton->transform->SetPosition(200, 30);
}

void TestCollisionScene::OnExitImpl()
{
}

void TestCollisionScene::UpdateImpl()
{

}
