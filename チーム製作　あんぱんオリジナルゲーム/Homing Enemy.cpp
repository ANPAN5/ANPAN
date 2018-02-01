//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"Homing Enemy.h"
#include"UtilityModule.h"

//使用するネームスペース
using namespace GameL;

CObjHomingEnemy::CObjHomingEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjHomingEnemy::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;

	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;

	//移動ベクトル
	UnitVec(&m_vy, &m_vx);
	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_ENEMY, OBJ_HOMING_ENEMY, 2);
}
//アクション
void CObjHomingEnemy::Action()
{
	//移動
	m_x += m_vx * 1.5f;
	m_y += m_vy * 1.5f;

	//Resourcesの描画物のRECT
	m_eff = GetBulletEffec(&m_ani, &m_ani_time, m_del, 4);
	float ar = 0.0f;

	//主人公機と誘導弾丸で角度を取る
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{
		float x = obj->GetX() - m_x;
		float y = obj->GetY() - m_y;
		float ar = GetAtan2Angle(x, -y);

		if (ar< 0)
		{
			ar = 360 - abs(ar);
		}

		//弾丸の現在の向いている角度を取る
		float br = GetAtan2Angle(m_vx, -m_vy);
		if (br < 0)
		{
			br = 360 - abs(br);
		}

		float r = 3.14 / 180.0f;

		if (ar < br)
		{
			//移動方向に+1°加える
			m_vx = m_vx*cos(r) - m_vy*sin(r);
			m_vy = m_vy*cos(r) + m_vx*sin(r);
		}
		else
		{
			//移動方向に-1°加える
			m_vx = m_vx*cos(-r) - m_vy*sin(-r);
			m_vy = m_vy*cos(-r) + m_vx*sin(-r);
		}
		UnitVec(&m_vx, &m_vy);


		//主人公機と敵機角度があまりにもかけ離れたら
		if (ar - br > 50)
		{
			//移動方向を主人公機の方向にする
			m_vx = cos(3.14 / 180 * ar);
			m_vy = -sin(3.14 / 180 * ar);
		}
	}
	m_x += m_vx;
	m_y += m_vy;


	//ブロックの情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);


	//HitBoxの内容を更新
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y - block->GetScroll());//HitBoxの位置を誘導弾丸の位置に更新



	//主人公オブジェクトと接触したら幽霊削除
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

}
//ドロー
void CObjHomingEnemy::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F dst;
	float r = 0.0f;


	//ブロックの情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	
	//表示位置の設定
	dst.m_top = 0.0f + m_y - block->GetScroll();
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0 + m_y  - block->GetScroll();

	//主人公機と誘導弾丸で角度を取る
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//主人公機が存在する場合、誘導角度を計算する
	if (obj != nullptr)
	{
		float x = obj->GetX() - m_x;
		float y = obj->GetY() - m_y;
		r = GetAtan2Angle(x, -y);
		if (r < 0)
		{
			r = 360 - abs(r);
		}
	}

	//０番目に登録したグラフィックをsrc.dst.cの情報を元に描画
	Draw::Draw(2, &m_eff, &dst, c, 1.0f);
}