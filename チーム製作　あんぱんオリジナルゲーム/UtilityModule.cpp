#include<math.h>
#include"GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
//UntiVec�֐�
//����1�@float* vx:�x�N�g����X�����̃|�C���^
//����2�@float* vy:�x�N�g����Y�����̃|�C���^
//�߂�l�@bool		:ture=�v�Z�����@�@false=�v�Z���s
//���e
//�����̃x�N�g���𐳋K�������̒l��vx,vy�ɕύX���܂�
//�x�N�g���̐��K�����s���֐�

bool UnitVec(float*vx, float*vy)
{
	//�x�N�g���̒��������߂�
	float r = 0.0f;
	r = (*vx)*(*vx) + (*vy)*(*vy);
	r = sqrt(r);

	//������0���ǂ������ׂ�
	if (r == 0.0f)
	{
		//0�Ȃ�v�Z���s
		return false;
	}
	else
	{
		//���K�����s���Avx��vy�̎Q�Ɛ�̒l��ύX
		(*vx) = 1.0f / r*(*vx);
		(*vy) = 1.0f / r*(*vy);
	}
	//�v�Z����
	return true;
}
//CheckWindow�֐�
//����1�@float pos_x:�̈�O���ǂ������ׂ邘�ʒu
//����2  float pos_y:�̈�O���ǂ������ׂ邙�ʒu
//����3�@float window_x :�̈��top�ʒu
//����4  float window_y�̈��left�ʒu
//����5�@float window_w:�̈��right�ʒu
//����6�@float window_h:�̈��bottom�ʒu
//�߂�l�@bool		:ture=�v�Z�����@�@false=�v�Z���s
//���e
//�����̃x�N�g���𐳋K�������̒l��vx,vy�ɕύX���܂�
//�x�N�g���̐��K�����s���֐�
bool CheckWindow(float pos_x, float pos_y,
	float window_x, float window_y, float window_w, float window_h)
{

	//�̈���`�F�b�N
	if (pos_x<window_x)
	{
		return false; //�̈�O
	}
	if (pos_x>window_w)
	{
		return false; //�̈�O
	}
	if (pos_y<window_y)
	{
		return false; //�̈�O
	}
	if (pos_y>window_h)
	{
		return false; //�̈�O
	}

	return true;	//�̈��
}
//---GetAtan2Angle�֐�
//����1�@float w�F��
//����2�@float h: ����
//�߂�l float   :�p�x�i0���`360���j
//���e
//�����ƕ����璼�p�O�p�`������Ɖ��肵���̊p�x�����߂�B
float GetAtan2Angle(float w, float h)
{
	//atan2�Ŋp�x�����߂�
	float r = atan2(h, w)*180.0f / 3.14f;

	//-180���`-0����180���`360���ɕϊ�
	if (r<0)
	{
		r = 360 - abs(r);
	}
	return r;
}
//---GetBulletEffect�֐�
//����1 int* ani;  ���e�G�t�F�N�g
//����2�@int*�@ani_time; ���e�A�j���[�V�����Ԋu�^�C��
//����3�@bool del;�@�폜�`�F�b�N
//����4�@int timing �Ԋu���
//�߂�l RECT_F eff;
//del�Œe�ۂ�RECT�⒅�eeffect��RECT��Ԃ�
RECT_F GetBulletEffec(int*ani, int*ani_time, bool del, int timing)
{
	RECT_F rect;

	if (del == true)
	{
		RECT_F ani_src[4] =
		{
			{ 0,0,93,82 },
			{ 0, 93, 190, 82 },
			{ 0,190,290,82 },
			{ 0,290,375,82 },
		};
		if (*ani_time>timing)
		{
			*ani += 1;
			*ani_time += 0;
		}
		else
		{
			*ani_time += 1;
		}
		rect = ani_src[*ani];
	}
	else
	{
		//���e�A�j���[�V�����Ȃ�
		//���\�[�X�G�ʒu
		RECT_F bullet = { 0.0f,40.0f,130.0f,360.0f };
		rect = bullet;
	}
	return rect;
}