//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p����w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneSetumei::CSceneSetumei()
{

}

//�f�X�g���N�^
CSceneSetumei::~CSceneSetumei()
{

}

//�Q�[�����C�����������\�b�h
void CSceneSetumei::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"Enter�L�[�ŃQ�[���J�n");

	//�����I�u�W�F�N�g�쐬
	CObjSetumei*objs = new CObjSetumei();
	Objs::InsertObj(objs, OBJ_SETUMEI, 10);
}

//�Q�[�����C�����s���ڃ��\�b�h
void CSceneSetumei::Scene()
{

}