#pragma once
#include "GameNode.h"

class Item;
class KiwiCookie;
class Image;
class GuageBar : public GameNode
{
private:
	
	Image* cookie_hp_bar;
	Image* cookie_hp;
	Image* cookie_hp_push;
	Image* cookie_gage_bar;
	Image* cookie_gage;
	Image* cookie_hp_state;
	KiwiCookie* kiwi;
	Item* itemstate;

	float CHP;
	float Guage;
	float BonusGuage;
	int countdown;
	bool skillplay;

public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	void SetKiwi(KiwiCookie* _kiwi) { kiwi = _kiwi; }
	void SetItem(Item* _item) { itemstate = _item; }

	GuageBar();
	virtual ~GuageBar();
};

