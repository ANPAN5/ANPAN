#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:ブロック&背景
class CObjHero : public CObj
{
	public :
		CObjHero() {};
		~CObjHero() {};
		void Init();	//イニシャライズ
		void Action();	//アクション
		void Draw();	//ドロー

		float GetX()	{ return m_px; }
		float GetY()	{ return m_py; }
		float GetVY()	{ return m_vy; }
		float GetVX()	{ return m_vx; }
		int GetBT() { return m_block_type;}

		void SetX(float x)	 { m_px = x; }
		void SetY(float y)	 { m_py = y; }
		void SetVY(float vy) { m_vy = vy; }
		void SetVX(float vx) { m_vx = vx; }
		void SetBT(int t){m_block_type=t;}

		void SetUp   (bool b) { m_hit_up = b; }
		void SetDown (bool b) { m_hit_down = b; }
		void SetLeft (bool b) { m_hit_left = b; }
		void SetRight(bool b) { m_hit_right = b; }
	private:
		float m_x;
		float m_y;
		float m_px;		//位置
		float m_py;
		float m_vx;		//移動
		float m_vy;
		float m_posture;	//姿勢
		bool m_f;	//弾丸発射制御
		float m_time;

		int m_ani_time;	//アニメーションフレーム動作間隔
		int m_ani_frame;//描画フレーム
		float m_ani_saikou_time;

		//blockとの衝突状態確認用
		bool m_hit_up;
		bool m_hit_down;
		bool m_hit_left;
		bool m_hit_right;

		//踏んでいるblockの種類確認用
		int m_block_type;
};
