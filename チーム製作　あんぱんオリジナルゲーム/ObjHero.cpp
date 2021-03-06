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
	m_x = 0.0f;
	m_y = 0.0f;
	m_time = 0;


	m_ani_time = 0;
	m_ani_frame = 1;		//静止フレームを初期にする

	m_ani_saikou_time = 4;

							//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0;    //踏んでいるblock確認用

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 35, 65, ELEMENT_PLAYER, OBJ_HERO, 1);

}

//アクション
void CObjHero::Action()
{
	//移動
	m_vx += -(m_vx*0.3000);

	//自由落下運動
	m_vy += 7.5 / (16.0f);

	//Zキー入力で弾丸(トゲ)発射
	if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{
			//発射音を鳴らす
			Audio::Start(3);

			//オブジェ作成
			CObjBullet* obj_b = new CObjBullet(m_px, m_py + 60.0f);
			Objs::InsertObj(obj_b, OBJ_BULLET, 100);

			m_f = false;
		}
	}

	//Xキー入力でジャンプ
	else if (Input::GetVKey('X') == true)
	{
			if (m_hit_down == true)
			{
				m_vy = -18;//元は-18
			}

			if (m_f == true)
			{
				//ジャンプ
				Audio::Start(8);
				m_f = false;
			}
	}
	else if (Input::GetVKey('C') == true)
	{
		m_vx = 0.0f;
			//落下速度制御
			if (m_vy > 1)
			{
				m_vy = 125
					/ (16.0f);
			}
			if (m_f == true)
			{
				//滑空音
				Audio::Start(9);
				m_f = false;
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
	if (m_ani_time > m_ani_saikou_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
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
	hit->SetPos(m_px+15, m_py-5);				//入り口から新しい位置（主人公の位置)情報に置き換える10
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
	int AniData[4] =
	{
		1,0,2,0
	};

	//描画カラー情報

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top    = 0.0f;
	src.m_left   = 0.0f  + AniData[m_ani_frame] * 47;
	src.m_right  = 61.0f + AniData[m_ani_frame] * 47;
	src.m_bottom = 72.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f  * m_posture) + m_px;
	dst.m_right = (64 - 64  * m_posture) + m_px;
	dst.m_bottom = 72.0f + m_py;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}