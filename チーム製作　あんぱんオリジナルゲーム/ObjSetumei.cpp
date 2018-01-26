//使用するヘッターファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjSetumei.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjSetumei::Init()
{
	m_key_flag = false;
}

//アクション
void CObjSetumei::Action()
{
	//エンターキーを押してシーン：説明に移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjSetumei::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"Enterキーでゲーム開始", 450, 800, 32, c);

	//描画カラー情報　R=RED　G=Green B=Blue A=alpha(透過情報）
	float d[4] = { 1.0f,0.5f,0.5f,1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置情報の設定
	src.m_top = 184.0f;
	src.m_left = 49.0f;
	src.m_right = 1160.0f;
	src.m_bottom = 850.0f;

	//表示位置の設定
	dst.m_top = 800.0f;
	dst.m_left = 0.0f;
	dst.m_right = 600.0f;
	dst.m_bottom = 500.0f;
	//4番目に登録したグラフィックをsrc・dst・dの情報を元に描画
	Draw::Draw(4, &src, &dst, d, 0.0f);
}
