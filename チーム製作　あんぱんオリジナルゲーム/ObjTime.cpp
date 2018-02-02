//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjTime.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTime::Init()
{
	m_time = 0;

	m_flag_time = false;

	m_key_flag = false;

}
//�A�N�V����
void CObjTime::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//�X�^�[�g�u���b�N�𓥂�ł���Ȃ�t���O���I���ɂ���
	if (hero->GetBT() == 2)
	{
		m_flag_time = true;
	}
	//�S�[��
	else if (hero->GetBT() == 4)
	{
		m_flag_time = false;

		//�S�[���u���b�N�𓥂񂾏ꍇ�G���f�B���O�Ɉڍs����
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

	//�t���O���I���̎��A���Ԃ�i�߂�
	if (m_flag_time == true)
	{
		m_time++;
	}

}
//�h���[
void CObjTime::Draw()
{
	//m_time����b�������߂�
	int minute;//��
	int second;//�b


	second = (m_time / 60) % 60;//�b
	minute = (m_time / 60) / 60;//��



	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	wchar_t str[128];

	////���F�b�̒l�𕶎���
	if (second < 10)
		swprintf_s(str, L"%d��0%d�b", minute, second);//�b��1���ڂ�0��p��
	else
		swprintf_s(str, L"%d��%d�b", minute, second);

	Font::StrDraw(str, 350, 8, 45, c);

}
