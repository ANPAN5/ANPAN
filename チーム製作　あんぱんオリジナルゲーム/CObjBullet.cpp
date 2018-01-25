//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "CObjBullet.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBullet::CObjBullet(float x, float y)
{
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void CObjBullet::Init()
{
	
}

//�A�N�V����
void CObjBullet::Action()
{
	m_py += 5.0f;
}

//�h���[
void CObjBullet::Draw()

{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu
	src.m_top    = 30.0f;
	src.m_left   = 280.0f;
	src.m_right  = 380.0f;
	src.m_bottom = 62.0f;

	//�\���ʒu
	dst.m_top    = 0.0f+m_py;
	dst.m_left   = 10.0f+m_px;
	dst.m_right  = 40.0f+m_px;
	dst.m_bottom = 45.0f+m_py;

	//0�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������ɕ`��
	Draw::Draw(0, &src, &dst, c, -90.0f);
}
