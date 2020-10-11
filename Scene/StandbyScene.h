#pragma once
#include "GameNode.h"

class Image;
class Button;
class ButtonFunction;
class StandbyScene :public GameNode
{
private:
	Button* play;

	ARGUMENT_INFO *args, *args1;
	ButtonFunction *btnFunc;
public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	StandbyScene();
	virtual ~StandbyScene();
};

