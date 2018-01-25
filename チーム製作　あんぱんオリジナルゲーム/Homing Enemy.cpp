//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameHead.h"
#include"Homing Enemy.h"
#include"UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjHomingEnemy::CObjHomingEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjHomingEnemy::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_time = 0;

	m_eff.m_top = 32;
	m_eff.m_left = 0;
	m_eff.m_right = 32;
	m_eff.m_bottom = 64;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;

	//�ړ��x�N�g��
	UnitVec(&m_vy, &m_vx);
	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_HOMING_ENEMY, 1);
}
//�A�N�V����
void CObjHomingEnemy::Action()
{
	//Resources�̕`�敨��RECT
	m_eff = GetBulletEffec(&m_ani, &m_ani_time, m_del, 4);
	float ar = 0.0f;
	//��l���@�ƗU���e�ۂŊp�x�����
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{
		float x = obj->GetX() - m_x;
		float y = obj->GetY() - m_y;
		float ar = GetAtan2Angle(x, -y);

		if (ar< 0)
		{
			ar = 360 - abs(ar);
		}

		//�e�ۂ̌��݂̌����Ă���p�x�����
		float br = GetAtan2Angle(m_vx, -m_vy);
		if (br < 0)
		{
			br = 360 - abs(br);
		}

		float r = 3.14 / 180.0f;

		if (ar < br)
		{
			//�ړ�������+1��������
			m_vx = m_vx*cos(r) - m_vy*sin(r);
			m_vy = m_vy*cos(r) + m_vx*sin(r);
		}
		else
		{
			//�ړ�������-1��������
			m_vx = m_vx*cos(-r) - m_vy*sin(-r);
			m_vy = m_vy*cos(-r) + m_vx*sin(-r);
		}
		UnitVec(&m_vx, &m_vy);


		//��l���@�ƓG�@�p�x�����܂�ɂ��������ꂽ��
		if (ar - br > 20)
		{
			//�ړ���������l���@�̕����ɂ���
			m_vx = cos(3.14 / 180 * ar);
			m_vy = -sin(3.14 / 180 * ar);
		}
	}
	m_x += m_vx;
	m_y += m_vy;

	//�U���e�ۂ�HitBox�X�V�p�|�C���^�[�擾
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);	//HitBox�̈ʒu��U���e�ۂ̈ʒu�ɍX�V

	/*�U���e�ۂ����S�ɗ̈�O�ɏo����U���e�ۂ�j������
	bool check = CheckWindow(m_x, m_y, -32.0f, -32.0f, 800.0f, 900.0f);
	if (check == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}*/

	//��l���I�u�W�F�N�g�ƐڐG������H��폜
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		m_del = true;
		hit->SetInvincibility(true);
	}

}
//�h���[
void CObjHomingEnemy::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F dst;
	float r = 0.0f;


	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0 + m_y;

	//��l���@�ƗU���e�ۂŊp�x�����
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//��l���@�����݂���ꍇ�A�U���p�x���v�Z����
	if (obj != nullptr)
	{
		float x = obj->GetX() - m_x;
		float y = obj->GetY() - m_y;
		r = GetAtan2Angle(x, -y);
		if (r < 0)
		{
			r = 360 - abs(r);
		}
	}

	//�O�Ԗڂɓo�^�����O���t�B�b�N��src.dst.c�̏������ɕ`��
	Draw::Draw(2, &m_eff, &dst, c, r);
}