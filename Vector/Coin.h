#pragma once
#include "GameNode.h"

class Image;
class Coin : public GameNode
{
private:
	Image* coin;
	Image* gcoin;
	RECT rc;
	POINT Cpoint;
	POINT initCPos;
	int coincount;
	bool collision;
	bool GoldTrue;
	int coinscore;

public:
	virtual HRESULT Init();
	virtual HRESULT Init(float posX, float posY);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	RECT GetRect() { return rc; }
	POINT GetCoinPoint() { return Cpoint; }
	POINT GetInitCPos() { return initCPos; }
	int Getcoinscore() { return coinscore; }

	bool GetGoldCoinTrue() { return GoldTrue; }
	void SetGoldCoinTrue(bool _GoldTrue) { GoldTrue = _GoldTrue; }

	bool IsCollision_C() { return collision; }
	void SetIsCollision_C(bool isCoin) { collision = isCoin; }
	

	Coin();
	virtual ~Coin();
};

