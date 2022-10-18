//=======================================
// �����֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/29
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _NUMBER_H_
#define _NUMBER_H_

#include "main.h"
#include "UI.h"
#include "DrawObject.h"

class Number:public UI
{
//�萔
private:
	//cpp�ŏ�����
	static const float SPACE_RATIO;	//�����Ɛ����̊Ԃ̔䗦

private:
	int m_num = 0;					//����			
	int m_digit = 0;				//����
	float m_space = 0.0f;			//�����Ɛ����̊�
	D3DXVECTOR2 m_init_pos = D3DXVECTOR2(0.0f, 0.0f);	//�����̍ŏ��̈ʒu

public:
	Number(){}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	Number(DrawObject& pDrawObject, const D3DXVECTOR2& pos = D3DXVECTOR2(0.0f, 0.0f),
		const D3DXVECTOR2& size = D3DXVECTOR2(0.0f, 0.0f), int digit = 0);

	~Number(){}	//�f�X�g���N�^

	//������ǉ�
	void AddNumber(int num) { m_num += num; }

	//�������Z�b�g
	void SetNumber(int num) { m_num = 0; }

	//�������Z�b�g
	void SetDigit(int digit) { m_digit = digit; }

	//�������W���Z�b�g
	void SetInitPos(const D3DXVECTOR2& pos) { m_init_pos = pos; }

	//�`�揈��
	void DrawNumber(void);
};

#endif // !_NUMBER_H_