#pragma once
#include "Core/Application.h"
#include "Core/Scene.h"

enum SceneType
{
	Menu = 0,
	Game
};

class DemoGameApp : public Application
{
public:
	void Initialize() override;
	void Render() override;
	void Uninitialize() override;
	void Update() override;

	//Transform* camera;
	//Sun* m_Sun;
	//BitmapRenderer* m_Earth;
	//BitmapRenderer* m_Moon;

private:

	//void FlagInputUpdate();		// 인풋으로 플래그 전환 내용 업데이트
	//void MoveCamera();			// 카메라 이동 관리
	//void SolarSystemUpdate();	// 태양계 이동 관리
	//void Reset();				// 프로젝트 초기 상태로 되돌리기

	//std::vector<GameObject*> objects;
	//
	//float baseRotateSpeed = 360.0f;
	//float cameraMoveSpeed = 10.0f;
	//
	//float sunRotateRatio = 0.1f;
	//float earthRotateRatio = 0.5f;
	//float moonRotateRatio = 0.8f;
	//
	//bool isSolarSystemMove = true; // 태양계 움직임 여부
};