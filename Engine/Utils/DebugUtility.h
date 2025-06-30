#pragma once
#include "pch.h"
#include "Utils/Singleton.h"

class DebugUtility : public Singleton<DebugUtility>
{
public:
	void GetDxgiAdapter(Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice, Microsoft::WRL::ComPtr<IDXGIDevice> dxgiDevice);

	std::string FormatBytes(UINT64 bytes);
	void PrintMemoryUsage();
	static void Print(std::wstring str);

private:
	Microsoft::WRL::ComPtr<IDXGIAdapter3> dxgiAdapter;
};