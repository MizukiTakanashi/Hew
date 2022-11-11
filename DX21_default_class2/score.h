//=======================================
// �X�R�A�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once
#ifndef _SCORE_H_
#define _SCORE_H_

#include "main.h"
#include "UI.h"
#include "draw_object.h"

class Score :public UI
{
	//�萔
private:
	//cpp�ŏ�����
	static const float SPACE_RATIO;	//�����Ɛ����̊Ԃ̔䗦
	static const float COMBO_MAGNIFICATION; //�R���{�p�����̔{��

private:
	int m_num = 0;					//����			
	int m_digit = 0;				//����
	float m_space = 0.0f;			//�����Ɛ����̊�
	D3DXVECTOR2 m_init_pos = D3DXVECTOR2(0.0f, 0.0f);	//�����̍ŏ��̈ʒu
	float m_ComboMagnification = 1.0f; //�R���{�{��
	int m_ComboNum = 0; //�R���{�p����

public:
	Score() {}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	Score(DrawObject& pDrawObject, const D3DXVECTOR2& pos = D3DXVECTOR2(0.0f, 0.0f),
		const D3DXVECTOR2& size = D3DXVECTOR2(0.0f, 0.0f), int digit = 0);

	~Score()override {}	//�f�X�g���N�^

	//������ǉ�
	void AddScore(int num);

	//�������Z�b�g
	void SetNumber(int num) { m_num = 0; }

	//�������Z�b�g
	void SetDigit(int digit) { m_digit = digit; }

	//�������W���Z�b�g
	void SetInitPos(const D3DXVECTOR2& pos) { m_init_pos = pos; }

	//�`�揈��
	void DrawNumber(void);

	//�R���{���r�؂ꂽ���̏���
	void InitCombo(void) { m_ComboMagnification = 1.0f; m_ComboNum = 0; }

};

#endif // !_SCORE_H_