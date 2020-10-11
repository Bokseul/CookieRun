#include "ItemManager.h"
#include "Item.h"

HRESULT ItemManager::Init()
{
	vecItem_Bonus = false;
	vecItem_Hp = false;
	vecItem_BigHp = false;

	vecItemBonus.reserve(10);
	vecItemHp.reserve(10);
	vecItemBigHp.reserve(10);

	for (int i = 0; i < 10; i++)
	{
		Item* item = new Item;
		item->Init();

		vecItemBonus.push_back(item);
	}
	for (int i = 0; i < 10; i++)
	{
		Item* item = new Item;
		item->Init();

		vecItemHp.push_back(item);
	}
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			Item* item = new Item;
			item->Init(1650 + (i * 65), 480);

			vecItemBigHp.push_back(item);
		}		
	}
	return S_OK;
}

void ItemManager::Release()
{
	for (itItem = vecItemBonus.begin(); itItem != vecItemBonus.end(); itItem++)
	{
		(*itItem)->Release();
		SAFE_DELETE(*itItem);
	}
	for (itItem = vecItemHp.begin(); itItem != vecItemHp.end(); itItem++)
	{
		(*itItem)->Release();
		SAFE_DELETE(*itItem);
	}
	for (itItem = vecItemBigHp.begin(); itItem != vecItemBigHp.end(); itItem++)
	{
		(*itItem)->Release();
		SAFE_DELETE(*itItem);
	}
	
}

void ItemManager::Update()
{
	if (vecItem_Hp)
	{
		for (itItem = vecItemHp.begin(); itItem != vecItemHp.end(); itItem++)
		{
			(*itItem)->Update();
			if (vecItemHp[vecItemHp.size() - 1]->GetHpRect().right <= 0)
			{
				vecItem_Hp = false;
				for (auto it : vecItemHp)
				{
					(it)->Init((it)->GetHppos().x, (it)->GetHppos().y);
				}
			}
		}
	}
	if (vecItem_BigHp)
	{
		for (itItem = vecItemBigHp.begin(); itItem != vecItemBigHp.end(); itItem++)
		{
			(*itItem)->Update();
			if (vecItemBigHp[vecItemBigHp.size() - 1]->GetHpRect().right <= 0)
			{
				vecItem_BigHp = false;
				for (auto it : vecItemBigHp)
				{
					(it)->Init((it)->GetBigHppos().x, (it)->GetBigHppos().y);
				}
			}
		}
	}
	if (vecItem_Bonus)
	{
		for (itItem = vecItemBonus.begin(); itItem != vecItemBonus.end(); itItem++)
		{
			(*itItem)->Update();
			if (vecItemBonus[vecItemBonus.size() - 1]->GetHpRect().right <= 0)
			{
				vecItem_BigHp = false;
				for (auto it : vecItemBonus)
				{
					(it)->Init((it)->GetItempos().x, (it)->GetItempos().y);
				}
			}
		}
	}
}

void ItemManager::Render(HDC hdc)
{
	if (vecItem_Hp)
	{
		for (itItem = vecItemHp.begin(); itItem != vecItemHp.end(); itItem++)
		{
			if ((*itItem)->GetItemCollision() == false)
			{
				(*itItem)->Render(hdc);
			}
		}
	}
	if (vecItem_BigHp)
	{
		for (itItem = vecItemBigHp.begin(); itItem != vecItemBigHp.end(); itItem++)
		{
			if ((*itItem)->GetItemCollision() == false)
			{
				(*itItem)->Render(hdc);
			}
		}
	}
	if (vecItem_Bonus)
	{
		for (itItem = vecItemBonus.begin(); itItem != vecItemBonus.end(); itItem++)
		{
			if ((*itItem)->GetItemCollision() == false)
			{
				(*itItem)->Render(hdc);
			}
		}
	}
}

ItemManager::ItemManager()
{
}

ItemManager::~ItemManager()
{
}
