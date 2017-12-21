//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjBlock.h"

//使用するネームスペース
using namespace GameL;

CObjBlock::CObjBlock(int map[200][13])
{
	//マップデータをコピー
	memcpy(m_map, map, sizeof(int)*(200 * 13));
}

//イニシャライズ
void CObjBlock::Init()
{
	m_scroll = 0.0f;
}

//アクション
void CObjBlock::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//上方スクロールライン
	if (hy < 200)
	{
		hero->SetY(200);			//主人公はラインを超えないようにする
		m_scroll += hero->GetVY();	//主人公が本来動くべき分の値をm_scrollに加える
	}

	//下方スクロールライン
	if (hy > 500)
	{
		hero->SetY(500);			//主人公はラインを超えないようにする
		m_scroll += hero->GetVY();	//主人公が本来動くべき分の値をm_scrollに加える
	}


	//主人公の衝突状態確認用フラグの初期化
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	//m_mapの全要素にアクセス
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float x = j*64.0f;
				float y = i*64.0f;

				//主人公とブロックの当たり判定                                             //↓を+にすると落下速度チャージ
				if ((hx + 64.0f > x) && (hx < x+64.0f) && (hy + 64.0f >(m_scroll)- y) && (hy - (m_scroll) < y + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float vx = hx - x;
					float vy = (hy-(-m_scroll)) - y;

					//長さを求める
					float len = sqrt(vx*vx + vy*vy);

					//角度を求める
					float r = atan2(vy, vx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さより短い場合判定に入る
					if (len < 88.0f)
					{

						//角度で上下左右を判定
						if ((r < 45 && r>0) || r > 315)
						{
							//右
							hero->SetRight(true);	//主人公の左の部分が衝突している
							hero->SetX(x + 64.0f);	//ブロックの位置+主人公の幅
							hero->SetVX(-hero->GetVX()*0.1f);//-VX*反発係数
						}
						if (r > 45 && r < 135)
						{
							//上
							hero->SetDown(true);	//主人公の下の部分が衝突している
							hero->SetY(y - 64.0f+(-m_scroll));  //ブロックの位置-主人公の幅
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225)
						{
							//左
							hero->SetLeft(true);	//主人公の右の部分が衝突している
							hero->SetX(x - 64.0f);	//ブロックの位置-主人公の幅
							hero->SetVX(-hero->GetVX()*0.1f);//-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							//下
							hero->SetUp(true);	  //主人公の上の部分が衝突している
							hero->SetY(y + 64.0f+(-m_scroll));//ブロックの位置+主人公の幅
							if (hero->GetVY() < 0)
							{
								hero->SetVY(0.0f);
							}
						}
					}
				}
			}
		}
	}
}
//ドロー
void CObjBlock::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//背景表示
	src.m_top = 256.0f;
	src.m_left = 0.0f;
	src.m_right = 180.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 840.0f;
	dst.m_bottom = 900.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//切り取り位置の設定
	src.m_top = 27.0f;
	src.m_left = 230.0f;
	src.m_right = 264.0f;
	src.m_bottom = 60.0f;

	


	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (m_map[i][j] > 0)
			{
				//表示位置の設定
				dst.m_top = i*64.0f - m_scroll;	
				dst.m_left	 = j*64.0f ;
				dst.m_right  = dst.m_left+70.0;
				dst.m_bottom = dst.m_top + 70.0 ;


				//描画
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
		}
	}
}

//BlockDrawMethod関数
//引数1　float   x  :リソース切り取り位置X
//引数1　float   x  :リソース切り取り位置Y
//引数3　RECT_F* dst:描画位置
//引数4 float   c[] :カラー情報
//ブロックを64X64限定描画用。　リソース切り取り位置のみｘ・ｙで
//設定できる
void CObjBlock::BlockDraw(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//描画
	Draw::Draw(0, &src, dst, c, 0.0f);

}
