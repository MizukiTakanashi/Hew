//=======================================
// UI�֌W(cpp�t�@�C��)
// �쐬���F2022/09/17
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _UI_H_
#define _UI_H_

#include "main.h"
#include "DrawObject.h"

class UI
{
private:
	DrawObject m_DrawObject;
	D3DXVECTOR2 m_pos = D3DXVECTOR2(0.0f, 0.0f);
	D3DXVECTOR2 m_size = D3DXVECTOR2(0.0f, 0.0f);
	D3DXCOLOR m_color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

public:
	UI(){}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	UI(DrawObject& draw_object, const D3DXVECTOR2& pos, const D3DXVECTOR2& size, 
		const D3DXCOLOR& color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f))
		:m_DrawObject(draw_object), m_pos(pos), m_size(size), m_color(color){}

	~UI(){}	//�f�X�g���N�^

	//�`��
	void Draw(void)const { m_DrawObject.Draw(m_pos, m_size, m_color); }

	//���W���Z�b�g
	void SetPos(const D3DXVECTOR2& pos) { m_pos = pos; }

	//�T�C�Y���Z�b�g
	void SetSize(const D3DXVECTOR2& size) { m_size = size; }

	//�A�j���[�V�����ԍ����Z�b�g
	void SetAnimationNum(float num) { m_DrawObject.SetPaterNo(num); }

	//���W��Ԃ�
	const D3DXVECTOR2& GetPos(void) { return m_pos; }

	//�T�C�Y��Ԃ�
	const D3DXVECTOR2& GetSize(void) { return m_size; }
};


#endif // !_UI_H_