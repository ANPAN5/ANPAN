//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITRATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include"SceneGameOver.h"
#include"GameHead.h"

//コンストラクタ
CSceneGameOver::CSceneGameOver()
{

}

//デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}

//初期化メソッド
void CSceneGameOver::InitScene()
{
	//出力させる文字のグラフィック作成
	Font::SetStrTex(L"Oh My God");
	Font::SetStrTex(L"You got missing");
	Font::SetStrTex(L"GameOver");
	Font::SetStrTex(L"PleaseEnterKey");

	//音楽読み込み
	Audio::LoadAudio(5, L"ゲームオーバー.wav", BACK_MUSIC);

	//ボリュームを戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster(1.0 - v);

	//音楽すたーと
	Audio::Start(5);

	//ゲームオーバーオブジェクト作成
	CObjGameOver*obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);
}

//実行中メソッド
void CSceneGameOver::Scene()
{

}