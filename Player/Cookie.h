#pragma once
#include "GameNode.h"

class GuageBar;
class Button;
class Image;
class Cookie : public GameNode
{
protected:
	Image* cookie;

	Motion mot;

	POINT cookie_pos;

	RECT cookie_rc;

	Button* jump;
	Button* slide;

	GuageBar* cgauge;

	float CookieHp;

	bool rushState;
	bool airState;
	bool jumpState;
	bool skillState;
	bool life;
	bool doublejump;
	bool hitstate;
	int doublejumpcount;
	
	int currFrameX, currFrameY, count;
	int gravity;
	int hpcount;
	int jumpPower;
	int maxjump;

public:
	virtual HRESULT Init() = 0;
	virtual void Release() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	
	Cookie();
	virtual ~Cookie();
};

