#include "Item.h"
#include "Image.h"
#include "pch.h"

HRESULT Item::Init()
{
	bonuscount = 0;
	Item_rc = GetRectToCenter(pos.x, pos.y, 65, 65);
	Hp_rc = GetRectToCenter(pos.x, pos.y, 62, 62);
	BigHp_rc = GetRectToCenter(pos.x, pos.y, 62, 62);

	/*bonus_B = ImageManager::GetSingleton()->FindImage("BonusTime_B");
	bonus_O = ImageManager::GetSingleton()->FindImage("BonusTime_O");
	bonus_N = ImageManager::GetSingleton()->FindImage("BonusTime_N");
	bonus_U = ImageManager::GetSingleton()->FindImage("BonusTime_U");
	bonus_S = ImageManager::GetSingleton()->FindImage("BonusTime_S");
	bonus_T = ImageManager::GetSingleton()->FindImage("BonusTime_T");
	bonus_I = ImageManager::GetSingleton()->FindImage("BonusTime_I");
	bonus_M = ImageManager::GetSingleton()->FindImage("BonusTime_M");
	bonus_E = ImageManager::GetSingleton()->FindImage("BonusTime_E");*/
	bonus_All = ImageManager::GetSingleton()->FindImage("BonusTime_All");
	HpPotion = ImageManager::GetSingleton()->FindImage("Item_Hp");
	HpBigPotion = ImageManager::GetSingleton()->FindImage("Item_BigHp");

	/*bonusCk_B = false;
	bonusCk_O = false;
	bonusCk_N = false;
	bonusCk_U = false;
	bonusCk_S = false;
	bonusCk_T = false;
	bonusCk_I = false;
	bonusCk_M = false;
	bonusCk_E = false;*/
	bonusCk_All = false;
	hpCk = false;
	bighpCk = false;
	collision = false;

	return S_OK;
}

HRESULT Item::Init(float posX, float posY)
{
	pos.x = posX;
	pos.y = posY;
	initBonuspos.x = posX;
	initBonuspos.y = posY;
	initHppos.x = posX;
	initHppos.y = posY;
	initBigHppos.x = posX;
	initBigHppos.y = posY;
	collision = false;
	bonuscount = 0;
	hpcount = 0;
	bighpcount = 0;
	Item_rc = GetRectToCenter(pos.x, pos.y, 65, 65);
	Hp_rc = GetRectToCenter(pos.x, pos.y, 62, 62);
	BigHp_rc = GetRectToCenter(pos.x, pos.y, 62, 62);

	/*bonus_B = ImageManager::GetSingleton()->FindImage("BonusTime_B");
	bonus_O = ImageManager::GetSingleton()->FindImage("BonusTime_O");
	bonus_N = ImageManager::GetSingleton()->FindImage("BonusTime_N");
	bonus_U = ImageManager::GetSingleton()->FindImage("BonusTime_U");
	bonus_S = ImageManager::GetSingleton()->FindImage("BonusTime_S");
	bonus_T = ImageManager::GetSingleton()->FindImage("BonusTime_T");
	bonus_I = ImageManager::GetSingleton()->FindImage("BonusTime_I");
	bonus_M = ImageManager::GetSingleton()->FindImage("BonusTime_M");
	bonus_E = ImageManager::GetSingleton()->FindImage("BonusTime_E");*/
	bonus_All = ImageManager::GetSingleton()->FindImage("BonusTime_All");
	HpPotion = ImageManager::GetSingleton()->FindImage("Item_Hp");
	HpBigPotion = ImageManager::GetSingleton()->FindImage("Item_BigHp");

	/*bonusCk_B = false;
	bonusCk_O = false;
	bonusCk_N = false;
	bonusCk_U = false;
	bonusCk_S = false;
	bonusCk_T = false;
	bonusCk_I = false;
	bonusCk_M = false;
	bonusCk_E = false;*/
	bonusCk_All = false;
	hpCk = false;
	bighpCk = false;
	collision = false;

	return S_OK;
}

void Item::Release()
{
}

void Item::Update()
{
	/*if (bonusCk_B || bonusCk_O || bonusCk_N || bonusCk_U || bonusCk_S || bonusCk_T || bonusCk_I || bonusCk_M || bonusCk_E)
	{
		bonuscount++;
		if (bonuscount % 3 == 2)
		{
			Item_rc.left += 15;
			Item_rc.right += 15;
			bonuscount = 0;
		}
	}*/
	if (bonusCk_All)
	{
		bonuscount++;
		if (bonuscount % 3 == 2)
		{
			Item_rc.left += 15;
			Item_rc.right += 15;
			bonuscount = 0;
		}
	}
	if (hpCk)
	{
		hpcount++;
		if (hpcount % 3 == 2)
		{
			Hp_rc.left += 15;
			Hp_rc.right += 15;
			hpcount = 0;
		}
	}
	if (bighpCk)
	{
		bighpcount++;
		if (bighpcount % 3 == 2)
		{
			BigHp_rc.left += 15;
			BigHp_rc.right += 15;
			bighpcount = 0;
		}
	}
}

void Item::Render(HDC hdc)
{
	/*if (bonusCk_B)
	{
		bonus_B->Render(hdc, pos.x, pos.y);
	}
	if (bonusCk_O)
	{
		bonus_O->Render(hdc, pos.x, pos.y);
	}
	if (bonusCk_N)
	{
		bonus_N->Render(hdc, pos.x, pos.y);
	}
	if (bonusCk_U)
	{
		bonus_U->Render(hdc, pos.x, pos.y);
	}
	if (bonusCk_S)
	{
		bonus_S->Render(hdc, pos.x, pos.y);
	}
	if (bonusCk_T)
	{
		bonus_T->Render(hdc, pos.x, pos.y);
	}
	if (bonusCk_I)
	{
		bonus_I->Render(hdc, pos.x, pos.y);
	}
	if (bonusCk_M)
	{
		bonus_M->Render(hdc, pos.x, pos.y);
	}
	if (bonusCk_E)
	{
		bonus_E->Render(hdc, pos.x, pos.y);
	}*/
	if (collision == false)
	{
		if (bonusCk_All)
		{
			bonus_All->Render(hdc, pos.x, pos.y);
		}
		if (hpCk)
		{
			HpPotion->Render(hdc, pos.x, pos.y);
		}
		if (bighpCk)
		{
			HpBigPotion->Render(hdc, pos.x, pos.y);
		}
	}
	
}

Item::Item()
{
}

Item::~Item()
{
}
