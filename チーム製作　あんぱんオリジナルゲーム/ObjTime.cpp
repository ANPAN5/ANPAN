//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjTime.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTime::Init()
{
	m_time = 0;

	m_flag_time = false;

	m_key_flag = false;

}
//アクション
void CObjTime::Action()
{
	//主人公の位置を取得
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//スタートブロックを踏んでいるならフラグをオンにする
	if (hero->GetBT() == 2)
	{
		m_flag_time = true;
	}
	//ゴール
	else if (hero->GetBT() == 4)
	{
		m_flag_time = false;

		//ゴールブロックを踏んだ場合エンディングに移行する
			if (m_key_flag == true)
			{
				Scene::SetScene(new Ending());
				m_key_flag = false;
			}
		
		else
		{
			m_key_flag = true;
		}

		
	}

	//フラグがオンの時、時間を進める
	if (m_flag_time == true)
	{
		m_time++;
	}

}
//ドロー
void CObjTime::Draw()
{
	//m_timeから秒分を求める
	int minute;//分
	int second;//秒


	second = (m_time / 60) % 60;//秒
	minute = (m_time / 60) / 60;//分



	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	wchar_t str[128];

	////分：秒の値を文字列化
	if (second < 10)
		swprintf_s(str, L"%d分0%d秒", minute, second);//秒の1桁目に0を用意
	else
		swprintf_s(str, L"%d分%d秒", minute, second);

	Font::StrDraw(str, 350, 8, 45, c);

}
