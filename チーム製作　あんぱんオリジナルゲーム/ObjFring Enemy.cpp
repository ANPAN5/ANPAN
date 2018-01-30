/*
//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjFring Enemy.h"
#include "UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
FringEnemy::FringEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void FringEnemy::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//当たり判定用Hit Boxを作成
	Hits::SetHitBox(this, m_x, m_y, 50, 50, ELEMENT_ENEMY, OBJ_FRING_ENEMY, 1);
}

//アクション
void FringEnemy::Action()
{

	//移動方向
	m_vx = -1.0f;
	m_vy = 0.0f;

	//スクロールの影響
//	float scroll = scroll_on ? m_scroll; 0;

//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//速度をつける
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//移動ベクトルを座標に加算する
	m_x+= m_vx;
	m_y+= m_vy;

	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);	//作成したHitBox更新酔おうの入り口を取り出す
	hit->SetPos(m_x, m_y);					//入り口から新しい位置(主人公機の位置)情報に置き換える

	//足と接触してるるかどうかを調べる
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//ドロー
void FringEnemy::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=alpha(透過情報）
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定
	src.m_top    = 20.0f;
	src.m_left   = 0.0f;
	src.m_right  = 209.0f;
	src.m_bottom = 107.0f;
	//表示位置の設定
	dst.m_top    = 100.0f +m_y;
	dst.m_left   = 300.0f+m_x;
	dst.m_right  = 410.0f+m_x;
	dst.m_bottom = 200.0f+m_y;
	//0番目に登録したグラフィックをsrc・dst・ｃの情報を元に描画
	Draw::Draw(1,&src, &dst,c,0.0f);
}*/