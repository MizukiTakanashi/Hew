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
	enum class STAGE_NUM : int
	{
		STAGE1,
		STAGE2,
		STAGE3,
		STAGE4,
		STAGE5,
		STAGE6,
		STAGE7,
		STAGE_NUM,
	};
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

	TextureUseful* m_pTexUse[4] = { nullptr, nullptr , nullptr , nullptr };
	DrawObject* m_pDrawOb[4] = { nullptr, nullptr , nullptr , nullptr };
	UI* m_pBG = nullptr;
	UI* m_pTitle = nullptr;
	UI* m_pContinue = nullptr;
	UI* m_pRetry = nullptr;
	Score* m_pScore = nullptr;

public:
	Result();	//�f�t�H���g�R���X�g���N�^

	Result(Score* pNumber);
	Result(Score* pNumber, STAGE_NUM stagenum);

	~Result();	//�f�X�g���N�^

	//�X�V����
	void Update(void);

	//�`�揈��
	void Draw(void)const;
};

#endif // !_RESULT_H_