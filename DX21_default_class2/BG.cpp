//=======================================
// 背景関係(cppファイル)
// 作成日：2022/11/07
// 作成者：高梨水希
//=======================================
#include	"bg.h"

//==========================
// 定数の初期化
//==========================
const float BG::UV_SPEED = 0.003f;

//=========================
// 背景描画
//=========================
void BG::DrawBG()const
{
	//テクスチャの設定
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(m_tex_num));

	Sprite::DrawSpriteUVStart(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 0.0f, m_start_uv_y, 1.0f, 0.7f);
}
