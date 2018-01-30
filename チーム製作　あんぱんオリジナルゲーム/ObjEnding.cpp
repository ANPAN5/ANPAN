//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjEnding.h"
#include "ObjTime.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjEnding::Init()
{
	m_key_flag = false;
}

//�A�N�V����
void CObjEnding::Action()
{
	//�G���^�[�L�[�������ăV�[���F�^�C�g���Ɉڍs����
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
//�h���[
void CObjEnding::Draw()
{
	int minute;//��
	int second;//�b

	CObjTime Time1;

	Time1.Draw();

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"You did it!", 140, 300, 125, c);

	Font::StrDraw(L"GameClear", 120, 600, 40, c);
}