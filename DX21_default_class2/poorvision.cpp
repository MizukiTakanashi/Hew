//=======================================
// �w�i�֌W(cpp�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#include "poorvision.h"

//==========================
// �萔�̏�����
//==========================

void PoorVision::Update(D3DXVECTOR2 pos)
{
	m_pos = pos;

	if (m_fadein)
	{
		m_alp += 0.05f;
		if (m_alp > 5.0f)
		{
			m_fadein = false;
		}
	}
	else
	{
		m_alp -= 0.05;
	}
}

//=========================
// �w�i�`��
//=========================
void PoorVision::Draw()const
{
	//�e�N�X�`���̐ݒ�
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(m_tex_num));

	Sprite::DrawSpriteUVStart(m_pos.x, m_pos.y,
		SCREEN_WIDTH * 3, SCREEN_HEIGHT * 3, 0.0f, D3DXCOLOR(1.0f, 1.0f, 1.0f, m_alp), 0.0f, 0.0f, 1.0f, 1.0f);
}

void PoorVision::SetPV()
{
	m_fadein = true;
	m_alp = 0.0f;
}
