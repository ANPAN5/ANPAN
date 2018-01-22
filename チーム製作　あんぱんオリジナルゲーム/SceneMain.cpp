//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include "GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//���������\�b�h
void CSceneMain::InitScene()
{
	//�O���f�[�^�̓ǂݍ���(�X�e�[�W���)
	unique_ptr<wchar_t> p;	//�X�e�[�W���|�C���^�[
	int size;				//�X�e�[�W���̑傫��

	p = Save::ExternalDataOpen(L"Book1.csv", &size);//�O���f�[�^�ǂݍ���

	int map[200][13];
	int count = 1;
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;

		}
	}

	//�O���t�B�b�N�ǂݍ���(��l��.�u���b�N�A�w�i)
	Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);
	//�O���t�B�b�N�ǂݍ��݁i��ԓG�j
	Draw::LoadImageW(L"FringEnemy.png", 1, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//��ԓG�I�u�W�F�N�g
	FringEnemy* obj_fring_enemy = new FringEnemy(300, 700);
	Objs::InsertObj(obj_fring_enemy, OBJ_FRING_ENEMY, 15);

	/*//Test�p �G�I�u�W�F�N�g�쐬
	CObjEnemy* obje = new CObjEnemy();
	Objs::InsertObj(obje,OBJ_ENEMY,10);*/
}

//���s�����\�b�h
void CSceneMain::Scene()
{

}