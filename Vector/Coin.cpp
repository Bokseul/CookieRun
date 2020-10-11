#include "Coin.h"
#include "Image.h"
#include "pch.h"

HRESULT Coin::Init()
{
	pos.x = Cpoint.x;
	pos.y = Cpoint.y;
	coinscore = 10;
	rc = GetRectToCenter(Cpoint.x, Cpoint.y, 50, 50);
	coin = ImageManager::GetSingleton()->FindImage("SilverCoin");
	gcoin = ImageManager::GetSingleton()->FindImage("GoldCoin");
	collision = false;
	coincount = 0;
	return S_OK;
}

HRESULT Coin::Init(float posX, float posY)
{
	initCPos.x = posX;
	initCPos.y = posY;
	pos.x = posX;
	pos.y = posY;
	Cpoint.x = pos.x;
	Cpoint.y = pos.y;
	coinscore = 10;
	rc = GetRectToCenter(Cpoint.x, Cpoint.y, 50, 50);
	coin = ImageManager::GetSingleton()->FindImage("SilverCoin");
	gcoin = ImageManager::GetSingleton()->FindImage("GoldCoin");
	collision = false;
	GoldTrue = false;
	coincount = 0;

	return S_OK;
}

void Coin::Release()
{
}

void Coin::Update()
{
	coincount++;
	if (coincount % 3 == 2)
	{
		rc.left -= 15;
		rc.right -= 15;
		coincount = 0;
	}
}

void Coin::Render(HDC hdc)
{
	if (GoldTrue == false)
	{
		coin->Render(hdc, rc.left, rc.top);
	}
	else if (GoldTrue == true)
	{
		gcoin->Render(hdc, rc.left, rc.right);
	}
}

Coin::Coin()
{
}

Coin::~Coin()
{
}
