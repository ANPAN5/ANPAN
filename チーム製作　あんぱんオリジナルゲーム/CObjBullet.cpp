//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "CObjBullet.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBullet::CObjBullet(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjBullet::Init()
{

}

//アクション
void CObjBullet::Action()
{

}

//ドロー
void CObjBullet::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置
	src.m_top    = 30.0f;
	src.m_left   = 275.0f;
	src.m_right  = 310.0f;
	src.m_bottom = 50.0f;

	//表示位置
	dst.m_top    = 30.0f;
	dst.m_left   = 275.0f;
	dst.m_right  = 310.0f;
	dst.m_bottom = 50.0f;

	//0番目に登録したグラフィックをsrc.dst.cの情報を元に描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
