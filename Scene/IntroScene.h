#pragma once
#include "GameNode.h"

class Image;
class IntroScene : public GameNode
{
private:
	Image* introScene;
	Image* loading_BG;
	Image* loading_Gage;
	
	float countdown;
	float loaddown;
	bool nextScene;

public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	IntroScene();
	virtual ~IntroScene();
};