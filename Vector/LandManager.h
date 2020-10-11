#pragma once
#include "GameNode.h"

class Land;
class LandManager : public GameNode
{
private:
	vector<Land*> vecLand;
	vector<Land*> vecLand2;
	vector<Land*> vecLand3;
	vector<Land*> vecLand_1;
	vector<Land*> vecLand2_1;
	vector<Land*> vecLand3_1;
	vector<Land*>::iterator	itLand;

public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	bool vecLand_b;
	bool vecLand_b2;
	bool vecLand_b3;
	bool vecLand_b4;
	bool vecLand_b5;
	bool vecLand_b6;
	int land_level_count;

	/*void AddLand(float posX, float posY);*/

	vector<Land*>* GetLand1() { return &vecLand; }
	vector<Land*>* GetLand2() { return &vecLand2; }
	vector<Land*>* GetLand3() { return &vecLand3; }
	vector<Land*>* GetLand1_1() { return &vecLand_1; }
	vector<Land*>* GetLand2_1() { return &vecLand2_1; }
	vector<Land*>* GetLand3_1() { return &vecLand3_1; }

	bool GetvecLand_b() { return vecLand_b; }
	bool GetvecLand_b2() { return vecLand_b2; }
	bool GetvecLand_b3() { return vecLand_b3; }
	bool GetvecLand_b4() { return vecLand_b4; }
	bool GetvecLand_b5() { return vecLand_b5; }
	bool GetvecLand_b6() { return vecLand_b6; }
	int GetLand_levelchange() { return land_level_count; }

	LandManager();
	~LandManager();
};

