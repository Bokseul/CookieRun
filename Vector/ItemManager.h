#pragma once
#include "GameNode.h"

class Item;
class ItemManager : public GameNode
{
private:
	vector<Item*> vecItemBonus;
	vector<Item*> vecItemHp;
	vector<Item*> vecItemBigHp;
	vector<Item*>::iterator itItem;

	bool vecItem_Bonus;
	bool vecItem_Hp;
	bool vecItem_BigHp;
public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	vector<Item*>* GetHpItem() { return &vecItemHp; }

	bool GetvecHpItem() { return vecItem_Hp; }
	void SetvecHpItem(bool vecItem_hp) { vecItem_Hp = vecItem_hp; }
	ItemManager();
	virtual ~ItemManager();
};

