//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjBlock.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBlock::CObjBlock(int map[200][13])
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, map, sizeof(int)*(200 * 13));
}

//�C�j�V�����C�Y
void CObjBlock::Init()
{
	m_scroll = 0.0f;
}

//�A�N�V����
void CObjBlock::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//����X�N���[�����C��
	if (hy < 200)
	{
		hero->SetY(200);			//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll += hero->GetVY();	//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}

	//�����X�N���[�����C��
	if (hy > 500)
	{
		hero->SetY(500);			//��l���̓��C���𒴂��Ȃ��悤�ɂ���
		m_scroll += hero->GetVY();	//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
	}


	
}
//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�w�i�\��
	src.m_top = 256.0f;
	src.m_left = 0.0f;
	src.m_right = 180.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 840.0f;
	dst.m_bottom = 900.0f;
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//�؂���ʒu�̐ݒ�
	src.m_top = 27.0f;
	src.m_left = 230.0f;
	src.m_right = 264.0f;
	src.m_bottom = 60.0f;

	


	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i*64.0f - m_scroll;	
				dst.m_left	 = j*64.0f ;
				dst.m_right  = dst.m_left+70.0;
				dst.m_bottom = dst.m_top + 70.0 ;


				//�`��
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
		}
	}
}

///BlockDrawMethod�֐�
//����1�@float   x  :���\�[�X�؂���ʒuX
//����1�@float   x  :���\�[�X�؂���ʒuY
//����3�@RECT_F* dst:�`��ʒu
//����4 float   c[] :�J���[���
//�u���b�N��64X64����`��p�B�@���\�[�X�؂���ʒu�݂̂��E����
//�ݒ�ł���
void CObjBlock::BlockDraw(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top    = y;
	src.m_left   = x;
	src.m_right  = src.m_left + 64.0f;
	src.m_bottom = src.m_top  + 64.0f;
	//�`��
	Draw::Draw(0, &src, dst, c, 0.0f);

}

//BlockHit�֐�
//����1 float* x   :������s��object��X�ʒu
//����2 float* y   :������s��object��Y�ʒu
//����3 bool  scroll_on :������s��object�̓X�N���[���̉e���^���邩�ǂ���(ture=�^����@false=�^���Ȃ��j
//����4 bool* up   :�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//����5 bool* down :�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//����6 bool* left :�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//����7 bool* right:�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//����8 float* vx  :���E���莞�̔����ɂ��ړ������E�͂̒l��ς��ĕԂ�
//����9 float* vy  :�㉺���莞�ɂ�鎩�R�����^���̈ړ������E�͂̒l��ς��ĕԂ�
//����10 int* bt   :���������莞�A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N64�~64����ŁA�����蔻��Ə㉺���E������s��
//���̌��ʂ͈���4�`10�ɕԂ�
void CObjBlock::BlockHit(
	float *x, float *y, bool scroll_on,
	bool*up, bool*down, bool*left, bool*right,
	float*vx, float*vy, int*bt
)
{
	//��l���̏Փˏ�Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//����ł���u���b�N�̎�ނ̏�����
	*bt = 0;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*64.0f;
				float by = i*64.0f;

				//�X�N���[���̉e��
				float scroll = scroll_on ? m_scroll : 0;

				//��l���ƃu���b�N�̓����蔻��
				if ((*x + 64.0f > bx) && (*x < bx + 64.0f) && (*y +(-scroll)+ 64.0f > by) && (*y+(-scroll) < by + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = *x + bx;
					float rvy = (*y - (-scroll))-by;

					//���������߂�
					float len = sqrt(rvx*rvx + rvy*rvy);

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//len��������̒������Z���ꍇ����ɓ���
					if (len < 80.0f)
					{

						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r>0) || r > 315)
						{
							//�E
							*right = true;//�I�u�W�F�N�g�̍��̕������Փ˂��Ă���
							*x = bx + 64.0f + (scroll);//�u���b�N�̈ʒu+�I�u�W�F�N�g�̕�
							*vx = -(*vx)*0.1f;//-VX*�����W��
						}
						if (r > 45 && r < 135)

						{
							//��
							*down = true;//�I�u�W�F�N�g�̉��̕������Փ˂��Ă���
							*y = by - 64.0f;//�u���b�N�̈ʒu-�I�u�W�F�N�g�̕�
							//��ނ�n���̃X�^�[�g�ƃS�[���̂ݕύX����
							if (m_map[i][j] >= 2)
								*bt = m_map[i][j];//�u���b�N�̗v�f�itype)����l���ɓn��
							*vy = 0.0f;
						}
						if (r > 135 && r < 225)
						{
							//��
							*left = true;//�I�u�W�F�N�g�̉E�̕������Փ˂��Ă���
							*x = bx - 64.0f + (scroll);//�u���b�N�̈ʒu-�u���b�N�̕�
							*vx = (*vx)*0.1f;//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							*up = true;//�I�u�W�F�N�g�̏�̕������Փ˂��Ă���
							*y + 64.0f;//�u���b�N�̈ʒu+��l���̕�
							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}
					}
				}
			}
		}
	}
	;
}