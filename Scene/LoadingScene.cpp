#include "LoadingScene.h"
#include "Image.h"
#include "Animation.h"

HRESULT LoadingScene::Init()
{
	
	/*loading_BG = ImageManager::GetSingleton()->AddImage("loading", "Cookbg/load_bg.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255,255,255));
	loading_Gage = ImageManager::GetSingleton()->AddImage("loading_gage", "Cookbg/loading_gage.bmp", WINSIZE_X, 46, true, RGB(159, 244, 255));*/
	
	gage = 0.0f;
	/*ani = new Animation();
	ani->Init(bg->GetWidth(), bg->GetHeight(), bg->GetFrameWidth(), bg->GetFrameHeight());
	ani->SetUpdateTime(FPS / 3.0f);
	ani->SetPlayFrame(false, true);
	ani->Start();*/

	return S_OK;

}

void LoadingScene::Release()
{
	/*SAFE_DELETE(ani);*/
}

void LoadingScene::Update()
{
	if (gage <= 1000.0f)
	{
		gage += 10.0f;
	}
}

void LoadingScene::Render(HDC hdc)
{
	//if(bg) bg->Render(hdc, 0, 0);
	/*bg->AnimationRender(hdc, WINSIZE_X / 2, WINSIZE_Y/2, ani);*/
	/*if (loading_BG)
	{
		loading_BG->Render(hdc, 0, 0);
	}
	if (loading_Gage)
	{
		loading_Gage->Render(hdc, 0, WINSIZE_Y - (WINSIZE_Y - 46), gage);
	}*/
}

LoadingScene::LoadingScene()
{
}

LoadingScene::~LoadingScene()
{
}
