//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjHero.h"

//使用するネームスペース
using namespace GameL;

//初期化
void CObjHero::Init()
{
	m_px = 0.0f;
	m_py = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_posture = 1.0f;	//右0.0f 左1.0f

	m_ani_time = 0;
	m_ani_frame = 1;		//静止フレームを初期にする

	//blockとの衝突状態確認用
	m_hit_up    = false;
	m_hit_down  = false;
	m_hit_left  = false;
	m_hit_right = false;
}

void CObjHero::Action()
{
	//移動ベクトルの破棄
	m_vx = 0.0f;
	m_vy = 0.0f;

	//キーの入力方向
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 2.0f;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 2.0f;
		m_posture = 0.0f;
		m_ani_time += 1;
	}

	else
	{
		m_ani_frame = 1;	//キー入力がない場合は静止フレーム
		m_ani_time = 0;
	}

	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	/*//主人公とブロックの当たり判定
	if ((hx + 64.0f > x) && (hx < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
	{
		//上下左右判定

		//vactorの作成
		float vx = hx - x;
		float vy = hy - y;

		//長さを求める
		float len = sqrt(vx*vx + vy*vy);

		//角度を求める
		float r = atan2(vy, vx);
		r = r*180.0f / 3.14f;

		if (r <= 0.0f)
			r = abs(r);
		else
			r = 360.0f - abs(r);

		//角度で上下左右を判定
		if (r<45 && r>0||r>315)
		{
			//右
		}
		if (r>45 && r<135)
		{
			//上
			hero->SetY(y-64.0f);//ブロックの位置・主人公の幅
		}
		if (r>135 && r<255)
		{
			//左
		}
		if (r>225 && r<315)
		{
			//下
		}

	}*/



	//自由落下運動
	m_vy += 9.8 / (16.0f);

	//更新の位置
	m_px += m_vx;
	m_py += m_vy;

}

void CObjHero::Draw()
{
	//歩くアニメーション
	int AniData[4] =
	{
		1,0,2,0,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top    = 0.0f;
	src.m_left   = 0.0f +AniData[m_ani_frame]*56;
	src.m_right  = 64.0f+AniData[m_ani_frame]*56;
	src.m_bottom = 72.0f;

	//表示位置の設定
	dst.m_top    = 0.0f +m_py;
	dst.m_left   = (     64.0f  * m_posture) + m_px;
	dst.m_right  = (64 - 64.0f  * m_posture) + m_px;
	dst.m_bottom = 72.0f+m_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}