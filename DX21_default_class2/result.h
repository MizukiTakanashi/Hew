//=======================================
// ���U���g��ʊ֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/22
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _RESULT_H_
#define _RESULT_H_

#include "texture_useful.h"
#include "draw_object.h"
#include "UI.h"
#include "score.h"
#include "main.h"

class Result
{
//�萔
private:
	//�����ŏ�����
	static const int NUMBER_DIGIT = 10 ;

	//cpp�ŏ�����
	static const D3DXVECTOR2 NUMBER_POS;
	static const D3DXVECTOR2 NUMBER_SIZE;


//�����o�ϐ�
private:
	int m_BGM = 0;

	TextureUseful* m_pTexUse = nullptr;
	DrawObject* m_pDrawOb = nullptr;
	UI* m_pBG = nullptr;
	Score* m_pScore = nullptr;

public:
	Result();	//�f�t�H���g�R���X�g���N�^

	Result(Score* pNumber);

	~Result();	//�f�X�g���N�^

	//�X�V����
	void Update(void);

	//�`�揈��
	void Draw(void)const;
};

#endif // !_RESULT_H_