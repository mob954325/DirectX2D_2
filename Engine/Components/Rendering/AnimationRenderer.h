#pragma once
#include "Resources/SpriteDatas.h"
#include "BitmapRenderer.h"

// 

class AnimationRenderer : public BitmapRenderer
{
public:
	void Render(D2DRenderManager* manager) override;
	void GetSpriteSheet(std::wstring filePath); 
	void GetAnimationClip(std::wstring filePath);

	int GetFrame() { return frameIndex; }

	void Play() { isPlay = true; }
	void Stop() { isPlay = false; }

private:
	SpriteSheet sheet{};
	AnimationClip clip{};

	D2D1_RECT_F srcRect{};

	bool isPlay = false;

	int frameIndex = 0;
	int maxFrameIndex = 1;

	float frameTimer = 0.0f;
	float maxFrameTimer = 0.0f;
};

/// 유니티 SpriteEditor 좌표
///	(0,y) +-----------------+ (x, y)
///		  |                 |
///		  |                 |
///		  |                 |
///		  |                 |
///		  |                 |
///		  |                 |
/// (0,0) +-----------------+ (x, 0)
