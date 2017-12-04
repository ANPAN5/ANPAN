//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//������
void CObjHero::Init()
{
	m_px = 0.0f;
	m_py = 0.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_posture = 1.0f;	//�E0.0f ��1.0f

	m_ani_time = 0;
	m_ani_time = 1;		//�Î~�t���[���������ɂ���
}

void CObjHero::Action()
{
	//�ړ��x�N�g���̔j��
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�L�[�̓��͕���
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx = +1.0f;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx = -1.0f;
		m_posture = 0.0f;
		m_ani_time += 1;
	}

	else
	{
		m_ani_frame = 1;	//�L�[���͂��Ȃ��ꍇ�͐Î~�t���[��
		m_ani_time = 0;
	}

	if (m_ani_time > 4)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//�X�V�̈ʒu
	m_px += m_vx;
	m_py += m_vy;
}

void CObjHero::Draw()
{
	//�����A�j���[�V����
	int AniData[4] =
	{
		1,0,2,0,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 0.0f;
	src.m_left   = 0.0f +AniData[m_ani_frame]*64;
	src.m_right  = 75.0f+AniData[m_ani_frame]*64;
	src.m_bottom = 90.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f +m_py;
	dst.m_left   = (     75.0f * m_posture) + m_px;
	dst.m_right  = (75 - 75.0f * m_posture) + m_px;
	dst.m_bottom = 90.0f+m_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}