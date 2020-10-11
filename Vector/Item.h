#pragma once
#include "GameNode.h"

class Image;
class Item : public GameNode
{
private:
	/*Image* bonus_B;
	Image* bonus_O;
	Image* bonus_N;
	Image* bonus_U;
	Image* bonus_S;
	Image* bonus_T;
	Image* bonus_I;
	Image* bonus_M;
	Image* bonus_E;*/
	Image* HpPotion;
	Image* HpBigPotion;
	Image* bonus_All;
	POINT* bonus_pos;
	RECT Item_rc;
	RECT Hp_rc;
	RECT BigHp_rc;

	/*bool bonusCk_B;
	bool bonusCk_O;
	bool bonusCk_N;
	bool bonusCk_U;
	bool bonusCk_S;
	bool bonusCk_T;
	bool bonusCk_I;
	bool bonusCk_M;
	bool bonusCk_E;*/
	bool bonusCk_All;
	bool hpCk;
	bool bighpCk;
	bool collision;

	int bonuscount;
	int hpcount;
	int bighpcount;
	POINT initHppos;
	POINT initBigHppos;
	POINT initBonuspos;

public:
	virtual HRESULT Init();
	virtual HRESULT Init(float posX, float posY);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	bool GetItemCollision() { return collision; }
	bool GetBonusTimeCheck() { return bonusCk_All; }
	void SetHp(bool _hpCk) { hpCk = _hpCk; }
	RECT GetItemRect() { return Item_rc; }
	RECT GetHpRect() { return Hp_rc; }
	RECT GetBigHpRect() { return BigHp_rc; }
	POINT GetItempos() { return initHppos; }
	POINT GetHppos() { return initHppos; }
	POINT GetBigHppos() { return initBigHppos; }

	Item();
	virtual ~Item();
};

