#pragma once
#include "GameNode.h"

class Image;
class Land : public GameNode
{
private:
	Image* level_one;
	Image* level_two;
	Image* level_three;

	POINT initPos;
	int changeLandCount;
	int landcount;
	float speed;
	bool rand;
	RECT rc;
	float loadPosX;
	float loadPosY;

public:
	virtual HRESULT Init();
	virtual HRESULT Init(float posX, float posY);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	RECT GetRect() { return rc; }
	void SetLandChange(int changeLand) { this->changeLandCount = changeLand; }
	POINT GetInitPos() { return initPos; }

	Land();
	virtual ~Land();
};

