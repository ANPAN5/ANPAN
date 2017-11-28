#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:ブロック&背景
class CObjBlock : public CObj
{
	public :
		CObjBlock() {};
		~CObjBlock() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー
	private:
		float m_px;		//位置
		float m_py;
		float m_vx;		//移動
		float m_vy;
};
