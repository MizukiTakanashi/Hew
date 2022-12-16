#pragma once
//=======================================
// �X�R�A�\���֌W(�w�b�_�t�@�C��)
// �쐬���F2022/12/16
// �쐬�ҁF��������
//=======================================

#ifndef _TITLE_SCORE_H_
#define _TITLE_SCORE_H_

#include "score.h"
#include "scene.h"
#include "UI.h"

class TitleScore
{
//�萔
private:


//�����o�ϐ�
private:
	TextureUseful* m_pTexUse[5];
	DrawObject* m_pDrawOb[5];

	UI* m_pBG = nullptr;
	Score* m_pScore = nullptr;
	int m_score[STAGE_NUM];

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	TitleScore(){
		for (int i = 0; i < STAGE_NUM; i++) {
			m_score[i] = 0;
		}
	}

	//�����t���R���X�g���N�^
	TitleScore(Score* pNumber, int score[]);

	//�X�V����
	void Update(void);

	//�`�揈��
	void Draw(void);
};

#endif // !_TITLE_SCORE_H_