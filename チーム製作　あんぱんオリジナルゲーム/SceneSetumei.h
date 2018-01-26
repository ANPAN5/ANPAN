#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：操作説明
class CSceneSetumei :public CScene
{
public:
	CSceneSetumei();
	~CSceneSetumei();
	void InitScene();	//タイトルの初期化メソッド
	void Scene();		//タイトルの実行中メソッド
private:
};