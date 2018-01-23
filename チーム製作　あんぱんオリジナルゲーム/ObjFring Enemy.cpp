//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjFring Enemy.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
FringEnemy::FringEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void FringEnemy::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�����蔻��pHit Box���쐬
	Hits::SetHitBox(this, m_x, m_y, 50, 50, ELEMENT_ENEMY,OBJ_FRING_ENEMY, 1);
}

//�A�N�V����
void FringEnemy::Action()
{
	//�ړ�����
	m_vx = -1.0f;
	m_vy = 0.0f;

	//�x�N�g���̒��������߂�
	float r = 0.0f;
	r = m_vx*m_vx + m_vy*m_vy;
	r = sqrt(r);

	if (r == 0.0f)
	{
		;
	}
	else
	{
		m_vx = 1.0f / r*m_vx;
		m_vy = 1.0f / r*m_vy;
	}

	//���x������
	m_vx *= 1.5f;
	m_vy *= 1.5f;

	//�ړ��x�N�g�������W�ɉ��Z����
	m_x= m_vx;
	m_y= m_vy;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x+655, m_y+70);

	//���ƐڐG���Ă�邩�ǂ����𒲂ׂ�
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�h���[
void FringEnemy::Draw()
{
	//�`��J���[���@R=RED G=Green B=Blue A=alpha(���ߏ��j
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�؂���ʒu�̐ݒ�
	src.m_top    = 20.0f;
	src.m_left   = 0.0f;
	src.m_right  = 209.0f;
	src.m_bottom = 107.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top    = 60.0f +m_y;
	dst.m_left   = 642.0f+m_x;
	dst.m_right  = 785.0f+m_x;
	dst.m_bottom = 190.0f+m_y;
	//0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�E���̏������ɕ`��
	Draw::Draw(1,&src, &dst,c,0.0f);
}