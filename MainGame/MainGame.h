#pragma once
#include "GameNode.h"

class Image;
class MainGame : public GameNode
{
private:
	HDC hdc;
	bool isInit;
	HANDLE hTimer;
	/*SceneManager* sceneMgr;*/

	//Scene
	//BattleScene* battleScene;
	//TitleScene* titleScene;
	//LoadingScene* loadingScene;
	GameNode* standbyScene;
	GameNode* runningScene;
	GameNode* introScene;
	GameNode* tilemapToolScene;
	GameNode* battleScene;
	GameNode* titleScene;
	GameNode* loadingScene;
	GameNode* isomatricScene;
	//string scene[2]{ "Title", "Battle"};
	
	Image* backBuffer;

public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	LRESULT MainProc(HWND hWnd, UINT iMessage,
		WPARAM wParam, LPARAM lParam);

	float GetAngle(float x1, float y1, float x2, float y2);
	float GetDistance(float x1, float y1, float x2, float y2);
	//bool CheckCollision(Missile* m1, Missile* m2);

	MainGame();
	~MainGame();
};

