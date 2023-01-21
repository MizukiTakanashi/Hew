#pragma once
//=======================================
// 背景関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================

#include "main.h"
#include "sprite.h"
#include "texture.h"

class PoorVision
{
//定数
public:
	//cppで初期化

//メンバ変数
private:
	int m_tex_num = 0;				//テクスチャ番号
	D3DXVECTOR2 m_pos;

	bool m_fadein = false;
	float m_alp = 0.0f;

//メンバ関数
public:
	//引数付きコンストラクタ
	PoorVision(char * tex_name){ m_tex_num = LoadTexture(tex_name); }

	~PoorVision() {}	//デストラクタ

	//更新処理
	void Update(D3DXVECTOR2 pos);

	//描画処理
	void Draw()const;

	void SetPV();
};
