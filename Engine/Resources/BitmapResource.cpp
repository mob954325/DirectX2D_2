﻿#include "BitmapResource.h"
#include "Systems/RenderSystem.h"
#include "Utils/Singleton.h"

Microsoft::WRL::ComPtr<ID2D1Bitmap1> BitmapResource::GetBitmap()
{
	return m_bitmap;
}

void BitmapResource::SetBitmap(ID2D1Bitmap1** pBitmap)
{
	m_bitmap.Attach(*pBitmap); // NOTE : 테스트 안함
}