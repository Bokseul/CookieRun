#include "RunningScene.h"
#include "Image.h"
#include "Land.h"
#include "LandManager.h"
#include "Obstacle.h"
#include "ObstacleManager.h"
#include "Jelly.h"
#include "Coin.h"
#include "PointManager.h"
#include "Cookie.h"
#include "KiwiCookie.h"
#include "GuageBar.h"
#include "Item.h"
#include "ItemManager.h"

HRESULT RunningScene::Init()
{
	Cookie_life = true;
	collision_Land = false;
	collision_Land_Down = false;
	CookieisCollision = false;
	CookieinvincibilityTime = 0;
	currFrameX = count = 0;
	currFrameY = 0;

	stage1Bg = ImageManager::GetSingleton()->FindImage("Stage1");
	stage2Bg = ImageManager::GetSingleton()->FindImage("Stage2");
	stage3Bg = ImageManager::GetSingleton()->FindImage("Stage3");
	bonusback = ImageManager::GetSingleton()->FindImage("Bonus_back");
	bonusfront = ImageManager::GetSingleton()->FindImage("Bonus_front");

	landMgr = new LandManager();
	landMgr->Init();

	obstacleMgr = new ObstacleManager();
	obstacleMgr->Init();

	ptMgr = new PointManager();
	ptMgr->Init();
	ptMgr->SetObstacleSetting(obstacleMgr);

	kiwicookie = new KiwiCookie();
	kiwicookie->Init();
	kiwicookie->SetCookieGuage(guage);

	guage = new GuageBar();
	guage->Init();
	guage->SetKiwi(kiwicookie);

	return S_OK;
}

void RunningScene::Release()
{
	guage->Release();
	SAFE_DELETE(guage);

	landMgr->Release();
	SAFE_DELETE(landMgr);

	obstacleMgr->Release();
	SAFE_DELETE(obstacleMgr);

	ptMgr->Release();
	SAFE_DELETE(ptMgr);

	kiwicookie->Release();
	SAFE_DELETE(kiwicookie);
}

void RunningScene::Update()
{
	if (stage1Bg || stage2Bg || stage3Bg)
	{
		sb++;
		if (sb > WINSIZE_X)
		{
			sb = 0;
		}
	}
	/*if (hpMgr)
	{
		hpMgr->Update();
	}*/
	if (guage)
	{
		guage->Update();
	}
	if (kiwicookie)
	{
		kiwicookie->Update();
	}
	if (landMgr)
	{
		landMgr->Update();
	}
	if (obstacleMgr)
	{
		obstacleMgr->Update();
	}
	if (ptMgr)
	{
		ptMgr->Update();
	}
	if (CookieisCollision == true)
	{
		CookieinvincibilityTime++;
		if (CookieinvincibilityTime == 1)
		{
			kiwicookie->SetMotion(Hit);
			kiwicookie->SetHitState(true);
		}
		if (CookieinvincibilityTime > 100)
		{
			kiwicookie->SetMotion(Idle);
			kiwicookie->SetHitState(false);
			CookieinvincibilityTime = 0;
			CookieisCollision = false;
		}
	}
	if ((*landMgr).GetvecLand_b())
	{
		for (int i = 0; i < (*landMgr->GetLand1()).size(); i++)
		{
			if (CheckRectCollision((*landMgr).GetLand1()->at(i)->GetRect(), kiwicookie->GetKiwiCookie()) == true)
			{
				if ((*landMgr).GetLand1()->at(i)->GetRect().top > kiwicookie->GetKiwiCookie().top)
				{
					kiwicookie->SetmaxjumpPw(55);
					collision_Land = true;
					kiwicookie->SetMotion(Idle);
					kiwicookie->SetairState(false);
					kiwicookie->SetdoublejumpState(false);
					kiwicookie->SetKiwipos({ kiwicookie->GetKiwipos().x, (*landMgr).GetLand1()->at(i)->GetRect().top - 50 });
					kiwicookie->SetKiwiCookie(GetRectToCenter(kiwicookie->GetKiwipos().x, kiwicookie->GetKiwipos().y, 50, 100));
				}
			}
		}
	}
	if ((*landMgr).GetvecLand_b2())
	{
		for (int i = 0; i < (*landMgr->GetLand2()).size(); i++)
		{
			if (CheckRectCollision((*landMgr).GetLand2()->at(i)->GetRect(), kiwicookie->GetKiwiCookie()) == true)
			{
				if ((*landMgr).GetLand2()->at(i)->GetRect().top > kiwicookie->GetKiwiCookie().top)
				{
					kiwicookie->SetmaxjumpPw(55);
					collision_Land = true;
					kiwicookie->SetMotion(Idle);
					kiwicookie->SetairState(false);
					kiwicookie->SetdoublejumpState(false);
					kiwicookie->SetKiwipos({ kiwicookie->GetKiwipos().x, (*landMgr).GetLand2()->at(i)->GetRect().top - 50 });
					kiwicookie->SetKiwiCookie(GetRectToCenter(kiwicookie->GetKiwipos().x, kiwicookie->GetKiwipos().y, 50, 100));
				}
			}
		}
	}
	if ((*landMgr).GetvecLand_b3())
	{
		for (int i = 0; i < (*landMgr->GetLand3()).size(); i++)
		{
			if (CheckRectCollision((*landMgr).GetLand3()->at(i)->GetRect(), kiwicookie->GetKiwiCookie()) == true)
			{
				if ((*landMgr).GetLand3()->at(i)->GetRect().top > kiwicookie->GetKiwiCookie().top)
				{
					kiwicookie->SetmaxjumpPw(55);
					collision_Land = true;
					kiwicookie->SetMotion(Idle);
					kiwicookie->SetairState(false);
					kiwicookie->SetdoublejumpState(false);
					kiwicookie->SetKiwipos({ kiwicookie->GetKiwipos().x, (*landMgr).GetLand3()->at(i)->GetRect().top - 50 });
					kiwicookie->SetKiwiCookie(GetRectToCenter(kiwicookie->GetKiwipos().x, kiwicookie->GetKiwipos().y, 50, 100));
				}
			}
		}
	}
	if ((*landMgr).GetvecLand_b4())
	{
		for (int i = 0; i < (*landMgr->GetLand1_1()).size(); i++)
		{
			if (CheckRectCollision((*landMgr).GetLand1_1()->at(i)->GetRect(), kiwicookie->GetKiwiCookie()) == true)
			{
				if ((*landMgr).GetLand1_1()->at(i)->GetRect().top > kiwicookie->GetKiwiCookie().top)
				{
					kiwicookie->SetmaxjumpPw(55);
					collision_Land = true;
					kiwicookie->SetMotion(Idle);
					kiwicookie->SetairState(false);
					kiwicookie->SetdoublejumpState(false);
					kiwicookie->SetKiwipos({ kiwicookie->GetKiwipos().x, (*landMgr).GetLand1_1()->at(i)->GetRect().top - 50 });
					kiwicookie->SetKiwiCookie(GetRectToCenter(kiwicookie->GetKiwipos().x, kiwicookie->GetKiwipos().y, 50, 100));
				}
			}
		}
	}
	if ((*landMgr).GetvecLand_b5())
	{
		for (int i = 0; i < (*landMgr->GetLand2_1()).size(); i++)
		{
			if (CheckRectCollision((*landMgr).GetLand2_1()->at(i)->GetRect(), kiwicookie->GetKiwiCookie()) == true)
			{
				if ((*landMgr).GetLand2_1()->at(i)->GetRect().top > kiwicookie->GetKiwiCookie().top)
				{
					kiwicookie->SetmaxjumpPw(55);
					collision_Land = true;
					kiwicookie->SetMotion(Idle);
					kiwicookie->SetairState(false);
					kiwicookie->SetdoublejumpState(false);
					kiwicookie->SetKiwipos({ kiwicookie->GetKiwipos().x, (*landMgr).GetLand2_1()->at(i)->GetRect().top - 50 });
					kiwicookie->SetKiwiCookie(GetRectToCenter(kiwicookie->GetKiwipos().x, kiwicookie->GetKiwipos().y, 50, 100));
				}
			}
		}
	}
	if ((*landMgr).GetvecLand_b6())
	{
		for (int i = 0; i < (*landMgr->GetLand3_1()).size(); i++)
		{
			if (CheckRectCollision((*landMgr).GetLand3_1()->at(i)->GetRect(), kiwicookie->GetKiwiCookie()) == true)
			{
				if ((*landMgr).GetLand3_1()->at(i)->GetRect().top > kiwicookie->GetKiwiCookie().top)
				{
					kiwicookie->SetmaxjumpPw(55);
					collision_Land = true;
					kiwicookie->SetMotion(Idle);
					kiwicookie->SetairState(false);
					kiwicookie->SetdoublejumpState(false);
					kiwicookie->SetKiwipos({ kiwicookie->GetKiwipos().x, (*landMgr).GetLand3_1()->at(i)->GetRect().top - 50 });
					kiwicookie->SetKiwiCookie(GetRectToCenter(kiwicookie->GetKiwipos().x, kiwicookie->GetKiwipos().y, 50, 100));
				}
			}
		}
	}
	if ((*obstacleMgr).GetvecObstacle1())
	{
		for (int i = 0; i < (*obstacleMgr->GetObstacle1()).size(); i++)
		{
			if (((CheckRectCollision((*obstacleMgr).GetObstacle1()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true) && (CookieisCollision == false))
			{
				kiwicookie->SetCookiHp(kiwicookie->GetCookieHp() - 100.0f);
				CookieisCollision = true;
			}
		}
	}
	if ((*obstacleMgr).GetvecObstacle2())
	{
		for (int i = 0; i < (*obstacleMgr->GetObstacle2()).size(); i++)
		{
			if (((CheckRectCollision((*obstacleMgr).GetObstacle2()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true) && (CookieisCollision == false))
			{
				kiwicookie->SetCookiHp(kiwicookie->GetCookieHp() - 50.0f);
				CookieisCollision = true;
			}
		}
	}
	if ((*obstacleMgr).GetvecObstacle3())
	{
		for (int i = 0; i < (*obstacleMgr->GetObstacle3()).size(); i++)
		{
			if (((CheckRectCollision((*obstacleMgr).GetObstacle3()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true) && (CookieisCollision == false))
			{
				kiwicookie->SetCookiHp(kiwicookie->GetCookieHp() - 50.0f);
				CookieisCollision = true;
			}
		}
	}
	if ((*obstacleMgr).GetvecObstacle1_1())
	{
		for (int i = 0; i < (*obstacleMgr->GetObstacle1_1()).size(); i++)
		{
			if (((CheckRectCollision((*obstacleMgr).GetObstacle1_1()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true) && (CookieisCollision == false))
			{
				kiwicookie->SetCookiHp(kiwicookie->GetCookieHp() - 50.0f);
				CookieisCollision = true;
			}
		}
	}
	if ((*obstacleMgr).GetvecObstacle2_1())
	{
		for (int i = 0; i < (*obstacleMgr->GetObstacle2_1()).size(); i++)
		{
			if (((CheckRectCollision((*obstacleMgr).GetObstacle2_1()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true) && (CookieisCollision == false))
			{
				kiwicookie->SetCookiHp(kiwicookie->GetCookieHp() - 50.0f);
				CookieisCollision = true;
			}
		}
	}
	if ((*obstacleMgr).GetvecObstacle3_1())
	{
		for (int i = 0; i < (*obstacleMgr->GetObstacle3_1()).size(); i++)
		{
			if (((CheckRectCollision((*obstacleMgr).GetObstacle3_1()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true) && (CookieisCollision == false))
			{
				kiwicookie->SetCookiHp(kiwicookie->GetCookieHp() - 50.0f);
				CookieisCollision = true;
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b1())
	{
		for (int i = 0; i < (*ptMgr->GetJelly1()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly1()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly1()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b2())
	{
		for (int i = 0; i < (*ptMgr->GetJelly2()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly2()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly2()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b3())
	{
		for (int i = 0; i < (*ptMgr->GetJelly3()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly3()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly3()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b4())
	{
		for (int i = 0; i < (*ptMgr->GetJelly4()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly4()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly4()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b5())
	{
		for (int i = 0; i < (*ptMgr->GetJelly5()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly5()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly5()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b6())
	{
		for (int i = 0; i < (*ptMgr->GetJelly6()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly6()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly6()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b7())
	{
		for (int i = 0; i < (*ptMgr->GetJelly7()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly7()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly7()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b8())
	{
		for (int i = 0; i < (*ptMgr->GetJelly8()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly8()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly8()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b9())
	{
		for (int i = 0; i < (*ptMgr->GetJelly9()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly9()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly9()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b10())
	{
		for (int i = 0; i < (*ptMgr->GetJelly10()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly10()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly10()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b11())
	{
		for (int i = 0; i < (*ptMgr->GetJelly11()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly11()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly11()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b_1())
	{
		for (int i = 0; i < (*ptMgr->GetJelly_1()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly_1()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly_1()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b_2())
	{
		for (int i = 0; i < (*ptMgr->GetJelly_2()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly_2()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly_2()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b_3())
	{
		for (int i = 0; i < (*ptMgr->GetJelly_3()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly_3()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly_3()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b_4())
	{
		for (int i = 0; i < (*ptMgr->GetJelly_4()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly_4()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly_4()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b_5())
	{
		for (int i = 0; i < (*ptMgr->GetJelly_5()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly_5()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly_5()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b_6())
	{
		for (int i = 0; i < (*ptMgr->GetJelly_6()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly_6()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly_6()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b_7())
	{
		for (int i = 0; i < (*ptMgr->GetJelly_7()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly_7()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly_7()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b_8())
	{
		for (int i = 0; i < (*ptMgr->GetJelly_8()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly_8()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly_8()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b_9())
	{
		for (int i = 0; i < (*ptMgr->GetJelly_9()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly_9()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly_9()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b_10())
	{
		for (int i = 0; i < (*ptMgr->GetJelly_10()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly_10()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly_10()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecJelly_b_11())
	{
		for (int i = 0; i < (*ptMgr->GetJelly_11()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetJelly_11()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetJelly_11()->at(i)->SetIsCollision(true);
			}
		}
	}
	if ((*ptMgr).GetvecCoin_b1())
	{
		for (int i = 0; i < (*ptMgr->GetCoin1()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetCoin1()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetCoin1()->at(i)->SetIsCollision_C(true);
			}
		}
	}
	if ((*ptMgr).GetvecCoin_b2())
	{
		for (int i = 0; i < (*ptMgr->GetCoin2()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetCoin2()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetCoin2()->at(i)->SetIsCollision_C(true);
			}
		}
	}
	if ((*ptMgr).GetvecCoin_b3())
	{
		for (int i = 0; i < (*ptMgr->GetCoin3()).size(); i++)
		{
			if ((CheckRectCollision((*ptMgr).GetCoin3()->at(i)->GetRect(), kiwicookie->GetKiwiCookie())) == true)
			{
				(*ptMgr).GetCoin3()->at(i)->SetIsCollision_C(true);
			}
		}
	}

	if (kiwicookie->GetLife() == false)
	{
		SceneManager::GetSingleton()->ChangeScene("Å¸ÀÌÆ²");
	}
}

void RunningScene::Render(HDC hdc)
{
	TimeManager::GetSingleton()->Render(hdc);

	if (kiwicookie->GetLife() == true)
	{
		if (landMgr->GetLand_levelchange() == 0)
		{
			stage1Bg->Render(hdc, 0, 0, sb);
		}
		else if (landMgr->GetLand_levelchange() == 1)
		{
			stage2Bg->Render(hdc, 0, 0, sb);
		}
		else if (landMgr->GetLand_levelchange() == 2)
		{
			stage3Bg->Render(hdc, 0, 0, sb);
		}
		if (landMgr)
		{
			landMgr->Render(hdc);
		}
		if (obstacleMgr)
		{
			obstacleMgr->Render(hdc);
		}
		if (ptMgr)
		{
			ptMgr->Render(hdc);
		}
		if (bonusback)
		{
			bonusback->Render(hdc, 20, 20);
		}
		if (guage)
		{
			guage->Render(hdc);
		}
		if (kiwicookie)
		{
			kiwicookie->Render(hdc);
		}
		
	}
}


RunningScene::RunningScene()
{
}

RunningScene::~RunningScene()
{
}
