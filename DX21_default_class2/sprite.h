
//==============================
//
//�X�v���C�g�`��
//==============================
#pragma once

#include "main.h"

class Sprite
{

public:
	Sprite();	//�f�t�H���g�R���X�g���N�^

	~Sprite();	//�f�X�g���N�^

	static void DrawSpriteAnimationRotation(float, float, float, float, float, const D3DXCOLOR&,
		float PaternNo, float uv_w, float uv_h, int NumPatern);

	static void DrawSpriteUVStart(float PosX, float PosY, float Size_W, float Size_H, float Kakudo, const D3DXCOLOR& col,
		float start_x, float start_y, float uv_w, float uv_h);
};