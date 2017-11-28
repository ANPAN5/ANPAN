#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g:�u���b�N&�w�i
class CObjBlock : public CObj
{
	public :
		CObjBlock() {};
		~CObjBlock() {};
		void Init();	//�C�j�V�����C�Y
		void Action();	//�A�N�V����
		void Draw();	//�h���[
	private:
		float m_px;		//�ʒu
		float m_py;
		float m_vx;		//�ړ�
		float m_vy;
		float m_posture;	//�p��

		int m_ani_time;	//�A�j���[�V�����t���[������Ԋu
		int m_ani_frame;//�`��t���[��
};
