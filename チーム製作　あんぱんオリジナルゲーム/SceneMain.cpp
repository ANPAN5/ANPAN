//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include"GameL\Audio.h"

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
	//Font�쐬
	Font::SetStrTex(L"0123456789���b");

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
	//���y�ǂݍ���
	Audio::LoadAudio(0, L"�^�C�g��.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"�������.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(2, L"�Q�[����.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(3, L"���ˉ�.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(4, L"���e��.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(5, L"�G���j.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(6, L"�Q�[���I�[�o�[.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(7, L"�S�[��.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(8, L"�W�����v.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(9, L"����.wav", SOUND_TYPE::EFFECT);


	//�{�����[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(1.0 - v);

	//���y�X�^�[�g
	Audio::Start(2);

	//�O���t�B�b�N�ǂݍ���(�����G)
	Draw::LoadImageW(L"Enemy1.png",3, TEX_SIZE_512);
	//�O���t�B�b�N�ǂݍ���(��l��.�u���b�N�A�w�i)
	Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);
	//�O���t�B�b�N�ǂݍ��݁i��ԓG�j
	Draw::LoadImageW(L"FringEnemy.png", 1, TEX_SIZE_512);
	//�O���t�B�b�N�ǂݍ���(�ǐՓG)
	Draw::LoadImageW(L"�H��@��.png", 2, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//�^�C���I�u�W�F�N�g�쐬
	CObjTime* objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 11);

}

//���s�����\�b�h
void CSceneMain::Scene()
{

}