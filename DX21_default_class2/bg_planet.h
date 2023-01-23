//=======================================
// 背景惑星関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#include "main.h"
#include "sprite.h"
#include "texture.h"

class BGPlanet
{
//定数
public:
	//cppで初期化
	static const float MOVE_SPEED;	//背景の動くスピード

//メンバ変数
private:
	int m_tex_num = 0;				//テクスチャ番号
	float posy = -400.0f;

	//メンバ関数
public:
	BGPlanet() {}		//デフォルトコンストラクタ

	//引数付きコンストラクタ
	BGPlanet(char* tex_name) { m_tex_num = LoadTexture(tex_name); }

	~BGPlanet() {}	//デストラクタ

	//更新処理
	void Update() 
	{
		if (posy <= 0.0f)
		{
			posy += MOVE_SPEED;
		}
	}

	//描画処理
	void DrawBG()const;
	void DrawSaturn()const;
};
