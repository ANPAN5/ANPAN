#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�N���A
class CObjEnding :public CObj
{
public:
	CObjEnding() {};
	~CObjEnding() {};
	void Init();
	void Action();
	void Draw();
private:
	bool m_key_flag;
};
