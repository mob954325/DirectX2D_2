#pragma once
#include "pch.h"
#include "Platform/D2DRenderManager.h"
#include "BitmapResource.h"
#include <unordered_map>

class ResourceManager
{
public:
	ResourceManager(D2DRenderManager* pManager) : renderManager(pManager) {};

	std::shared_ptr<BitmapResource> CreateBitmapResource(std::wstring filePath);

private:
	D2DRenderManager* renderManager;
	std::unordered_map<std::wstring, std::weak_ptr<BitmapResource>> mapBitmap;
};