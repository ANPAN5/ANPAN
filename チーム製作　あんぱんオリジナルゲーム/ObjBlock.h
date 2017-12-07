#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class CObjBlock : public CObj
{
	public:
		CObjBlock() {};
		~CObjBlock() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー
	private:
		int m_map[10][13];//マップ情報(仮)
};
