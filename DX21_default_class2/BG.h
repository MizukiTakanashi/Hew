/*==============================================================================

   頂点管理[polygon.h]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#pragma once


#include "main.h"
#include "sprite.h"
#include "texture.h"

class BG
{
public:
	//定数
	static const float UV_SPEED;	//背景の動くスピード

private:
	int m_tex_num = 0;
	float m_start_uv_y = 0.0f;

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
