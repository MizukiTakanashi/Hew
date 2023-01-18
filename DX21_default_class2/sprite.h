
//==============================
//
//スプライト描画
//==============================
#pragma once

#include "main.h"

class Sprite
{

public:
	Sprite();	//デフォルトコンストラクタ

	~Sprite();	//デストラクタ

	static void DrawSpriteAnimationRotation(float, float, float, float, float, const D3DXCOLOR&,
		float PaternNo, float uv_w, float uv_h, int NumPatern);

	static void DrawSpriteAnimationRotationReverse(float, float, float, float, float, const D3DXCOLOR&,
		float PaternNo, float uv_w, float uv_h, int NumPatern);

	static void DrawSpriteUVStart(float PosX, float PosY, float Size_W, float Size_H, float Kakudo, const D3DXCOLOR& col,
		float start_x, float start_y, float uv_w, float uv_h);
};