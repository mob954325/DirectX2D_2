#include "Sun.h"

void Sun::Start()
{
	bitmapRenderer = AddComponent<BitmapRenderer>();

	transform->SetScale(0.1f, 0.1f);
	bitmapRenderer->SetOffSet(bitmapRenderer->GetBitmap()->GetSize().width / 2 * -1, bitmapRenderer->GetBitmap()->GetSize().height / 2 * -1);
}

void Sun::OnDestory()
{
	delete this;
}