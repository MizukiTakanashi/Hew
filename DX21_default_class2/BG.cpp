//=======================================
// �w�i�֌W(cpp�t�@�C��)
// �쐬���F2022/11/07
// �쐬�ҁF��������
//=======================================
#include	"bg.h"

//==========================
// �萔�̏�����
//==========================
const float BG::UV_SPEED = 0.003f;

//=========================
// �w�i�`��
//=========================
void BG::DrawBG()const
{
	//�e�N�X�`���̐ݒ�
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(m_tex_num));

	Sprite::DrawSpriteUVStart(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
		SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 0.0f, m_start_uv_y, 1.0f, 0.7f);
}
