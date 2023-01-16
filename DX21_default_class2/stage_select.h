#pragma once
//=======================================
// �X�e�[�W�I����ʊ֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/29
// �쐬�ҁF��������
//=======================================

#ifndef _STAGE_SELECT_H_
#define _STAGE_SELECT_H_

#include "main.h"
#include "BG.h"
#include "draw_object.h"
#include "stage_select_planet.h"

class StageSelect
{
//�萔
private:
	enum class TEXTURE_TYPE :int
	{
		BG,
		MOON,
		MARS,
		MERCURY,
		JUPITER,
		VENUS,
		SATURN,
		SUN,
		WHITE_CIRCLE,
		NUM
	};

	enum class DRAW_TYPE :int
	{
		BG,
		MOON,
		MARS,
		MERCURY,
		JUPITER,
		VENUS,
		SATURN,
		SUN,
		WHITE_CIRCLE,
		NUM
	};


//�����o�ϐ�
private:
	int m_BGM = 0;	//BGM

	TextureUseful* m_pTexUseful = nullptr;
	DrawObject* m_pDrawObject = nullptr;

	BG* m_pBG = nullptr;
	
	StageSelectPlanet* m_pPlanet = nullptr;	//�f��

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	StageSelect(){}

	//�����t���R���X�g���N�^
	StageSelect(int stage_score[]);

	//�f�X�g���N�^
	~StageSelect() {}

	//�X�V(�f���̍X�V)
	void Update(void){ m_pPlanet->Update(); }

	//�`��
	void Draw(void)const;
};
#endif // !_STAGE_SELECT_H_