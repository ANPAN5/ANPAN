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
	int minute;//分
	int second;//秒

	CObjTime Time1;

	Time1.Draw();

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"You did it!", 140, 300, 125, c);

	Font::StrDraw(L"GameClear", 120, 600, 40, c);
}