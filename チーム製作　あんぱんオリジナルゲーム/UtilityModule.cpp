#include<math.h>
#include"GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;
//UntiVec関数
//引数1　float* vx:ベクトルのX成分のポインタ
//引数2　float* vy:ベクトルのY成分のポインタ
//戻り値　bool		:ture=計算成功　　false=計算失敗
//内容
//引数のベクトルを正規化しその値をvx,vyに変更します
//ベクトルの正規化を行う関数

bool UnitVec(float*vx, float*vy)
{
	//ベクトルの長さを求める
	float r = 0.0f;
	r = (*vx)*(*vx) + (*vy)*(*vy);
	r = sqrt(r);

	//長さが0かどうか調べる
	if (r == 0.0f)
	{
		//0なら計算失敗
		return false;
	}
	else
	{
		//正規化を行い、vxとvyの参照先の値を変更
		(*vx) = 1.0f / r*(*vx);
		(*vy) = 1.0f / r*(*vy);
	}
	//計算成功
	return true;
}
//CheckWindow関数
//引数1　float pos_x:領域外かどうか調べるｘ位置
//引数2  float pos_y:領域外かどうか調べるｙ位置
//引数3　float window_x :領域のtop位置
//引数4  float window_y領域のleft位置
//引数5　float window_w:領域のright位置
//引数6　float window_h:領域のbottom位置
//戻り値　bool		:ture=計算成功　　false=計算失敗
//内容
//引数のベクトルを正規化しその値をvx,vyに変更します
//ベクトルの正規化を行う関数
bool CheckWindow(float pos_x, float pos_y,
	float window_x, float window_y, float window_w, float window_h)
{

	//領域内チェック
	if (pos_x<window_x)
	{
		return false; //領域外
	}
	if (pos_x>window_w)
	{
		return false; //領域外
	}
	if (pos_y<window_y)
	{
		return false; //領域外
	}
	if (pos_y>window_h)
	{
		return false; //領域外
	}

	return true;	//領域内
}
//---GetAtan2Angle関数
//引数1　float w：幅
//引数2　float h: 高さ
//戻り値 float   :角度（0°～360°）
//内容
//高さと幅から直角三角形があると仮定しその角度を求める。
float GetAtan2Angle(float w, float h)
{
	//atan2で角度を求める
	float r = atan2(h, w)*180.0f / 3.14f;

	//-180°～-0°を180°～360°に変換
	if (r<0)
	{
		r = 360 - abs(r);
	}
	return r;
}
//---GetBulletEffect関数
//引数1 int* ani;  着弾エフェクト
//引数2　int*　ani_time; 着弾アニメーション間隔タイム
//引数3　bool del;　削除チェック
//引数4　int timing 間隔区間
//戻り値 RECT_F eff;
//delで弾丸のRECTや着弾effectのRECTを返す
RECT_F GetBulletEffec(int*ani, int*ani_time, bool del, int timing)
{
	RECT_F rect;

	if (del == true)
	{
		RECT_F ani_src[4] =
		{
			{ 0,0,93,82 },
			{ 0, 93, 190, 82 },
			{ 0,190,290,82 },
			{ 0,290,375,82 },
		};
		if (*ani_time>timing)
		{
			*ani += 1;
			*ani_time += 0;
		}
		else
		{
			*ani_time += 1;
		}
		rect = ani_src[*ani];
	}
	else
	{
		//着弾アニメーションなし
		//リソース敵位置
		RECT_F bullet = { 0.0f,40.0f,130.0f,360.0f };
		rect = bullet;
	}
	return rect;
}