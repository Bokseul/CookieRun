#pragma once
#include "GameNode.h"

class Item;
class GuageBar;
class KiwiCookie;
class PointManager;
class ObstacleManager;
class LandManager;
class Cookie;
class Coin;
class Jelly;
class Obstacle;
class Land;
class Image;
class RunningScene : public GameNode
{
private:

	Image* battleBg;
	Image* stage1Bg;
	Image* stage2Bg;
	Image* stage3Bg;
	Image* bonusfront;
	Image* bonusback;

	bool Cookie_life;
	bool collision_Land;
	bool collision_Land_Down;
	bool CookieisCollision;
	int CookieinvincibilityTime;
	int RunningBackGround;

	int currFrameX, currFrameY, count;
	int sb = 300;
	
	LandManager* landMgr;
	ObstacleManager* obstacleMgr;
	PointManager* ptMgr;
	KiwiCookie* kiwicookie;
	GuageBar* guage;

public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	RunningScene();
	virtual ~RunningScene();
};

