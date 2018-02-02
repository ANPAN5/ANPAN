//STLデバック機能をoffにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain.h"
#include"GameHead.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{

}
//デストラクタ
CSceneTitle::~CSceneTitle()
{

}
//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	Font::SetStrTex(L"シューティングゲーム");

	//音楽情報の読み込み
	Audio::LoadAudio(0, L"タイトル.wav", SOUND_TYPE::BACK_MUSIC);
	//マスターボリューム
	float Volume = Audio::VolumeMaster(-0.8f);
	//音楽スタート
	Audio::Start(0);	
	//タイトルオブジェクト作成
	CObjTitle*obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 10);

}
//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{

}