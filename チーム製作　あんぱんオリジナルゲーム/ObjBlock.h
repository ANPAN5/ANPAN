#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g��l��
class CObjBlock : public CObj
{
public:
	CObjBlock(int map[200][13]);
	~CObjBlock() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[


	void SetScroll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }


	//�u���b�N�Ƃ̓����蔻��
	void BlockHit(
		float*x, float*y, bool scroll_on,
		bool*up, bool*down, bool*left, bool*right,
		float* vx, float*vy, int*bt
	);


private:
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	int m_map[200][13];	//�}�b�v���

	float m_scroll;		//���E�X�N���[���p
};
