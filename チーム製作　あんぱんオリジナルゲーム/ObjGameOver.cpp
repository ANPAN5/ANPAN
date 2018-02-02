//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameOver.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOver::Init()
{
	m_key_flag;
}

//アクション
void CObjGameOver::Action()
{
	if (Input::GetVKey(VK_RETURN)==true)
	{
		if (m_key_flag==true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"Oh My God",120,250,100,c);
	Font::StrDraw(L"You got missing",60,400,100,c);
	Font::StrDraw(L"GameOver",220,600,50,c);
	Font::StrDraw(L"PleaseEnterKey", 220, 700, 50, c);

}