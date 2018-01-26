//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用するヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneSetumei::CSceneSetumei()
{

}

//デストラクタ
CSceneSetumei::~CSceneSetumei()
{

}

//ゲームメイン初期化メソッド
void CSceneSetumei::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"Enterキーでゲーム開始");

	//説明オブジェクト作成
	CObjSetumei*objs = new CObjSetumei();
	Objs::InsertObj(objs, OBJ_SETUMEI, 10);
}

//ゲームメイン実行中目メソッド
void CSceneSetumei::Scene()
{

}