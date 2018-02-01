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
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjBullet::Init()
{
	
	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 36, 25, ELEMENT_PLAYER, OBJ_BULLET, 1);

}

//アクション
void CObjBullet::Action()
{
	m_py += 10.0f;

	if (m_del==true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		return;
	}


	//弾丸のHitBox更新用ポインター取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px+10, m_py);				//HitBoxの位置を弾丸の位置に更新

	//弾丸が領域外に出たら弾丸削除
	if (m_py > 950.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}


	//当たり判定を行うオブジェクト情報
	int data_base[3] =
	{
		OBJ_ENEMY,
		OBJ_HOMING_ENEMY,
        OBJ_FRING_ENEMY,
	};

	//オブジェクト情報と当たり判定を行い、当たっていれば削除
	for (int i = 0; i < 3; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			m_del = true;			//消滅実行
			hit->SetInvincibility(true);
		}
	}

	return;//消滅処理は、ここでアクションメソッドを終了させる


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
	src.m_left   = 280.0f;
	src.m_right  = 380.0f;
	src.m_bottom = 62.0f;

	//表示位置
	dst.m_top    = 0.0f+m_py;
	dst.m_left   = 10.0f+m_px;
	dst.m_right  = 40.0f+m_px;
	dst.m_bottom = 45.0f+m_py;

	//0番目に登録したグラフィックをsrc.dst.cの情報を元に描画
	Draw::Draw(0, &src, &dst, c, -90.0f);
}
