#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class CObjBlock : public CObj
{
public:
	CObjBlock(int map[200][13]);
	~CObjBlock() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー


	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }


	//ブロックとの当たり判定
	void BlockHit(
		float*x, float*y, bool scroll_on,
		bool*up, bool*down, bool*left, bool*right,
		float* vx, float*vy, int*bt
	);


private:
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	int m_map[200][13];	//マップ情報

	float m_scroll;		//左右スクロール用
};
