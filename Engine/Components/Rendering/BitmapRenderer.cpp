#include "BitmapRenderer.h"
#include "Platform/D2DRenderManager.h"
#include "Components/Base/GameObject.h"
#include "Scene/SceneManager.h"
#include "Resources/ResourceManager.h"
#include "Components/Camera/Camera.h"
#include "Datas/EngineData.h"
#include "Resources/BitmapResource.h"

void BitmapRenderer::Render(D2DRenderManager* manager)
{
	if (m_bitmapResource != nullptr)
	{
		// CalculateFinalMatrix();
		D2D1_MATRIX_3X2_F mat = owner->transform->GetFinalMatrix();

		manager->SetBitmapTransform(mat);
		manager->DrawBitmap(m_bitmapResource->GetBitmap());
	}
}

void BitmapRenderer::OnStart()
{

}

void BitmapRenderer::OnDestroy()
{
	m_bitmapResource.reset();
}

void BitmapRenderer::CreateBitmapResource(std::wstring filePath)
{
	m_bitmapResource = resourceManager->CreateBitmapResource(filePath);
}

std::shared_ptr<BitmapResource> BitmapRenderer::GetResource()
{
	return m_bitmapResource;
}