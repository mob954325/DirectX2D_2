#pragma once
#include "BitmapRenderer.h"

class AnimationRenderer : public BitmapRenderer
{
public:
	void Render(D2DRenderManager* manager) override;
	void SetFrameSize(int imageWidth, int imageHeight); 
	void SetFrameCount(int row, int colum);

	void Play() { isPlay = true; }
	void Stop() { isPlay = false; }

private:
	bool isPlay = false;

	int frame = 0;
	int maxFrame = 1;

	int rowCount = 1; // 가로 길이
	int columnCount = 1; // 세로 길이

	int frameWidth = 0;
	int frameHeight = 0;

	float frameTimer = 0.0f;
	float maxFrameTimer = 0.0f;
};