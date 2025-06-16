﻿#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#include <iostream>
#include <Windows.h>
#include <vector>
#include <assert.h>
#include <wrl.h>		// ComPtr 사용을 위한 헤더 
#include <d2d1.h>
#include <d2d1helper.h>

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

#include <d2d1_3.h> //ID2D1Factory8,ID2D1DeviceContext7
#pragma comment(lib, "d2d1.lib")

#include <dxgi1_6.h> // IDXGIFactory7
#pragma comment(lib, "dxgi.lib")

#include <wincodec.h>
#pragma comment(lib,"windowscodecs.lib")

#include <dwrite.h>
#pragma comment(lib,"dwrite.lib")

#include <d2d1effects_2.h>
#pragma comment(lib, "dxguid.lib")