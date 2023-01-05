//=======================================
// ”wŒiŠÖŒW(cppƒtƒ@ƒCƒ‹)
// ì¬“úF2022/11/07
// ì¬ŽÒF‚—œ…Šó
//=======================================
#include	"bg.h"

//==========================
// ’è”‚Ì‰Šú‰»
//==========================
const float BG::UV_SPEED = 0.003f;

//=========================
// ”wŒi•`‰æ
//=========================
void BG::DrawBG()const
{
	//ƒeƒNƒXƒ`ƒƒ‚ÌÝ’è
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(m_tex_num));

	Sprite::DrawSpriteUVStart(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 0.0f, m_start_uv_y, 1.0f, 0.7f);
}
