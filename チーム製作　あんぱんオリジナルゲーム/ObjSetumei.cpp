//使用するヘッターファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
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
	//エンターキーを押してシーン：メイン画面に移行する
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
	Font::StrDraw(L"移動　←キー:→キー",100,200,50,c);

	Font::StrDraw(L"ジャンプ  Xキー", 100, 300, 50, c);

	Font::StrDraw(L"弾丸発射  Zキー", 100, 400, 50, c);

	Font::StrDraw(L"滑　空	　 Cキー", 100, 500, 50, c);

	Font::StrDraw(L"Enterキーでゲーム開始", 450, 800, 32, c);

}
