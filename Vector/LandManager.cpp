#include "LandManager.h"
#include "Land.h"

HRESULT LandManager::Init()
{
	
	vecLand_b = true;
	vecLand_b2 = false;
	vecLand_b3 = false;
	vecLand.reserve(40);
	vecLand2.reserve(40);
	vecLand3.reserve(40);

	vecLand_b4 = false;
	vecLand_b5 = false;
	vecLand_b6 = false;
	vecLand_1.reserve(40);
	vecLand2_1.reserve(40);
	vecLand3_1.reserve(40);
	
	land_level_count = 0;

	for (int i = 0; i < 40; i++)
	{
		Land* land = new Land();
		land->Init(62 + (i * 124), 640);

		vecLand.push_back(land);
	}
	for (int i = 0; i < 40; i++)
	{
		if (i > 0 && i < 35 || i == 37 || i == 38 || i == 40)
		{
			Land* land = new Land();
			land->Init(1674 + (i * 124), 640);

			vecLand2.push_back(land);
		}
		
	}
	for (int i = 0; i < 40; i++)
	{
		if (i > 0 && i < 20 || i > 22 && i < 40)
		{
			Land* land = new Land();
			land->Init(1674 + (i * 124), 640);

			land->SetLandChange(1);
			vecLand3.push_back(land);
		}
		
	}
	for (int i = 0; i < 40; i++)
	{
		if (!(i % 10 == 7))
		{
			Land* land = new Land();
			land->Init(1674 + (i * 124), 640);

			land->SetLandChange(1);
			vecLand_1.push_back(land);
		}
	}
	for (int i = 0; i < 40; i++)
	{
		if (!(i % 10 == 5))
		{
			Land* land = new Land();
			land->Init(1674 + (i * 124), 640);

			land->SetLandChange(2);
			vecLand2_1.push_back(land);
		}
	}
	for (int i = 0; i < 40; i++)
	{
		if (!(i % 10 == 3))
		{
			Land* land = new Land();
			land->Init(1674 + (i * 124), 640);

			land->SetLandChange(2);
			vecLand3_1.push_back(land);
		}
	}
	return S_OK;
}

void LandManager::Release()
{
	for (itLand = vecLand.begin(); itLand != vecLand.end(); itLand++)
	{
		(*itLand)->Release();
		SAFE_DELETE((*itLand));
	}
	vecLand.clear();

	for (itLand = vecLand2.begin(); itLand != vecLand2.end(); itLand++)
	{
		(*itLand)->Release();
		SAFE_DELETE((*itLand));
	}
	vecLand2.clear();

	for (itLand = vecLand3.begin(); itLand != vecLand3.end(); itLand++)
	{
		(*itLand)->Release();
		SAFE_DELETE((*itLand));
	}
	vecLand3.clear();
	
	for (itLand = vecLand_1.begin(); itLand != vecLand_1.end(); itLand++)
	{
		(*itLand)->Release();
		SAFE_DELETE((*itLand));
	}
	vecLand_1.clear();

	for (itLand = vecLand2_1.begin(); itLand != vecLand2_1.end(); itLand++)
	{
		(*itLand)->Release();
		SAFE_DELETE((*itLand));
	}
	vecLand2_1.clear();

	for (itLand = vecLand3_1.begin(); itLand != vecLand3_1.end(); itLand++)
	{
		(*itLand)->Release();
		SAFE_DELETE((*itLand));
	}
	vecLand3_1.clear();
}

void LandManager::Update()
{
	if (vecLand_b == true)
	{
		for (itLand = vecLand.begin(); itLand != vecLand.end(); itLand++)
		{
			(*itLand)->Update();
			if (vecLand[vecLand.size() - 1]->GetRect().right <= 1627 && vecLand[vecLand.size() - 1]->GetRect().right > 0)
			{
				vecLand_b2 = true;
			}
			if (vecLand[vecLand.size() - 1]->GetRect().right <= 0)
			{
				vecLand_b = false;
				for (auto it : vecLand)
				{
					(it)->Init();
					
				}
			}
		}
	}
	if (vecLand_b2 == true )
	{
		for (itLand = vecLand2.begin(); itLand != vecLand2.end(); itLand++)
		{
			(*itLand)->Update();
			if (vecLand2[vecLand2.size() - 1]->GetRect().right <= 1627 && vecLand2[vecLand2.size() - 1]->GetRect().right > 0)
			{
				vecLand_b3 = true;
			}
			if (vecLand2[vecLand2.size() - 1]->GetRect().right <= 0)
			{
				vecLand_b2 = false;		
				for (auto it : vecLand2)
				{
					(it)->Init((it)->GetInitPos().x, (it)->GetInitPos().y);
				}
			}
		}
	}
	if (vecLand_b3 == true)
	{
		land_level_count = 1;
		for (itLand = vecLand3.begin(); itLand != vecLand3.end(); itLand++)
		{
			(*itLand)->Update();
			if (vecLand3[vecLand3.size() - 1]->GetRect().right <= 1627 && vecLand3[vecLand3.size() - 1]->GetRect().right > 0)
			{
				vecLand_b4 = true;
			}
			if (vecLand3[vecLand3.size() - 1]->GetRect().right <= 0)
			{
				vecLand_b3 = false;
				for (auto it : vecLand3)
				{
					(it)->Init((it)->GetInitPos().x, (it)->GetInitPos().y);
				}
			}
		}
	}
	if (vecLand_b4 == true)
	{
		land_level_count = 1;
		for (itLand = vecLand_1.begin(); itLand != vecLand_1.end(); itLand++)
		{
			(*itLand)->Update();
			if (vecLand_1[vecLand_1.size() - 1]->GetRect().right <= 1627 && vecLand_1[vecLand_1.size() - 1]->GetRect().right > 0)
			{
				vecLand_b5 = true;
			}
			if (vecLand_1[vecLand_1.size() - 1]->GetRect().right <= 0)
			{
				vecLand_b4 = false;
				for (auto it : vecLand_1)
				{
					(it)->Init((it)->GetInitPos().x, (it)->GetInitPos().y);
				}
			}
		}
	}
	if (vecLand_b5 == true)
	{
		land_level_count = 2;
		for (itLand = vecLand2_1.begin(); itLand != vecLand2_1.end(); itLand++)
		{
			(*itLand)->Update();
			if (vecLand2_1[vecLand2_1.size() - 1]->GetRect().right <= 1627 && vecLand2_1[vecLand2_1.size() - 1]->GetRect().right > 0)
			{
				vecLand_b6 = true;
			}
			if (vecLand2_1[vecLand2_1.size() - 1]->GetRect().right <= 0)
			{
				vecLand_b5 = false;
				for (auto it : vecLand2_1)
				{
					(it)->Init((it)->GetInitPos().x, (it)->GetInitPos().y);
				}
			}
		}
	}
	if (vecLand_b6 == true)
	{
		land_level_count = 2;
		for (itLand = vecLand3_1.begin(); itLand != vecLand3_1.end(); itLand++)
		{
			(*itLand)->Update();
			if (vecLand3_1[vecLand3_1.size() - 1]->GetRect().right <= 1627 && vecLand3_1[vecLand3_1.size() - 1]->GetRect().right > 0)
			{
				vecLand_b2 = true;
			}
			if (vecLand3_1[vecLand3_1.size() - 1]->GetRect().right <= 0)
			{
				vecLand_b6 = false;
				for (auto it : vecLand3_1)
				{
					(it)->Init((it)->GetInitPos().x, (it)->GetInitPos().y);
				}
			}
		}
	}
}

void LandManager::Render(HDC hdc)
{
	if (vecLand_b == true)
	{
		for (itLand = vecLand.begin(); itLand != vecLand.end(); itLand++)
		{
			(*itLand)->Render(hdc);
		}
	}
	if (vecLand_b2 == true)
	{
		for (itLand = vecLand2.begin(); itLand != vecLand2.end(); itLand++)
		{
			(*itLand)->Render(hdc);
		}
	}
	if (vecLand_b3 == true)
	{
		for (itLand = vecLand3.begin(); itLand != vecLand3.end(); itLand++)
		{
			(*itLand)->Render(hdc);
		}
	}
	if (vecLand_b4 == true)
	{
		for (itLand = vecLand_1.begin(); itLand != vecLand_1.end(); itLand++)
		{
			(*itLand)->Render(hdc);
		}
	}
	if (vecLand_b5 == true)
	{
		for (itLand = vecLand2_1.begin(); itLand != vecLand2_1.end(); itLand++)
		{
			(*itLand)->Render(hdc);
		}
	}
	if (vecLand_b6 == true)
	{
		for (itLand = vecLand3_1.begin(); itLand != vecLand3_1.end(); itLand++)
		{
			(*itLand)->Render(hdc);
		}
	}
}
//
//void LandManager::AddLand(float posX, float posY)
//{
//	Land* land = new Land();
//	land->Init();
//
//	vecLand.push_back(land);
//}

LandManager::LandManager()
{
}

LandManager::~LandManager()
{
}
