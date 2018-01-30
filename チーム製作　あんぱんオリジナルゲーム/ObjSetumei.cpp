//�g�p����w�b�^�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
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
	//�G���^�[�L�[�������ăV�[���F���C����ʂɈڍs����
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
	Font::StrDraw(L"�ړ��@���L�[:���L�[",100,200,50,c);

	Font::StrDraw(L"�W�����v  X�L�[", 100, 300, 50, c);

	Font::StrDraw(L"�e�۔���  Z�L�[", 100, 400, 50, c);

	Font::StrDraw(L"���@��	�@ C�L�[", 100, 500, 50, c);

	Font::StrDraw(L"Enter�L�[�ŃQ�[���J�n", 450, 800, 32, c);

}
