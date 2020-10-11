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
	
	ARGUMENT_INFO *args, *args1;	// ��������� �ٲ�
	ButtonFunction *btnFunc;	// ButtonFunction�� void ���� ���� �����۾� �̴��� Init���� ���� �����Ҵ� ����

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

