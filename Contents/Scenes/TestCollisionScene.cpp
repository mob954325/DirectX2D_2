#include "TestCollisionScene.h"
#include "GameObject/TestCollisionScene/TestRigidbodyObject.h"
#include "GameObject/TestCollisionScene/TestGround.h"
#include "GameObject/TestGameScene/FreeCamera.h"

void TestCollisionScene::OnEnterImpl()
{
	m_MainCamera = new FreeCamera();
	AddGameObject(m_MainCamera, "MainCamera");

	player = new TestRigidbodyObject;
	AddGameObject(player);

	ground = new TestGround;
	AddGameObject(ground);
}

void TestCollisionScene::OnExitImpl()
{
}

void TestCollisionScene::UpdateImpl()
{
}
