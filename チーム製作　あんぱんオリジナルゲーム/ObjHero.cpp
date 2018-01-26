//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "CObjBullet.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 70.0f;
	m_py = 64.0f; //�ʒu
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_posture = 1.0f;	//�E0.0f ��1.0f
	m_f = true;

	m_ani_time = 0;
	m_ani_frame = 1;		//�Î~�t���[���������ɂ���

							//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_block_type = 0;    //����ł���block�m�F�p

						 //�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 60, 67, ELEMENT_PLAYER, OBJ_HERO, 1);

}

void CObjHero::Action()
{
	//X�L�[���͂ŃW�����v
	if (Input::GetVKey('X') == true)
	{
		if (m_hit_down == true)
		{
			m_vy = -20;//����-16
		}
	}

	//Z�L�[���͂Œe��(�g�Q)����
	if (Input::GetVKey('Z') == true)
	{
		if (m_f == true)
		{
			//�e�ۃI�u�W�F�쐬
			CObjBullet* obj_b = new CObjBullet(m_px, m_py + 60.0f);
			Objs::InsertObj(obj_b, OBJ_BULLET, 100);

			m_f = false;
		}
	}

	else
	{
		m_f = true;
	}

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

	//�ړ�
	m_vx += -(m_vx*0.3000);

	//���R�����^��    
	m_vy += 8.5 / (16.0f);

	/*�������x�����Ł@����ׂȂ��A�����Ȃ�
	while (m_vy < 10) {
	m_vy += 8.5 / (16.0f);
	}*/

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);	//�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_px, m_py);				//���������V�����ʒu�i��l���@�̈ʒu)���ɒu��������

	/*//�G�ƐڐG���Ă邩�ǂ������ׂ�
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}*/

	//�G�ƐڐG�������l���폜
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);		//���g�ɍ폜���߂��o��
		Hits::DeleteHitBox(this);	//��l�������L����HitBox���폜����

		Scene::SetScene(new CSceneGameOver());
	}

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
	src.m_top = 0.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 56;
	src.m_right = 64.0f + AniData[m_ani_frame] * 56;
	src.m_bottom = 72.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f  * m_posture) + m_px;
	dst.m_right = (64 - 64.0f  * m_posture) + m_px;
	dst.m_bottom = 72.0f + m_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}