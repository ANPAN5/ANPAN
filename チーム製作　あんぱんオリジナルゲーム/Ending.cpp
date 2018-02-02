//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"Ending.h"
#include"GameHead.h"

//�R���X�g���N�^
Ending::Ending()
{

}

//�f�X�g���N�^
Ending::~Ending()
{

}

//���������\�b�h
void Ending::InitScene()
{
	Font::SetStrTex(L"You did it!");
	Font::SetStrTex(L"Game Clear");
	//���y�ǂݍ���
	Audio::LoadAudio(7, L"�S�[��.wav", BACK_MUSIC);

	//�{�����[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(1.0 - v);

	//���y�X�^�[�g
	Audio::Start(7);

	//�N���A�I�u�W�F�N�g�쐬
	CObjEnding*obj = new CObjEnding();
	Objs::InsertObj(obj, OBJ_ENDING, 10);
}

//���s�����\�b�h
void Ending::Scene()
{

}