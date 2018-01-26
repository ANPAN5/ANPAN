#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�e��
class CObjBullet : public CObj
{
public:
	CObjBullet(float x,float y);		//�R���X�g���N�^
	~CObjBullet() {};
	void Init();    //�C�j�V�����C�Y
	void Action();  //�A�N�V����
	void Draw();    //�h���[
private:
	float m_px;		//�e��X�����̈ʒu�p�ϐ�
	float m_py;     //�e�ۂ�Y�����̈ʒu�p�ϐ�
	float m_vy;		//�e�ۂ�Y�����̑��x�p�ϐ�

	int    m_ani;		//���e�A�j���[�V�����p
	int    m_ani_time;	//���e�A�j���[�V�����Ԋu�^�C��
	bool   m_del;		//�폜�`�F�b�N
	RECT_F m_eff;		//���e�G�t�F�N�g�`��p
};