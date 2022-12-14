//=======================================
// 背景惑星関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "bg_planet.h"

//==========================
// 定数の初期化
//==========================
const float BGPlanet::MOVE_SPEED = 0.2f;

//=========================
// 背景描画
//=========================
void BGPlanet::DrawBG()const
{
	//テクスチャの設定
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(m_tex_num));

	Sprite::DrawSpriteUVStart(SCREEN_WIDTH / 2, posy,
		800, 800, 0.0f, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 0.0f, 0.0f, 1.0f, 1.0f);
}
