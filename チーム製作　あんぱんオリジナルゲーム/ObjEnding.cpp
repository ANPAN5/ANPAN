//使用するヘッダーファイル
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjEnding.h"
#include "ObjTime.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjEnding::Init()
{
	m_key_flag = false;
}

//アクション
void CObjEnding::Action()
{
	//エンターキーを押してシーン：タイトルに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
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
void CObjEnding::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"You did it!", 65, 270, 125, c);

	Font::StrDraw(L"GameClear", 190, 450, 100, c);

	Font::StrDraw(L"Please EnterKey", 220, 700, 50, c);
}