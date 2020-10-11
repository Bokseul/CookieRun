#pragma once
#include "GameNode.h"

//enum LADN_TERRAIN
//{
//	Land,
//	Null
//};
class Cookie;
class Image;
class Button;
class ButtonFunction;
class TitleScene : public GameNode
{
private:
	/*LADN_TERRAIN l_t;*/
	Image* lobby_Bg;
	Image* cookie_lobby;

	Cookie* cookie_All;

	RECT cookie_box;
	RECT land_box;
	
	Button* play;
	
	ARGUMENT_INFO *args, *args1;	// 멤버변수로 바꿈
	ButtonFunction *btnFunc;	// ButtonFunction의 void 식을 쓰기 위한작업 이다음 Init으로 가서 동적할당 해줌

public:

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	/*static void click1();
	static void click2();*/

	TitleScene();
	virtual ~TitleScene();
};

