#include "StandbyScene.h"
#include "Image.h"
#include "Button.h"
#include "ButtonFunction.h"

HRESULT StandbyScene::Init()
{
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

void StandbyScene::Release()
{
}

void StandbyScene::Update()
{
}

void StandbyScene::Render(HDC hdc)
{
}

StandbyScene::StandbyScene()
{
}

StandbyScene::~StandbyScene()
{
}
