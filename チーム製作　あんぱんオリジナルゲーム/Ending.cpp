//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"Ending.h"
#include"GameHead.h"

//コンストラクタ
Ending::Ending()
{

}

//デストラクタ
Ending::~Ending()
{

}

//初期化メソッド
void Ending::InitScene()
{
	Font::SetStrTex(L"You did it!");
	Font::SetStrTex(L"Game Clear");

	//クリアオブジェクト作成
	CObjEnding*obj = new CObjEnding();
	Objs::InsertObj(obj, OBJ_ENDING, 10);
}

//実行中メソッド
void Ending::Scene()
{

}