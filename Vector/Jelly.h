#pragma once
#include "GameNode.h"

class Image;
class Jelly : public GameNode
{
private:
	Image* jelly;
	RECT rc;
	POINT Jpoint;
	POINT initJPos;
	float jellyposX;
	float jellyposY;
	int jellycount;
	bool collision;
	int jellyscore;

public:
	virtual HRESULT Init();
	virtual HRESULT Init(float posX, float posY);
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	RECT GetRect() { return rc; }
	POINT GetPoint() { return Jpoint; }
	POINT GetInitJPos() { return initJPos; }
	bool IsCollision() { return collision; }
	void SetIsCollision(bool isJelly) { collision = isJelly; }
	int Getjellyscore() { return jellyscore; }

	Jelly();
	virtual ~Jelly();
};

