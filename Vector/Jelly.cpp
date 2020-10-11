#include "Jelly.h"
#include "Image.h"
#include "pch.h"

HRESULT Jelly::Init()
{
	pos.x = Jpoint.x;
	pos.y = Jpoint.y;
	jellyscore = 33;
	rc = GetRectToCenter(Jpoint.x, Jpoint.y, 50, 50);
	jelly = ImageManager::GetSingleton()->FindImage("Jelly_lv1");
	collision = false;
	jellycount = 0;
	return S_OK;
}

HRESULT Jelly::Init(float posX, float posY)
{
	initJPos.x = posX;
	initJPos.y = posY;
	pos.x = posX;
	pos.y = posY;
	Jpoint.x = pos.x;
	Jpoint.y = pos.y;
	jellyscore = 33;
	rc = GetRectToCenter(Jpoint.x, Jpoint.y, 62, 62);
	jelly = ImageManager::GetSingleton()->FindImage("Jelly_lv1");
	collision = false;
	jellycount = 0;

	return S_OK;
}

void Jelly::Release()
{
}

void Jelly::Update()
{
	jellycount++;
	if (jellycount % 3 == 2)
	{
		rc.left -= 15;
		rc.right -= 15;
		jellycount = 0;
	}
}

void Jelly::Render(HDC hdc)
{
	if (jelly)
	{
		jelly->Render(hdc, rc.left, rc.top);
		//Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}
}

Jelly::Jelly()
{
}

Jelly::~Jelly()
{
}
