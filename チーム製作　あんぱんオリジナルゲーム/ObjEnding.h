#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：クリア
class CObjEnding :public CObj
{
public:
	CObjEnding() {};
	~CObjEnding() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;
};
