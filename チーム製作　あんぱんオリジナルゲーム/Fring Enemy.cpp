//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "Fring Enemy.h"

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
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY,OBJ_FRING_ENEMY, 1);
}

//�A�N�V����
void FringEnemy::Action()
{
	//�ړ�����
	m_vx = 1.0f;
	m_vy = 0.0f;

	//���x������
	m_vx *= 2.0f;
	m_vy *= 2.0f;

	//�ړ��x�N�g�������W�ɉ��Z����
	m_x= m_vy;
	m_x= m_vy;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

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
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 30.0f+ src.m_left;
	src.m_bottom = 30.0f+ src.m_top;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 20.0f;
	dst.m_right = 30.0f+dst.m_left;
	dst.m_bottom = 30.0f+dst.m_top;
	//0�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�E���̏������ɕ`��
	Draw::Draw(1,&src, &dst,c,0.0f);
}