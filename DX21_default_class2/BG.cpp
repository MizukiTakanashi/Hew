/*==============================================================================

   ’¸“_ŠÇ— [polygon.cpp]
														 Author :
														 Date   :
--------------------------------------------------------------------------------

==============================================================================*/
#include	"BG.h"

//==========================
// ’è”‚Ì‰Šú‰»
//==========================
const float BG::UV_SPEED = 0.004f;

//=========================
// ”wŒi•`‰æ
//=========================
void BG::DrawBG()const
{
	//ƒeƒNƒXƒ`ƒƒ‚ÌÝ’è
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(m_tex_num));

	Sprite::DrawSpriteUVStart(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), m_start_uv_x, 0.0f, 1.0f, 1.0f);
}
