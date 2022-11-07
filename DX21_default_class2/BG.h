#pragma once
//=======================================
// 背景関係(ヘッダファイル)
// 作成日：2022/11/07
// 作成者：高梨水希
//=======================================

#include "main.h"
#include "sprite.h"
#include "texture.h"

class BG
{
//定数
public:
	//cppで初期化
	static const float UV_SPEED;	//背景の動くスピード

//メンバ変数
private:
	int m_tex_num = 0;				//テクスチャ番号
	float m_start_uv_y = 0.0f;		//UV座標Y

//メンバ関数
public:
	BG() {}		//デフォルトコンストラクタ

	//引数付きコンストラクタ
	BG(char * tex_name){ m_tex_num = LoadTexture(tex_name); }

	~BG() {}	//デストラクタ

	//更新処理
	void Update() { m_start_uv_y -= UV_SPEED; }

	//描画処理
	void DrawBG()const;
};
