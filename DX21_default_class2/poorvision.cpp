//=======================================
// 背景関係(cppファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#include "poorvision.h"

//==========================
// 定数の初期化
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
// 背景描画
//=========================
void PoorVision::Draw()const
{
	//テクスチャの設定
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(m_tex_num));

	Sprite::DrawSpriteUVStart(m_pos.x, m_pos.y,
		SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, 0.0f, D3DXCOLOR(1.0f, 1.0f, 1.0f, m_alp), 0.0f, 0.0f, 1.0f, 1.0f);
}

void PoorVision::SetPV()
{
	m_fadein = true;
	m_alp = 0.0f;
}
