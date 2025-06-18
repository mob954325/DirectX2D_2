﻿#pragma once
#include "framework.h"
#include "D2DRenderManager.h"
#include "ScriptSystem.h"
#include "RenderSystem.h"

using namespace Microsoft::WRL;

// 윈도우 프로그램 생성 재활용을 위한 클래스
class Application
{
public:
	D2DRenderManager* m_D2DRenderManager{};

	/// <summary>
	/// D2DRenderManager 초기화
	/// </summary>	
	virtual void Initialize();
	virtual void Uninitialize();

	virtual void CALLBACK MessageProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	virtual void Render();
	virtual void Update();
	void Run();

	int m_Width = 1024;
	int m_Height = 768;

protected:
	void ResizeSwapChainBuffers();

	ComPtr<ID3D11Device>			m_d3dDevice;
	ComPtr<IDXGISwapChain1>			m_dxgiSwapChain;
	ComPtr<ID2D1DeviceContext7>		m_d2dDeviceContext;
	ComPtr<ID2D1Bitmap1>			m_d2dBitmapTarget;

private:
	HINSTANCE		m_hInstance{};
	//std::wstring	m_windowName = L"WindowClass";
	//std::wstring	m_titleName = L"Default Title Name";
	//std::string	m_modulePath;
	//std::string	m_workingPath;
	HWND			m_hwnd{};

	bool m_isWindowOpen = false; // 윈도우가 열렸는지 확인하는 변수
	bool m_resized = false;
};
