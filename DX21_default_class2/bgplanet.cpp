//=======================================
// �w�i�f���֌W(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "bg_planet.h"

//==========================
// �萔�̏�����
//==========================
const float BGPlanet::MOVE_SPEED = 0.2f;

//=========================
// �w�i�`��
//=========================
void BGPlanet::DrawBG()const
{
	//�e�N�X�`���̐ݒ�
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(m_tex_num));

	Sprite::DrawSpriteUVStart(SCREEN_WIDTH / 2, posy,
		800, 800, 0.0f, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 0.0f, 0.0f, 1.0f, 1.0f);
}
