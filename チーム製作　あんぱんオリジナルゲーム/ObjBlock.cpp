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
//BlockHit関数
//引数1 float x			:リソース切り取り位置Ｘ
//引数2 float y			:リソース切り取り位置Ｙ
//引数3 bool scroll_on	:判定を行うobjectはスクロールの影響を与えるかどうか(true=与える、false=与えない)
//引数4 bool* up		:上下左右判定の上部分に当たっているかどうかを返す
//引数5 bool* down		:上下左右判定の下部分に当たっているかどうかを返す
//引数6 bool* left		:上下左右判定の左部分に当たっているかどうかを返す
//引数7 bool* right     :上下左右判定の右部分に当たっているかどうかを返す
//引数8 float* vx		:左右判定時の反発による移動方向・力の値を変えて返す
//引数9 float* vy		:上下判定時による自由落下速度運動の移動方向・力の値を変えて返す
//引数10 int* bt		:下部分判定時、特殊なブロックのタイプを返す
//判定を行うobjectとブロック64×64限定で、当たり判定と上下左右判定を行う
//その結果は引数4～10に返す
void CObjBlock::BlockHit(
	float *x, float *y, bool scroll_on,
	bool*up, bool*down, bool*left, bool*right,
	float* vx, float* vy, int* bt
)
{
	;
}
