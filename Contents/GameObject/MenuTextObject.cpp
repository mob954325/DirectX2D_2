#include "MenuTextObject.h"

void MenuTextObject::Start()
{
	textRenderer = AddComponent<TextRenderer>();
	textRenderer->SetText(L"aaaa");
	textRenderer->SetPosition(20, 20);
}

void MenuTextObject::OnDestory()
{

}
