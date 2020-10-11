#include "Image.h"
#include "KiwiCookie.h"
#include "pch.h"
#include "GuageBar.h"
#include "Item.h"

HRESULT GuageBar::Init()
{
	pos.x = 100;
	pos.y = 100;

	Guage = 0.0f;
	BonusGuage = 1000.0f;
	skillplay = false;

	cookie_hp = ImageManager::GetSingleton()->FindImage("Cookie_Hp");
	cookie_hp_bar = ImageManager::GetSingleton()->FindImage("Cookie_Hp_Bar");
	cookie_hp_push = ImageManager::GetSingleton()->FindImage("Cookie_Hp_PuhsBar");
	cookie_gage = ImageManager::GetSingleton()->FindImage("Cookie_Gage");
	cookie_gage_bar = ImageManager::GetSingleton()->FindImage("Cookie_Gage_Bar");
	cookie_hp_state = ImageManager::GetSingleton()->FindImage("Cookie_Hp_state");

	return S_OK;
}

void GuageBar::Release()
{
}

void GuageBar::Update()
{
	if (kiwi->GetLife()==true)
	{
		countdown++;
		if (countdown % 3 == 2 && kiwi->GetCookieHp() > 0)
		{
			if (Guage >= 1000.0f)
			{
				skillplay = true;
			}
			if (Guage <= 0.0f)
			{
				skillplay = false;
			}
			if (skillplay == true)
			{
				Guage -= 10.0f;
			}
			if (skillplay == false)
			{
				Guage += 0.01f;
			}
			kiwi->SetCookiHp(kiwi->GetCookieHp() - 0.3f);
			countdown = 0;
		}
		if (kiwi->GetCookieHp() <= 0.0f)
		{
			kiwi->SetLife(false);
		}
	}
	
}

void GuageBar::Render(HDC hdc)
{
	if (cookie_hp_bar)
	{
		cookie_hp_bar->Render(hdc, 40, 80);
	}
	if (cookie_hp)
	{
		cookie_hp->Render(hdc, 40, 82, kiwi->GetCookieHp());
	}
	if (cookie_hp_state)
	{
		cookie_hp_state->Render(hdc, 20, 70);
	}
	if (cookie_gage_bar)
	{
		cookie_gage_bar->Render(hdc, kiwi->GetKiwipos().x - 42, kiwi->GetKiwipos().y - 100);
	}
	if (cookie_gage)
	{
		cookie_gage->Render(hdc, kiwi->GetKiwipos().x - 40, kiwi->GetKiwipos().y - 98, Guage);
	}
}

GuageBar::GuageBar()
{
}

GuageBar::~GuageBar()
{
}
