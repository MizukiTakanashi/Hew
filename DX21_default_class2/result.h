//=======================================
// ���U���g��ʊ֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/22
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _RESULT_H_
#define _RESULT_H_

#include "texture_useful.h"
#include "DrawObject.h"
#include "UI.h"
#include "number.h"
#include "main.h"

class Result
{
//�萔
private:
	//�����ŏ�����
	static const int NUMBER_DIGIT = 3;

	//cpp�ŏ�����
	static const D3DXVECTOR2 NUMBER_POS;
	static const D3DXVECTOR2 NUMBER_SIZE;


//�����o�ϐ�
private:
	int m_BGM = 0;

	TextureUseful* m_pTexUse = nullptr;
	DrawObject* m_pDrawOb = nullptr;
	UI* m_pBG = nullptr;
	Number* m_pNumber = nullptr;

public:
	Result();	//�f�t�H���g�R���X�g���N�^

	Result(Number* pNumber);

	~Result();	//�f�X�g���N�^

	//�X�V����
	void Update(void);

	//�`�揈��
	void Draw(void)const;
};

#endif // !_RESULT_H_