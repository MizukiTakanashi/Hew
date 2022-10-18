//=======================================
// �I�u�W�F�N�g�`��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/12
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _DRAW_OBJECT_H_
#define _DRAW_OBJECT_H_

#include "main.h"
#include "sprite.h"
#include "texture_useful.h"

class DrawObject
{
private:
	TextureUseful m_pTexUseful;
	float m_paternNo = 0.0f;
	float m_uv_w = 0.0f;
	float m_uv_h = 0.0f;
	int m_tex_num = 0;

public:
	DrawObject(){}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	DrawObject(const TextureUseful& pTexUseful, 
		float paternNo = 0.0f, float uv_w = 1.0f, float uv_h = 1.0f, int tex_num = 1) 
		:m_pTexUseful(pTexUseful), m_paternNo(paternNo), m_uv_w(uv_w), m_uv_h(uv_h), m_tex_num(tex_num){}

	~DrawObject(){}	//�f�X�g���N�^

	void SetDrawObject(const TextureUseful& pTexUseful, float paternNo = 0.0f, float uv_w = 1.0f, 
		float uv_h = 1.0f, int tex_num = 1);

	//�`��
	void Draw(const D3DXVECTOR2& pos, const D3DXVECTOR2& size, 
		const D3DXCOLOR& col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), float rot = 0.0f)const;

	//�A�j���[�V�����ԍ��w��
	void SetPaterNo(float patenNo) { m_paternNo = patenNo; }
};

#endif // !_DRAW_OBJECT_H_