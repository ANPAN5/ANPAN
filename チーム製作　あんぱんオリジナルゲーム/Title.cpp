//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"

#include"GameHead.h"
#include"Title.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CTitle::Init()
{

}
//アクション
void CTitle::Action()
{

}

//ドロー
void CTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 0.0f;
	dst.m_bottom = 0.0f;

	Draw::Draw(1, &src, &dst, c, 0.0f);
}