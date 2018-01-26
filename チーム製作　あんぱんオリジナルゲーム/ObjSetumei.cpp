//�g�p����w�b�^�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjSetumei.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjSetumei::Init()
{
	m_key_flag = false;
}

//�A�N�V����
void CObjSetumei::Action()
{
	//�G���^�[�L�[�������ăV�[���F�����Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjSetumei::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"Enter�L�[�ŃQ�[���J�n", 450, 800, 32, c);

	//�`��J���[���@R=RED�@G=Green B=Blue A=alpha(���ߏ��j
	float d[4] = { 1.0f,0.5f,0.5f,1.0f };

	RECT_F src;
	RECT_F dst;

	//�؂���ʒu���̐ݒ�
	src.m_top = 184.0f;
	src.m_left = 49.0f;
	src.m_right = 1160.0f;
	src.m_bottom = 850.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 800.0f;
	dst.m_left = 0.0f;
	dst.m_right = 600.0f;
	dst.m_bottom = 500.0f;
	//4�Ԗڂɓo�^�����O���t�B�b�N��src�Edst�Ed�̏������ɕ`��
	Draw::Draw(4, &src, &dst, d, 0.0f);
}
