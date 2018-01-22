//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"

#include "GameL\UserData.h"

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

	//グラフィック読み込み(主人公.ブロック、背景)
	Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);
	//グラフィック読み込み（飛ぶ敵）
	Draw::LoadImageW(L"FringEnemy.png", 1, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//飛ぶ敵オブジェクト
	FringEnemy* obj_fring_enemy = new FringEnemy(300, 700);
	Objs::InsertObj(obj_fring_enemy, OBJ_FRING_ENEMY, 15);

	/*//Test用 敵オブジェクト作成
	CObjEnemy* obje = new CObjEnemy();
	Objs::InsertObj(obje,OBJ_ENEMY,10);*/
}

//実行中メソッド
void CSceneMain::Scene()
{

}