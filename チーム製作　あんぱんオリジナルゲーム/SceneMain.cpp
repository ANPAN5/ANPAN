//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//初期化メソッド
void CSceneMain::InitScene()
{
	//Font作成
	Font::SetStrTex(L"0123456789分秒");

	//外部データの読み込み(ステージ情報)
	unique_ptr<wchar_t> p;	//ステージ情報ポインター
	int size;				//ステージ情報の大きさ

	p = Save::ExternalDataOpen(L"Book1.csv", &size);//外部データ読み込み

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
	//音楽読み込み
	Audio::LoadAudio(0, L"タイトル.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"操作説明.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(2, L"ゲーム内.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(3, L"発射音.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(4, L"着弾音.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(5, L"敵撃破.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(6, L"ゲームオーバー.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(7, L"ゴール.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(8, L"ジャンプ.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(9, L"滑空音.wav", SOUND_TYPE::EFFECT);


	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(1.0 - v);

	//音楽スタート
	Audio::Start(2);

	//グラフィック読み込み(歩く敵)
	Draw::LoadImageW(L"Enemy1.png",3, TEX_SIZE_512);
	//グラフィック読み込み(主人公.ブロック、背景)
	Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);
	//グラフィック読み込み（飛ぶ敵）
	Draw::LoadImageW(L"FringEnemy.png", 1, TEX_SIZE_512);
	//グラフィック読み込み(追跡敵)
	Draw::LoadImageW(L"幽霊　普.png", 2, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//タイムオブジェクト作成
	CObjTime* objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 11);

}

//実行中メソッド
void CSceneMain::Scene()
{

}