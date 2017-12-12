#pragma once
//使用するヘッダーファイル
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：クリア
class Ending :public CScene
{
public:
	Ending();
	~Ending();
	void InitScene();
	void Scene();
private:
};