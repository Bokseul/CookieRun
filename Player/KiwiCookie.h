#pragma once
#include "Cookie.h"

class Animation;
class KiwiCookie : public Cookie
{
private:
	Animation* playAni;
	Animation* ani_Idle;
	Animation* ani_Rush;
	Animation* ani_Jump;
	Animation* ani_DoubleJump;
	Animation* ani_Jump_Down;
	Animation* ani_Slide;
	Animation* ani_SkillStart;
	Animation* ani_SkillIng;
	Animation* ani_SkillRush;
	Animation* ani_BonusTime;
	Animation* ani_BonusFly;
	Animation* ani_Hit;
	Animation* ani_Die;

public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	float GetCookieHp() { return CookieHp; }
	void SetCookiHp(float _cookieHp) { CookieHp = _cookieHp; }

	int GetjumpPw() { return jumpPower; }
	void SetmaxjumpPw(int ismaxjumpPower) { maxjump = ismaxjumpPower; }

	void SetLife(bool islife) { life = islife; }
	bool GetLife() { return life; }

	void SetairState (bool air) { airState = air; }
	void SetdoublejumpState(bool _doublejump) { doublejump = _doublejump; }

	RECT GetKiwiCookie() { return cookie_rc; }
	void SetKiwiCookie(RECT cookieRC) { cookie_rc = cookieRC; }

	POINT GetKiwipos() { return cookie_pos; }
	void SetKiwipos(POINT kiwicookiepos) { cookie_pos = kiwicookiepos; }
	
	void SetMotion(Motion motion) { mot = motion; }

	void SetHitState(bool _hitState) { hitstate = _hitState; }
	
	void SetCookieGuage(GuageBar* _cguage) { cgauge = _cguage; }

	KiwiCookie();
	virtual ~KiwiCookie();
};

