#include "BoxComponent.h"
#include "D2DRenderManager.h"
#include "GameObject.h"
#include "EngineData.h"
#include "Utility/SceneManager.h"
#include "EngineData.h"

void BoxComponent::OnStart()
{
	renderManager->CreateBrush(D2D1::ColorF::Green, &brush);

	unityCoordMatrix = D2D1::Matrix3x2F::Scale(1.0f, -1.0f) * D2D1::Matrix3x2F::Translation((FLOAT)(EngineData::SceenWidth / 2), (FLOAT)(EngineData::SceenHeight / 2)); // 유니티 좌표 전환 메트릭스
}

void BoxComponent::OnDestroy()
{
	if (brush)
	{
		brush->Release();
	}
}

void BoxComponent::Render(D2DRenderManager* render)
{
	if (!isShow) return;

	if (brush) // NOTE : BitmapRenderer와 내용 중복됨
	{
		Camera* pCam = Singleton<SceneManager>::GetInstance().GetMainCamera();
		D2D1_MATRIX_3X2_F mainCamInvertMatrix = pCam ? pCam->GetInvertMatrix() : D2D1::Matrix3x2F::Identity();

		// 최종 변환 값 계산
		if (owner->transform->IsUnityCoords())
		{
			finalMatrix =
				unityRenderMatrix *					// Render Matrix
				owner->transform->ToWorldMatrix() *	// m_transform world matrix 
				mainCamInvertMatrix *				// MainCamera invert matrix
				unityCoordMatrix;					// unity coord Matrix
		}	
		else
		{
			finalMatrix =
				normalRenderMatrix *				// Render Matrix
				owner->transform->ToWorldMatrix() *	// m_transform world matrix 
				mainCamInvertMatrix;				// MainCamera invert matrix	
		}

		D2D1_POINT_2F topLeft = D2D1::Point2F(rect.left, rect.top);
		D2D1_POINT_2F bottomRight = D2D1::Point2F(rect.right, rect.bottom);

		D2D1_POINT_2F transformedTopLeft = MatrixTransform(topLeft, finalMatrix);
		D2D1_POINT_2F transformedBottomRight = MatrixTransform(bottomRight, finalMatrix);

		D2D1_RECT_F transformedRect = D2D1::RectF(
			transformedTopLeft.x,
			transformedTopLeft.y,
			transformedBottomRight.x,
			transformedBottomRight.y
		);

		render->DrawRectangle(transformedRect, brush, width, strokeStyle);
	}
}

void BoxComponent::SetRect(D2D1_RECT_F rect)
{
	this->rect = rect;
}

void BoxComponent::SetWidth(FLOAT width)
{
	this->width = width;
}

void BoxComponent::SetStyle(ID2D1StrokeStyle* style)
{
	this->strokeStyle = style;
}

void BoxComponent::SetIsShow(bool value)
{
	isShow = value;	
}

D2D1_POINT_2F BoxComponent::MatrixTransform(const D2D1_POINT_2F& point, const D2D1_MATRIX_3X2_F& matrix)
{
	return D2D1::Point2F(
		point.x * matrix._11 + point.y * matrix._21 + matrix._31,
		point.x * matrix._12 + point.y * matrix._22 + matrix._32
	);
}
