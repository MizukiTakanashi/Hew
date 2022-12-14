//=======================================
// ”wŒi˜f¯ŠÖŒW(cppƒtƒ@ƒCƒ‹)
// ì¬“úF
// ì¬ŽÒF‰¶“c—ms
//=======================================
#include "bg_planet.h"

//==========================
// ’è”‚Ì‰Šú‰»
//==========================
const float BGPlanet::MOVE_SPEED = 0.2f;

//=========================
// ”wŒi•`‰æ
//=========================
void BGPlanet::DrawBG()const
{
	//ƒeƒNƒXƒ`ƒƒ‚ÌÝ’è
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(m_tex_num));

	Sprite::DrawSpriteUVStart(SCREEN_WIDTH / 2, posy,
		800, 800, 0.0f, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 0.0f, 0.0f, 1.0f, 1.0f);
}
