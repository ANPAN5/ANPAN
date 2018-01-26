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

///BlockDrawMethod関数
//引数1　float   x  :リソース切り取り位置X
//引数1　float   x  :リソース切り取り位置Y
//引数3　RECT_F* dst:描画位置
//引数4 float   c[] :カラー情報
//ブロックを64X64限定描画用。　リソース切り取り位置のみｘ・ｙで
//設定できる
void CObjBlock::BlockDraw(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top    = y;
	src.m_left   = x;
	src.m_right  = src.m_left + 64.0f;
	src.m_bottom = src.m_top  + 64.0f;
	//描画
	Draw::Draw(0, &src, dst, c, 0.0f);

}

//BlockHit関数
//引数1 float* x   :判定を行うobjectのX位置
//引数2 float* y   :判定を行うobjectのY位置
//引数3 bool  scroll_on :判定を行うobjectはスクロールの影響与えるかどうか(ture=与える　false=与えない）
//引数4 bool* up   :上下左右判定の上部分に当たっているかどうかを返す
//引数5 bool* down :上下左右判定の下部分に当たっているかどうかを返す
//引数6 bool* left :上下左右判定の左部分に当たっているかどうかを返す
//引数7 bool* right:上下左右判定の右部分に当たっているかどうかを返す
//引数8 float* vx  :左右判定時の反発による移動方向・力の値を変えて返す
//引数9 float* vy  :上下判定時による自由落下運動の移動方向・力の値を変えて返す
//引数10 int* bt   :下部分判定時、特殊なブロックのタイプを返す
//判定を行うobjectとブロック64×64限定で、当たり判定と上下左右判定を行う
//その結果は引数4～10に返す
void CObjBlock::BlockHit(
	float *x, float *y, bool scroll_on,
	bool*up, bool*down, bool*left, bool*right,
	float*vx, float*vy, int*bt
)
{
	//主人公の衝突状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//踏んでいるブロックの種類の初期化
	*bt = 0;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float bx = j*64.0f;
				float by = i*64.0f;

				//スクロールの影響
				float scroll = scroll_on ? m_scroll : 0;

				//主人公とブロックの当たり判定
				if ((*x + 64.0f > bx) && (*x < bx + 64.0f) && (*y +(-scroll)+ 64.0f > by) && (*y+(-scroll) < by + 64.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = *x + bx;
					float rvy = (*y - (-scroll))-by;

					//長さを求める
					float len = sqrt(rvx*rvx + rvy*rvy);

					//角度を求める
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さより短い場合判定に入る
					if (len < 80.0f)
					{

						//角度で上下左右を判定
						if ((r < 45 && r>0) || r > 315)
						{
							//右
							*right = true;//オブジェクトの左の部分が衝突している
							*x = bx + 64.0f + (scroll);//ブロックの位置+オブジェクトの幅
							*vx = -(*vx)*0.1f;//-VX*反発係数
						}
						if (r > 45 && r < 135)

						{
							//上
							*down = true;//オブジェクトの下の部分が衝突している
							*y = by - 64.0f;//ブロックの位置-オブジェクトの幅
							//種類を渡すのスタートとゴールのみ変更する
							if (m_map[i][j] >= 2)
								*bt = m_map[i][j];//ブロックの要素（type)を主人公に渡す
							*vy = 0.0f;
						}
						if (r > 135 && r < 225)
						{
							//左
							*left = true;//オブジェクトの右の部分が衝突している
							*x = bx - 64.0f + (scroll);//ブロックの位置-ブロックの幅
							*vx = (*vx)*0.1f;//-VX*反発係数
						}
						if (r > 225 && r < 315)
						{
							//下
							*up = true;//オブジェクトの上の部分が衝突している
							*y + 64.0f;//ブロックの位置+主人公の幅
							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}
					}
				}
			}
		}
	}
	;
}