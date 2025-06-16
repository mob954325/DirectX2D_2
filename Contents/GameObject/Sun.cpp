#include "Sun.h"

// NOTE : D2DManager에서 가져오는 bitmap데이터를 어떻게 가져올것인가?
// NOTE : GameSystem을 어디서 가져오지?

void Sun::Start()
{
	bitmapRenderer = AddComponent<BitmapRenderer>();

	transform->SetScale(0.1f, 0.1f);
	ComPtr<ID2D1Bitmap1> outSunBitmap;
	HRESULT hr = renderManager->CreateBitmapFromFile(L"../Resource/Sun.png", outSunBitmap.GetAddressOf());
	bitmapRenderer->SetBitmap(outSunBitmap);
	bitmapRenderer->SetOffSet(outSunBitmap.Get()->GetSize().width / 2 * -1, outSunBitmap.Get()->GetSize().height / 2 * -1);
	assert(SUCCEEDED(hr));
}