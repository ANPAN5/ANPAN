#pragma once
//使用するヘッダー
#include "GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class CObjHero : public CObj
{
	public:
		CObjHero() {};
		~CObjHero() {};
		void Init();
		void Action();
		void Draw();
	private:
};
