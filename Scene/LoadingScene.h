#pragma once
#include "GameNode.h"

class Image;
class Animation;
class LoadingScene : public GameNode
{
private:

	/*Image* loading_BG;
	Image* loading_Gage;*/

	float gage;
	Animation* ani;

public:

	virtual HRESULT Init();		// ��� ���� �ʱ�ȭ, �޸� �Ҵ�
	virtual void Release();		// �޸� ����
	virtual void Update();		// ������ ���� ���� ���� ���� (������ ����)
	virtual void Render(HDC hdc);	// ������ ���� ��� (�̹���, �ؽ�Ʈ ��)

	LoadingScene();
	virtual ~LoadingScene();
};

