#include "MainGame.h"
#include "macroFunction.h"
#include "Image.h"
#include "TitleScene.h"
#include "LoadingScene.h"
#include "IntroScene.h"
#include "RunningScene.h"
#include "StandbyScene.h"

HRESULT MainGame::Init()
{
	hdc = GetDC(g_hWnd);

	// backBuffer
	backBuffer = new Image;
	backBuffer->Init(WINSIZE_X, WINSIZE_Y);

	KeyManager::GetSingleton()->Init();
	ImageManager::GetSingleton()->Init();
	TimeManager::GetSingleton()->Init();
	SoundManager::GetSingleton()->Init();
	SceneManager::GetSingleton()->Init();

	titleScene = new TitleScene;
	SceneManager::GetSingleton()->AddScene("타이틀", titleScene); //이닛이 된다.

	standbyScene = new StandbyScene;
	SceneManager::GetSingleton()->AddScene("대기실", standbyScene);

	runningScene = new RunningScene;
	SceneManager::GetSingleton()->AddScene("달리기게임", runningScene);

	introScene = new IntroScene;
	SceneManager::GetSingleton()->AddScene("인트로", introScene);

	loadingScene = new LoadingScene;
	SceneManager::GetSingleton()->AddLoadingScene("로딩1", loadingScene);

	SceneManager::GetSingleton()->ChangeScene("인트로");

	ImageManager::GetSingleton()->AddImage("Stage1", "Cookbg/stage1.bmp", WINSIZE_X, WINSIZE_Y);
	ImageManager::GetSingleton()->AddImage("Stage2", "Cookbg/stage2.bmp", WINSIZE_X, WINSIZE_Y);
	ImageManager::GetSingleton()->AddImage("Stage3", "Cookbg/stage3.bmp", WINSIZE_X, WINSIZE_Y);
	ImageManager::GetSingleton()->AddImage("Land_one", "Cookieland/leveloneLand.bmp", 124, 140, true, RGB(49, 21, 7));
	ImageManager::GetSingleton()->AddImage("Obstacle_one", "Cookieland/leveloneObstacle.bmp", 87, 118, true, RGB(0, 0, 0));
	ImageManager::GetSingleton()->AddImage("Obstacle_one2", "Cookieland/leveloneObstacle2.bmp", 124, 220, true, RGB(5, 5, 5));
	ImageManager::GetSingleton()->AddImage("Obstacle_one3", "Cookieland/leveloneObstacle3.bmp", 124, 370, true, RGB(5, 5, 5));
	ImageManager::GetSingleton()->AddImage("Obstacle_one_slide", "Cookieland/leveloneObstacle4.bmp", 124, 470, true, RGB(5, 5, 5));
	ImageManager::GetSingleton()->AddImage("Land_two", "Cookieland/leveltwoLand.bmp", 124, 140, true);
	ImageManager::GetSingleton()->AddImage("Obstacle_two", "Cookieland/leveltwoObstacle.bmp", 110, 118, true, RGB(3, 3, 3));
	ImageManager::GetSingleton()->AddImage("Obstacle_two2", "Cookieland/leveltwoObstacle2.bmp", 125, 255, true, RGB(0, 0, 0));
	ImageManager::GetSingleton()->AddImage("Land_three", "Cookieland/levelthreeLand.bmp", 124, 140, true, RGB(25, 10, 10));
	ImageManager::GetSingleton()->AddImage("Obstacle_three", "Cookieland/levelthreeObstacle.bmp", 110, 100, true, RGB(110, 0, 50));
	ImageManager::GetSingleton()->AddImage("Cookie_Gage_Bar", "Cookie/skill_guage_bar.bmp", 74, 16);
	ImageManager::GetSingleton()->AddImage("Cookie_Gage", "Cookie/skill_guage.bmp", 70, 12);
	ImageManager::GetSingleton()->AddImage("Cookie_Hp_Bar", "Cookie/cookie_HPbar.bmp", 750, 32);
	ImageManager::GetSingleton()->AddImage("Cookie_Hp", "Cookie/cookie_HP.bmp", 750, 28);
	ImageManager::GetSingleton()->AddImage("Cookie_Hp_state", "Cookie/heartstate.bmp", 54, 54, true, RGB(250, 250, 50));

	ImageManager::GetSingleton()->AddImage("Jelly_lv1", "CookieItem/cookie_jelly1.bmp", 62, 62, true, RGB(50, 25, 0));
	ImageManager::GetSingleton()->AddImage("BonusTime_B", "CookieItem/BonusTime_B.bmp", 80, 80, true, RGB(160, 0, 0));
	ImageManager::GetSingleton()->AddImage("BonusTime_O", "CookieItem/BonusTime_O.bmp", 80, 80, true, RGB(100, 70, 0));
	ImageManager::GetSingleton()->AddImage("BonusTime_N", "CookieItem/BonusTime_N.bmp", 80, 80, true, RGB(15, 70, 1));
	ImageManager::GetSingleton()->AddImage("BonusTime_U", "CookieItem/BonusTime_U.bmp", 80, 80, true, RGB(0, 45, 100));
	ImageManager::GetSingleton()->AddImage("BonusTime_S", "CookieItem/BonusTime_S.bmp", 80, 80, true, RGB(60, 10, 100));
	ImageManager::GetSingleton()->AddImage("BonusTime_T", "CookieItem/BonusTime_T.bmp", 80, 80, true, RGB(125, 0, 60));
	ImageManager::GetSingleton()->AddImage("BonusTime_I", "CookieItem/BonusTime_I.bmp", 80, 80, true, RGB(100, 10, 0));
	ImageManager::GetSingleton()->AddImage("BonusTime_M", "CookieItem/BonusTime_M.bmp", 80, 80, true, RGB(130, 100, 45));
	ImageManager::GetSingleton()->AddImage("BonusTime_E", "CookieItem/BonusTime_E.bmp", 80, 80, true, RGB(100, 70, 0));
	ImageManager::GetSingleton()->AddImage("BonusTime_All", "CookieItem/Item_bonus.bmp", 85, 85, true, RGB(125, 110, 140));
	ImageManager::GetSingleton()->AddImage("Bonus_back", "CookieItem/bonustime_back.bmp", 340, 44, true, RGB(80, 80, 80));
	ImageManager::GetSingleton()->AddImage("Bonus_front", "CookieItem/bonustime_front.bmp", 340, 44, true, RGB(80, 80, 80));

	ImageManager::GetSingleton()->AddImage("Jelly", "CookieItem/cookie_jelly.bmp", 62, 62, true, RGB(65, 30, 105));
	ImageManager::GetSingleton()->AddImage("SilverCoin", "CookieItem/coin_jelly.bmp", 50, 50, true, RGB(45, 45, 45));
	ImageManager::GetSingleton()->AddImage("GoldCoin", "CookieItem/coin_gold_jelly.bmp", 50, 50, true, RGB(120, 60, 0));
	ImageManager::GetSingleton()->AddImage("Item_Hp", "CookieItem/Hpitem.bmp", 62, 62, true, RGB(10, 20, 75));
	ImageManager::GetSingleton()->AddImage("Item_BigHp", "CookieItem/HpBigitem.bmp", 62, 62, true, RGB(10, 20, 75));
	

	isInit = true;

	return S_OK;
}

void MainGame::Release()
{
	
	SceneManager::GetSingleton()->Release();
	SceneManager::GetSingleton()->ReleaseSingleton();

	SoundManager::GetSingleton()->Release();
	SoundManager::GetSingleton()->ReleaseSingleton();

	TimeManager::GetSingleton()->Release();
	TimeManager::GetSingleton()->ReleaseSingleton();
	
	ImageManager::GetSingleton()->Release();
	ImageManager::GetSingleton()->ReleaseSingleton();

	KeyManager::GetSingleton()->Release();
	KeyManager::GetSingleton()->ReleaseSingleton();

	backBuffer->Release();
	delete backBuffer;

	ReleaseDC(g_hWnd, hdc);
}

void MainGame::Update()
{
	SceneManager::GetSingleton()->Update();
	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render()
{	
	SceneManager::GetSingleton()->Render(backBuffer->GetMemDC());
	//TimeManager::GetSingleton()->Render(backBuffer->GetMemDC());
	backBuffer->Render(hdc, 0, 0);
}

LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_MOUSEMOVE:
		g_ptMouse.x = LOWORD(lParam);
		g_ptMouse.y = HIWORD(lParam);
		break;

	case WM_TIMER:
		if (isInit)
			this->Update();
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		//if (isInit)
		//	this->Render(hdc);

		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_SPACE:
			//tank->Fire();
			break;
		case VK_LEFT:
			//tank->SetBarrelAngle(tank->GetBarrelAngle() + (PI / 180 * 1));
			break;
		case VK_RIGHT:
			//tank->SetBarrelAngle(tank->GetBarrelAngle() - (PI / 180 * 1));
			break;
		case VK_UP:
			break;
		case VK_DOWN:
			break;
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

float MainGame::GetAngle(float x1, float y1, float x2, float y2)
{
	/*
		tan (theta) = x / y;
					= (x2 - x1) / (y2 - y1);

					atan2( (y2 - y1), (x2 - x1) );
	*/

	return atan2((y2 - y1), (x2 - x1));
}

float MainGame::GetDistance(float x1, float y1, float x2, float y2)
{
	float x = x2 - x1;
	float y = y2 - y1;

	float dist = sqrtf((x * x) + (y * y));

	return dist;
}

//bool MainGame::CheckCollision(Missile * m1, Missile * m2)
//{
//	float halfSize1 = m1->GetSize() / 2;
//	float halfSize2 = m2->GetSize() / 2;
//	FPOINT pos1 = m1->GetPos();
//	FPOINT pos2 = m2->GetPos();
//
//	if ((halfSize1 + halfSize2) >=
//		GetDistance(pos1.x, pos1.y, pos2.x, pos2.y))
//	{
//		return true;
//	}
//
//	return false;
//}

MainGame::MainGame()
	: isInit(false)
{
}


MainGame::~MainGame()
{
}
