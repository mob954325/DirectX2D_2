#include "ResourceManager.h"

// NOTE : BitmapRenderer 컴포넌트에서 테스트 진행안함

std::shared_ptr<BitmapResource> ResourceManager::CreateBitmapResource(std::wstring filePath)
{
	std::shared_ptr<BitmapResource> sharedResource;
	auto it = mapBitmap.find(filePath);
	if (it == mapBitmap.end()) // 키가 존재하지 않음
	{
		std::weak_ptr<BitmapResource> weakResource;
		sharedResource = weakResource.lock();

		ID2D1Bitmap1* outBitmap = nullptr;
		renderManager->CreateBitmapFromFile(filePath.c_str(), &outBitmap);

		sharedResource->SetBitmap(&outBitmap);
	}
	else
	{
		sharedResource = it->second.lock();
	}

	return sharedResource;
}
