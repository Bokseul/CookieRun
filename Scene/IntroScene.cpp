#include "IntroScene.h"
#include "Image.h"

HRESULT IntroScene::Init()
{
	introScene = ImageManager::GetSingleton()->AddImage("introBG", "Cookbg/intro_bg.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(253, 132, 57));
	loading_BG = ImageManager::GetSingleton()->AddImage("loading", "Cookbg/load_bg.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 255, 255));
	loading_Gage = ImageManager::GetSingleton()->AddImage("loading_gage", "Cookbg/loading_gage.bmp", WINSIZE_X, 20, true, RGB(255, 255, 255));
	
	countdown = 0.0f;
	loaddown = 0.0f;
	nextScene = false;

	return S_OK;
}

void IntroScene::Release()
{

}

void IntroScene::Update()
{
	if (countdown <= 1000.0f)
	{
		countdown += 10.0f;
		if (countdown >= 1000.0f)
		{
			nextScene = true;
		}

	}
	if (nextScene)
	{
		loaddown += 10.0f;
		if (loaddown >= 1000.0f)
		{
			loaddown = 1000.0f;
			if (loaddown >= 1000.0f)
			{
				SceneManager::GetSingleton()->ChangeScene("Å¸ÀÌÆ²");
				nextScene = false;
			}
		}

	}
}

void IntroScene::Render(HDC hdc)
{
	PatBlt(hdc, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);

	if (nextScene == false)
	{
		introScene->Render(hdc, 0, 0, countdown);
	}
	if (nextScene == true)
	{
		loading_BG->Render(hdc, 0, 0);
		loading_Gage->Render(hdc, 0, 690, loaddown);
	}
}

IntroScene::IntroScene()
{
}

IntroScene::~IntroScene()
{
}
