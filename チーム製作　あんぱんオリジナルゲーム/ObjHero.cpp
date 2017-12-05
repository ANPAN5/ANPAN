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
	m_ani_frame = 1;		//�Î~�t���[���������ɂ���

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up    = false;
	m_hit_down  = false;
	m_hit_left  = false;
	m_hit_right = false;
}

void CObjHero::Action()
{
	//�ړ��x�N�g���̔j��
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�L�[�̓��͕���
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_vx += 2.0f;
		m_posture = 1.0f;
		m_ani_time += 1;
	}

	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_vx -= 2.0f;
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

	/*//��l���ƃu���b�N�̓����蔻��
	if ((hx + 64.0f > x) && (hx < x + 64.0f) && (hy + 64.0f > y) && (hy < y + 64.0f))
	{
		//�㉺���E����

		//vactor�̍쐬
		float vx = hx - x;
		float vy = hy - y;

		//���������߂�
		float len = sqrt(vx*vx + vy*vy);

		//�p�x�����߂�
		float r = atan2(vy, vx);
		r = r*180.0f / 3.14f;

		if (r <= 0.0f)
			r = abs(r);
		else
			r = 360.0f - abs(r);

		//�p�x�ŏ㉺���E�𔻒�
		if (r<45 && r>0||r>315)
		{
			//�E
		}
		if (r>45 && r<135)
		{
			//��
			hero->SetY(y-64.0f);//�u���b�N�̈ʒu�E��l���̕�
		}
		if (r>135 && r<255)
		{
			//��
		}
		if (r>225 && r<315)
		{
			//��
		}

	}*/



	//���R�����^��
	m_vy += 9.8 / (16.0f);

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
	src.m_left   = 0.0f +AniData[m_ani_frame]*56;
	src.m_right  = 64.0f+AniData[m_ani_frame]*56;
	src.m_bottom = 72.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = 0.0f +m_py;
	dst.m_left   = (     64.0f  * m_posture) + m_px;
	dst.m_right  = (64 - 64.0f  * m_posture) + m_px;
	dst.m_bottom = 72.0f+m_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}