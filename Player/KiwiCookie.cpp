#include "KiwiCookie.h"
#include "Animation.h"
#include "Image.h"
#include "Button.h"
#include "ButtonFunction.h"

HRESULT KiwiCookie::Init()
{
	pos.x = 480;
	pos.y = 378;

	cookie_pos.x = pos.x;
	cookie_pos.y = pos.y;

	POINT upFramePoint = { 0, 0 };
	POINT downFramePoint = { 0, 1 };

	mot = Idle;

	rushState = false;
	airState = false;
	skillState = false;
	life = true;
	doublejump = false;
	hitstate = false;
	CookieHp = 1000.0f;
	cookie_rc = GetRectToCenter(cookie_pos.x, cookie_pos.y, 60, 60);

	jumpPower = 3;
	maxjump = 43;
	gravity = 3;
	hpcount = 0;
	doublejumpcount = 0;
	cookie = ImageManager::GetSingleton()->AddImage("Motion", "Cookie/cookie_motion.bmp", 0.0f, 0.0f, 3240, 2750, 9, 11, true, RGB(46, 16, 0));

	ImageManager::GetSingleton()->AddImage("Btn_JUMP", "Cookie/btn_jump.bmp", 0.0f, 0.0f, 236, 356, 1, 2, true, RGB(53, 45, 38));
	ImageManager::GetSingleton()->AddImage("Btn_SLIDE", "Cookie/btn_slide.bmp", 0.0f, 0.0f, 236, 356, 1, 2, true, RGB(53, 45, 38));

	jump = new Button();
	jump->Init("Btn_JUMP", WINSIZE_X / 8, (WINSIZE_Y / 4), downFramePoint, upFramePoint);
	slide = new Button();
	slide->Init("Btn_SLIDE", (WINSIZE_X / 8) * 7, (WINSIZE_Y / 4), downFramePoint, upFramePoint);

	ani_Idle = new Animation();
	ani_Idle->Init(cookie->GetWidth(), cookie->GetHeight(), cookie->GetFrameWidth(), cookie->GetFrameHeight());
	ani_Idle->SetUpdateTime(FPS / 6.0f);
	ani_Idle->SetPlayFrame(0, 3, false, true);
	ani_Idle->Start();

	ani_Rush = new Animation();
	ani_Rush->Init(cookie->GetWidth(), cookie->GetHeight(), cookie->GetFrameWidth(), cookie->GetFrameHeight());
	ani_Rush->SetUpdateTime(FPS / 3.0f);
	ani_Rush->SetPlayFrame(9, 12, false, true);
	ani_Rush->Start();

	ani_Jump = new Animation();
	ani_Jump->Init(cookie->GetWidth(), cookie->GetHeight(), cookie->GetFrameWidth(), cookie->GetFrameHeight());
	ani_Jump->SetUpdateTime(FPS / 10.0f);
	ani_Jump->SetPlayFrame(27, 28, false, false);
	ani_Jump->Start();

	ani_DoubleJump = new Animation();
	ani_DoubleJump->Init(cookie->GetWidth(), cookie->GetHeight(), cookie->GetFrameWidth(), cookie->GetFrameHeight());
	ani_DoubleJump->SetUpdateTime(FPS / 7.0f);
	ani_DoubleJump->SetPlayFrame(29, 32, false, false);
	ani_DoubleJump->Start();

	ani_Jump_Down = new Animation();
	ani_Jump_Down->Init(cookie->GetWidth(), cookie->GetHeight(), cookie->GetFrameWidth(), cookie->GetFrameHeight());
	ani_Jump_Down->SetUpdateTime(FPS / 3.0f);
	ani_Jump_Down->SetPlayFrame(33, 35, false, false);
	ani_Jump_Down->Start();

	ani_Slide = new Animation();
	ani_Slide->Init(cookie->GetWidth(), cookie->GetHeight(), cookie->GetFrameWidth(), cookie->GetFrameHeight());
	ani_Slide->SetUpdateTime(FPS / 3.0f);
	ani_Slide->SetPlayFrame(36, 37, false, true);
	ani_Slide->Start();

	ani_SkillStart = new Animation();
	ani_SkillStart->Init(cookie->GetWidth(), cookie->GetHeight(), cookie->GetFrameWidth(), cookie->GetFrameHeight());
	ani_SkillStart->SetUpdateTime(FPS / 3.0f);
	ani_SkillStart->SetPlayFrame(45, 49, false, false);
	ani_SkillStart->Start();

	ani_SkillIng = new Animation();
	ani_SkillIng->Init(cookie->GetWidth(), cookie->GetHeight(), cookie->GetFrameWidth(), cookie->GetFrameHeight());
	ani_SkillIng->SetUpdateTime(FPS / 6.0f);
	ani_SkillIng->SetPlayFrame(50, 53, false, true);
	ani_SkillIng->Start();

	ani_SkillRush = new Animation();
	ani_SkillRush->Init(cookie->GetWidth(), cookie->GetHeight(), cookie->GetFrameWidth(), cookie->GetFrameHeight());
	ani_SkillRush->SetUpdateTime(FPS / 3.0f);
	ani_SkillRush->SetPlayFrame(54, 60, false, true);
	ani_SkillRush->Start();

	ani_BonusTime = new Animation();
	ani_BonusTime->Init(cookie->GetWidth(), cookie->GetHeight(), cookie->GetFrameWidth(), cookie->GetFrameHeight());
	ani_BonusTime->SetUpdateTime(FPS / 3.0f);
	ani_BonusTime->SetPlayFrame(63, 71, false, false);
	ani_BonusTime->Start();

	ani_BonusFly = new Animation();
	ani_BonusFly->Init(cookie->GetWidth(), cookie->GetHeight(), cookie->GetFrameWidth(), cookie->GetFrameHeight());
	ani_BonusFly->SetUpdateTime(FPS / 3.0f);
	ani_BonusFly->SetPlayFrame(72, 80, false, true);
	ani_BonusFly->Start();

	ani_Hit = new Animation();
	ani_Hit->Init(cookie->GetWidth(), cookie->GetHeight(), cookie->GetFrameWidth(), cookie->GetFrameHeight());
	ani_Hit->SetUpdateTime(FPS / 6.0f);
	ani_Hit->SetPlayFrame(82, 85, true, true);
	ani_Hit->Start();

	ani_Die = new Animation();
	ani_Die->Init(cookie->GetWidth(), cookie->GetHeight(), cookie->GetFrameWidth(), cookie->GetFrameHeight());
	ani_Die->SetUpdateTime(FPS / 3.0f);
	ani_Die->SetPlayFrame(90, 94, false, true);
	ani_Die->Start();

	playAni = ani_Idle;

	return S_OK;
}

void KiwiCookie::Release()
{
	SAFE_DELETE(ani_Idle);
	SAFE_DELETE(ani_Rush);
	SAFE_DELETE(ani_Jump);
	SAFE_DELETE(ani_Jump_Down);
	SAFE_DELETE(ani_DoubleJump);
	SAFE_DELETE(ani_Slide);
	SAFE_DELETE(ani_SkillStart);
	SAFE_DELETE(ani_SkillIng);
	SAFE_DELETE(ani_SkillRush);
	SAFE_DELETE(ani_BonusTime);
	SAFE_DELETE(ani_BonusFly);
	SAFE_DELETE(ani_Die);

	jump->Release();
	SAFE_DELETE(jump);

	slide->Release();
	SAFE_DELETE(slide);
}

void KiwiCookie::Update()
{
	if (life == true)
	{
		playAni->UpdateKeyFrame(TimeManager::GetSingleton()->GetDeltaTime());
		if (cookie_pos.y >= 840)
		{
			life = false;
		}
		if (KeyManager::GetSingleton()->IsOnceKeyDown(VK_UP))
		{
			if (doublejump == false)
			{
				if (airState == false)
				{
					airState = true;
					ani_Jump->Start();
				}
				else if (airState == true)
				{
					doublejump = true;
					ani_DoubleJump->Start();
					maxjump = 40;
				}
			}
		}

		else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_SPACE) && mot != Jump)
		{
			mot = Slide;
			cookie_rc = GetRectToCenter(cookie_pos.x, cookie_pos.y, 80, 20);
		}
		if (KeyManager::GetSingleton()->IsOnceKeyUp(VK_SPACE))
		{
			mot = Idle;
		}
		if (airState)
		{
			if ((maxjump >= 0) && doublejump == false)
			{
				maxjump -= jumpPower;
				cookie_pos.y -= 11;
				mot = Jump;
				cookie_rc = GetRectToCenter(cookie_pos.x, cookie_pos.y, 60, 30);
			}
			else if ((maxjump < 0) && doublejump == false)
			{
				cookie_pos.y += 11;
				mot = JumpDown;
				cookie_rc = GetRectToCenter(cookie_pos.x, cookie_pos.y, 60, 30);
			}
			if ((maxjump >= 0) && doublejump == true)
			{
				maxjump -= jumpPower;
				cookie_pos.y -= 11;
				mot = DoubleJump;
				cookie_rc = GetRectToCenter(cookie_pos.x, cookie_pos.y, 60, 30);
			}
			else if ((maxjump < 0) && doublejump == true)
			{
				cookie_pos.y += 11;
				mot = JumpDown;
				cookie_rc = GetRectToCenter(cookie_pos.x, cookie_pos.y, 60, 30);
			}
		}
		if (hitstate == true)
		{
			/*ani_Hit->Start();*/
			mot = Hit;
		}
		switch (mot)
		{
		case Idle:
			playAni = ani_Idle;
			break;
		case Rush:
			playAni = ani_Rush;
			break;
		case Jump:
			playAni = ani_Jump;
			break;
		case JumpDown:
			playAni = ani_Jump_Down;
			break;
		case DoubleJump:
			playAni = ani_DoubleJump;
			break;
		case Slide:
			playAni = ani_Slide;
			break;
		case Skill:
			playAni = ani_SkillIng;
			break;
		case SkillRush:
			break;
		case BonusTime:
			break;
		case BonusTimeFly:
			break;
		case Hit:
			playAni = ani_Hit;
			break;
		case Die:
			break;
		default:
			break;
		}
		/*if (jump)
		{
			jump->Update();
		}
		if (slide)
		{
			slide->Update();
		}*/
		/*if (mot == Skill)
		{
			gage -= 0.5f;
			skillState = true;
			if (gage <= 6.5f)
			{
				playAni = ani_SkillStart;
			}
			if (gage > 6.5f)
			{
				playAni = ani_SkillIng;
			}
		}
		else
		{
			mot = Idle;
			playAni = ani_Idle;
		}
		if (gage <= 100.f && skillState == false)
		{
			gage += 0.3f;
		}
		if (gage >= 100.0f)
		{
			mot = Skill;
		}*/


		if (airState == false)
		{
			cookie_pos.y += (gravity * 8);
		}
		cookie_rc = GetRectToCenter(cookie_pos.x, cookie_pos.y, 60, 60);
	}
	if (life == false)
	{
		playAni = ani_Die;
		
		/*if (MessageBox(g_hWnd, "게임오버", "CookieRun", MB_OK))
		{
			PostQuitMessage(0);
		}*/

	}
}

void KiwiCookie::Render(HDC hdc)
{
	if (cookie)
	{
	//	Rectangle(hdc, cookie_rc.left, cookie_rc.top, cookie_rc.right, cookie_rc.bottom);
		cookie->AnimationRender(hdc, cookie_pos.x, cookie_pos.y, playAni);
	}
	/*if (jump)			jump->Render(hdc);
	if (slide)			slide->Render(hdc);*/
}

KiwiCookie::KiwiCookie()
{
}

KiwiCookie::~KiwiCookie()
{
}
