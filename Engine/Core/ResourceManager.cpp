#include "ResourceManager.h"

// NOTE : BitmapRenderer 컴포넌트에서 테스트 진행안함

std::shared_ptr<BitmapResource> ResourceManager::CreateBitmapResource(std::wstring filePath)
{
	std::shared_ptr<BitmapResource> sharedResource;
	auto it = mapBitmap.find(filePath);

	if (it == mapBitmap.end() || it->second.expired())
	{
		sharedResource = std::make_shared<BitmapResource>();

		ID2D1Bitmap1* outBitmap = nullptr;
		renderManager->CreateBitmapFromFile(filePath.c_str(), &outBitmap);
		sharedResource->SetBitmap(&outBitmap);
		mapBitmap[filePath] = sharedResource;
	}
	else
	{
		sharedResource = it->second.lock();
	}

	return sharedResource;
}

void ResourceManager::ReleaseAllResource()
{
	for (auto resource : mapBitmap)
	{
		// resource release		
	}
}
