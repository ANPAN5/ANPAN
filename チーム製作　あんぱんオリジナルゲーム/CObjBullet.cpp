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
	
	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 36, 25, ELEMENT_PLAYER, OBJ_BULLET, 1);

}

//�A�N�V����
void CObjBullet::Action()
{
	m_py += 10.0f;

	if (m_del==true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		return;
	}


	//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px+10, m_py);				//HitBox�̈ʒu��e�ۂ̈ʒu�ɍX�V

	//�e�ۂ��̈�O�ɏo����e�ۍ폜
	if (m_py > 950.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}


	//�����蔻����s���I�u�W�F�N�g���
	int data_base[3] =
	{
		OBJ_ENEMY,
		OBJ_HOMING_ENEMY,
        OBJ_FRING_ENEMY,
	};

	//�I�u�W�F�N�g���Ɠ����蔻����s���A�������Ă���΍폜
	for (int i = 0; i < 3; i++)
	{
		if (hit->CheckObjNameHit(data_base[i]) != nullptr)
		{
			m_del = true;			//���Ŏ��s
			hit->SetInvincibility(true);
		}
	}

	return;//���ŏ����́A�����ŃA�N�V�������\�b�h���I��������


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
