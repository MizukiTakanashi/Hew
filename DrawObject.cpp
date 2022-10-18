//=======================================
// �I�u�W�F�N�g�`��֌W(cpp�t�@�C��)
// �쐬���F2022/09/12
// �쐬�ҁF��������
//=======================================
#include "DrawObject.h"

//======================
// �Z�b�g
//======================
void DrawObject::SetDrawObject(const TextureUseful& pTexUseful, float paternNo, float uv_w, float uv_h, int tex_num)
{
	m_pTexUseful = pTexUseful;
	m_paternNo = paternNo;
	m_uv_w = uv_w;
	m_uv_h = uv_h;
	m_tex_num = tex_num;
}

//==========================
// �`�揈��
//==========================
void DrawObject::Draw(const D3DXVECTOR2& pos, const D3DXVECTOR2& size, const D3DXCOLOR& col, float rot)const
{
	//�e�N�X�`���̐ݒ�
	GetDeviceContext()->PSSetShaderResources(0, 1,
		GetTexture(m_pTexUseful.GetTexIndexNum()));

	Sprite::DrawSpriteAnimationRotation(pos.x, pos.y, size.x, size.y, rot, col,
		m_paternNo, m_uv_w, m_uv_h, m_tex_num);
}