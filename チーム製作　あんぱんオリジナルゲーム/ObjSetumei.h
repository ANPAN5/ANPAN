#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：説明
class CObjSetumei :public CObj
{
public:
	CObjSetumei() {};
	~CObjSetumei() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;
};