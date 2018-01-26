#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G�@�e��
class CObjHomingEnemy :public CObj
{
public:
	CObjHomingEnemy(float x, float y);
	~CObjHomingEnemy() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_x;
	float m_y;
	float m_vx;
	float m_vy;
	int m_time;

	int m_ani;//���e�A�j���[�V����
	int m_ani_time;//���e�A�j���[�V�������o�^�C��
	bool m_del;	//�폜�`�F�b�N
	RECT_F m_eff; //���e�G�t�F�N�g

};