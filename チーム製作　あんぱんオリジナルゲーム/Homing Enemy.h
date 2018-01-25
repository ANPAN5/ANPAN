#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵機弾丸
class CObjHomingEnemy :public CObj
{
public:
	CObjHomingEnemy(float x, float y);
	~CObjHomingEnemy() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	int m_time;

	int m_ani;//着弾アニメーション
	int m_ani_time;//着弾アニメーション感覚タイム
	bool m_del;	//削除チェック
	RECT_F m_eff; //着弾エフェクト

};