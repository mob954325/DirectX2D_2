#pragma once
#include "pch.h"

class BitmapResource
{
public:

	Microsoft::WRL::ComPtr<ID2D1Bitmap1> GetBitmap();
	void SetBitmap(ID2D1Bitmap1** pBitmap);

protected:
	Microsoft::WRL::ComPtr<ID2D1Bitmap1> m_bitmap;	
};

