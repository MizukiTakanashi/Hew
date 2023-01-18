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
	float m_paternNo = 0.0f;		//���݂̃A�j���[�V�����ԍ�
	float m_uv_w = 0.0f;			//����UV�T�C�Y
	float m_uv_h = 0.0f;			//�c��UV�T�C�Y
	int m_tex_num = 0;				//���ɕ���ł���A�j���[�V������
	D3DXCOLOR m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);	//�F

public:
	DrawObject(){}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	DrawObject(const TextureUseful& pTexUseful, 
		float paternNo = 0.0f, float uv_w = 1.0f, float uv_h = 1.0f, int tex_num = 1,
		const D3DXCOLOR& color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f))
		:m_pTexUseful(pTexUseful), m_paternNo(paternNo), m_uv_w(uv_w), m_uv_h(uv_h), 
		m_tex_num(tex_num), m_color(color) {}

	~DrawObject(){}	//�f�X�g���N�^

	void SetDrawObject(const TextureUseful& pTexUseful, float paternNo = 0.0f, float uv_w = 1.0f, 
		float uv_h = 1.0f, int tex_num = 1, const D3DXCOLOR& color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

	//�`��
	void Draw(const D3DXVECTOR2& pos, const D3DXVECTOR2& size, float rot = 0.0f)const;
	void DrawReverse(const D3DXVECTOR2& pos, const D3DXVECTOR2& size, float rot = 0.0f)const;

	//�F���Z�b�g
	void SetDrawColor(const D3DXCOLOR& col) { m_color = col; }

	//�A�j���[�V�����ԍ��w��
	void SetPaterNo(float patenNo) { m_paternNo = patenNo; }
	
	//�A�j���[�V�����ԍ���Ԃ�
	int GetPaterNo(void) { return (int)m_paternNo; }
};

#endif // !_DRAW_OBJECT_H_