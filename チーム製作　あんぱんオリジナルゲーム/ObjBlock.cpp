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


	//��l���̏Փˏ�Ԋm�F�p�t���O�̏�����
	hero->SetUp(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�v�f�ԍ������W�ɕύX
				float x = j*64.0f;
				float y = i*64.0f;

				//��l���ƃu���b�N�̓����蔻��                                             //����+�ɂ���Ɨ������x�`���[�W
				if ((hx + 64.0f > x) && (hx < x+64.0f) && (hy + 64.0f >(m_scroll)- y) && (hy - (m_scroll) < y + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float vx = hx - x;
					float vy = (hy-(-m_scroll)) - y;

					//���������߂�
					float len = sqrt(vx*vx + vy*vy);

					//�p�x�����߂�
					float r = atan2(vy, vx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//len��������̒������Z���ꍇ����ɓ���
					if (len < 88.0f)
					{

						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r>0) || r > 315)
						{
							//�E
							hero->SetRight(true);	//��l���̍��̕������Փ˂��Ă���
							hero->SetX(x + 64.0f);	//�u���b�N�̈ʒu+��l���̕�
							hero->SetVX(-hero->GetVX()*0.1f);//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							hero->SetDown(true);	//��l���̉��̕������Փ˂��Ă���
							hero->SetY(y - 64.0f+(-m_scroll));  //�u���b�N�̈ʒu-��l���̕�
							hero->SetVY(0.0f);
						}
						if (r > 135 && r < 225)
						{
							//��
							hero->SetLeft(true);	//��l���̉E�̕������Փ˂��Ă���
							hero->SetX(x - 64.0f);	//�u���b�N�̈ʒu-��l���̕�
							hero->SetVX(-hero->GetVX()*0.1f);//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							hero->SetUp(true);	  //��l���̏�̕������Փ˂��Ă���
							hero->SetY(y + 64.0f+(-m_scroll));//�u���b�N�̈ʒu+��l���̕�
							if (hero->GetVY() < 0)
							{
								hero->SetVY(0.0f);
							}
						}
					}
				}
			}
		}
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

//BlockDrawMethod�֐�
//����1�@float   x  :���\�[�X�؂���ʒuX
//����1�@float   x  :���\�[�X�؂���ʒuY
//����3�@RECT_F* dst:�`��ʒu
//����4 float   c[] :�J���[���
//�u���b�N��64X64����`��p�B�@���\�[�X�؂���ʒu�݂̂��E����
//�ݒ�ł���
void CObjBlock::BlockDraw(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//�`��
	Draw::Draw(0, &src, dst, c, 0.0f);

}
