//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "CObjBullet.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{
	m_px = 70.0f;
	m_py = 64.0f; //位置
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_posture = 1.0f;	//右0.0f 左1.0f
	m_f = true;

	m_ani_time = 0;
	m_ani_frame = 1;		//静止フレームを初期にする

							//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0;    //踏んでいるblock確認用

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 60, 60, ELEMENT_PLAYER, OBJ_HERO, 1);

}

void CObjHero::Action()
{
	//移動
	m_vx += -(m_vx*0.3000);

	//自由落下運動  
	m_vy += 8.5 / (16.0f);
	/*
	do {
		m_vy += 8.5 / (16.0f);
	} while (m_vy > 10);
	*/


	//Xキー入力でジャンプ
	if (Input::GetVKey('X') == true)
	{
			if (m_hit_down == true)
			{
				m_vy = -18;//元は-16
			}

			if (m_f == true)
			{
				//ジャンプ
				Audio::Start(8);
				m_f = false;
			}

	}

	//Zキー入力で弾丸(トゲ)発射
	else if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{
			//発射音を鳴らす
			Audio::Start(3);
			
			//弾丸オブジェ作成
			CObjBullet* obj_b = new CObjBullet(m_px, m_py + 60.0f);
			Objs::InsertObj(obj_b, OBJ_BULLET, 100);

			m_f = false;
		}
	}
	//ホバリング
	else if (Input::GetVKey('C') == true)
	{	
		//落下速度制御
		if (m_vy < 15 && m_vy>=0) 
		{
			m_vy *= 15.3 / (16.0f);
		}

	}


	else
	{
		m_f = true;
	}

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

	if (m_ani_time > 5)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}
	if (m_ani_frame == 5)
	{

	}
	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);	//作成したHitBox更新用の入り口を取り出す
	hit->SetPos(m_px, m_py);				//入り口から新しい位置（主人公の位置)情報に置き換える

	//敵と接触したら主人公削除
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);		//自身に削除命令を出す
		Hits::DeleteHitBox(this);	//主人公が所有するHitBoxを削除する

		Scene::SetScene(new CSceneGameOver());
	}

}

void CObjHero::Draw()
{
	//歩くアニメーション
	int AniData[5] =
	{
		1,0,2,0,3
	};

	//描画カラー情報

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 56;
	src.m_right = 64.0f + AniData[m_ani_frame] * 56;
	src.m_bottom = 72.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f  * m_posture) + m_px;
	dst.m_right = (64 - 64.0f  * m_posture) + m_px;
	dst.m_bottom = 72.0f + m_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}