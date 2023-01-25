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
	static const int NUMBER_DIGIT = 5 ;

	//cpp�ŏ�����
	static const D3DXVECTOR2 NUMBER_POS;
	static const D3DXVECTOR2 NUMBER_SIZE;


//�����o�ϐ�
private:
	int m_BGM = 0;		//BGM
	int m_SE_01 = 0;	//���艹
	int m_SE_03 = 0;	//�J�[�\���ړ���
	STAGE m_stage;

	TextureUseful* m_pTexUse[3] = { nullptr, nullptr , nullptr};
	DrawObject* m_pDrawOb[3] = { nullptr, nullptr , nullptr};
	UI* m_pBG = nullptr;
	UI* m_pStageTitle = nullptr;
	UI* m_pCursor = nullptr;
	Score* m_pScore = nullptr;

	bool m_isClear = false;		//CLEAR�������ǂ���
	bool m_select_retry = false; //�ǂ�����I�����Ă��邩

	float m_thumb_before = 0.0f;	//�X�e�B�b�N�̒l

public:
	Result(bool isClear, Score* pNumber, STAGE stagenum);

	~Result();	//�f�X�g���N�^

	//�X�V����
	void Update(void);

	//�`�揈��
	void Draw(void)const;

	//�I����ς���
	void Select(void)
	{
		if (m_select_retry)
		{
			m_select_retry = false;
		}
		else
		{
			m_select_retry = true;
		}
	}
};

#endif // !_RESULT_H_