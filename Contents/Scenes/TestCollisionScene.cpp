#include "TestCollisionScene.h"
#include "GameObject/TestCollisionScene/TestRigidbodyObject.h"
#include "GameObject/TestGameScene/FreeCamera.h"
#include "GameObject/TestCollisionScene/TestGround.h"
#include "GameObject/TestGameScene/TestPlayer.h"
#include "GameObject/TestGameScene/SunGeneratorObject.h"
#include "Components/Camera/CameraManager.h"

void TestCollisionScene::OnEnterImpl()
{
	m_MainCamera = new FreeCamera();
	AddGameObject(m_MainCamera, "MainCamera");

	player = new TestRigidbodyObject();
	AddGameObject(player, "Player");

	ground = new TestGround();
	AddGameObject(ground, "Ground");

	sun = new SunGeneratorObject();
	AddGameObject(sun, "sun1");
}

void TestCollisionScene::OnExitImpl()
{
}

void TestCollisionScene::UpdateImpl()
{

}
