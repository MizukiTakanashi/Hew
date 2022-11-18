//=======================================
// �X�R�A�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once
#ifndef _SCORE_H_
#define _SCORE_H_

#include "main.h"
#include "number.h"
#include "draw_object.h"

class Score :public Number
{
	//�萔
private:
	//cpp�ŏ�����
	static const float COMBO_MAGNIFICATION; //�R���{�p�����̔{��

private:
	float m_ComboMagnification = 1.0f; //�R���{�{��
	int m_ComboNum = 0; //�R���{�p����

public:
	Score() {}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	Score(DrawObject& pDrawObject, const D3DXVECTOR2& pos = D3DXVECTOR2(0.0f, 0.0f),
		const D3DXVECTOR2& size = D3DXVECTOR2(0.0f, 0.0f), int digit = 0);

	~Score()override {}	//�f�X�g���N�^

	//�X�R�A��ǉ�
	void AddScore(int num);


	//�R���{���r�؂ꂽ���̏���
	void InitCombo(void) { m_ComboMagnification = 1.0f; m_ComboNum = 0; }

};

#endif // !_SCORE_H_