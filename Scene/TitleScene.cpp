#include "TitleScene.h"
#include "Image.h"
#include "Button.h"
#include "ButtonFunction.h"

HRESULT TitleScene::Init()
{
	pos.y = (WINSIZE_Y / 5) * 2;

	lobby_Bg = ImageManager::GetSingleton()->AddImage("TitleBg", "Cookbg/lobby.bmp", WINSIZE_X, WINSIZE_Y);
	cookie_lobby = ImageManager::GetSingleton()->AddImage("Lobby_cookie", "Cookie/cookie_lobby.bmp", 250, 250, true, RGB(46, 16, 0));

	ImageManager::GetSingleton()->AddImage("Btn_PLAY", "Cookie/btn_play.bmp", 0.0f, 0.0f, 210, 140, 1, 2, true, RGB(90, 50, 5));

	btnFunc = new ButtonFunction;

	POINT upFramePoint = { 0, 0 };
	POINT downFramePoint = { 0, 1 };
	
	play = new Button;
	play->Init("Btn_PLAY", (WINSIZE_X / 10) * 9, (WINSIZE_Y / 8) * 7, downFramePoint, upFramePoint);
	args = new ARGUMENT_INFO;
	args->sceneName = "달리기게임";
	args->loadingName = "로딩1";
	play->SetButtonFunc(btnFunc, &ButtonFunction::ChangeScene1, args);
	return S_OK;
}

void TitleScene::Release()
{
	SAFE_DELETE(args);
	SAFE_DELETE(btnFunc);
	play->Release();
	SAFE_DELETE(play);
}

void TitleScene::Update()
{
	/*if (KeyManager::GetSingleton()->IsOnceKeyDown(VK_RETURN))
	{
		SceneManager::GetSingleton()->ChangeScene("배틀", "로딩1");

		return;
	}*/
	if (play)
	{
		play->Update();
	}
}

void TitleScene::Render(HDC hdc)
{
	if (lobby_Bg)
	{
		lobby_Bg->Render(hdc, 0, 0);
	}
	if (cookie_lobby)
	{
		cookie_lobby->Render(hdc, (WINSIZE_X / 5) * 2, pos.y);
	}
	if (play)			play->Render(hdc);
}

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}
