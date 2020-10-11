#include "Land.h"
#include "Image.h"
#include "pch.h"


HRESULT Land::Init()
{
	pos.x = loadPosX;
	pos.y = loadPosY;
	rc = GetRectToCenter(pos.x, pos.y, 124, 140);
	level_one = ImageManager::GetSingleton()->FindImage("Land_one");
	level_two = ImageManager::GetSingleton()->FindImage("Land_two");
	level_three = ImageManager::GetSingleton()->FindImage("Land_three");
	changeLandCount = 0;

	rand = false;
	landcount = 0;
	return S_OK;
}

HRESULT Land::Init(float posX, float posY)
{
	initPos.x = posX;
	initPos.y = posY;
	pos.x =	posX;
	pos.y = posY;
	loadPosX = pos.x;
	loadPosY = pos.y;
	rc = GetRectToCenter(posX, posY, 124, 140);

	level_one = ImageManager::GetSingleton()->FindImage("Land_one");
	level_two = ImageManager::GetSingleton()->FindImage("Land_two");
	level_three = ImageManager::GetSingleton()->FindImage("Land_three");

	rand = false;
	changeLandCount = 0;

	landcount = 0;
	return S_OK;
}

void Land::Release()
{
}

void Land::Update()
{
	landcount++;
	if (landcount % 3 == 2)
	{
		rc.left -= 15;
		rc.right -= 15;
		landcount = 0;
	}

	/*if (rc.right <= 0)
	{
		rc.left = WINSIZE_X;
		rc.right = WINSIZE_X + 100;
	}*/
}

void Land::Render(HDC hdc)
{
	if (changeLandCount == 0)
	{
	//	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
		level_one->Render(hdc, rc.left, rc.top);
	}
	else if (changeLandCount == 1)
	{
		level_two->Render(hdc, rc.left, rc.top);
	//	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}
	else if (changeLandCount == 2)
	{
		level_three->Render(hdc, rc.left, rc.top);
	}
		
}

Land::Land()
{
}

Land::~Land()
{
}
