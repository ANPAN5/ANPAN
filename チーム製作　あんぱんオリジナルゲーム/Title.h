#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CTitle :public CObj
{
public:
	CTitle() {};
	~CTitle() {};
	void Init();
	void Action();
	void Draw();
private:
};

