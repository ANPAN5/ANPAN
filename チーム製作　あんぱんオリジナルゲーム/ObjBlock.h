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


		void SetScroll(float s) { m_scroll = s; }
		float GetScroll()		{ return m_scroll; }


	private:
		int m_map[200][13];	//マップ情報

		float m_scroll;		//左右？スクロール用
};
