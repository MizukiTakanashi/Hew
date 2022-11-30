#pragma once
//=======================================
// �X�e�[�W�I����ʊ֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/29
// �쐬�ҁF��������
//=======================================

#ifndef _STAGE_SELECT_H_
#define _STAGE_SELECT_H_

#include "main.h"
#include "sprite.h"
#include "BG.h"
#include "draw_object.h"
#include "number.h"
#include "scene.h"
#include "stage_select_planet.h"

class StageSelect
{
//�萔
private:
	//�����ŏ�����
	static const int NUMBER_DIGIT = 10;		//�����̌�

	//cpp�ŏ�����
	static const D3DXVECTOR2 NUMBER_SIZE;	//�����̃T�C�Y
	static const D3DXVECTOR2 NUMBER_POS;	//�����̈ʒu

	enum class TEXTURE_TYPE :int
	{
		MOON,
		MARS,
		MERCURY,
		JUPITER,
		VENUS,
		SATURN,
		SUN,
		NUM
	};

	enum class DRAW_TYPE :int
	{
		MOON,
		MARS,
		MERCURY,
		JUPITER,
		VENUS,
		SATURN,
		SUN,
		NUM
	};


//�����o�ϐ�
private:
	int m_stage_score[STAGE_NUM];

	int m_BGM = 0;

	TextureUseful* m_pTexUseful = nullptr;
	DrawObject* m_pDrawObject = nullptr;

	BG* m_pBG = nullptr;

	UI* m_pMultiply = nullptr;
	Number* m_pComboNum = nullptr;
	
	StageSelectPlanet* m_pPlanet = nullptr;

//�����o�֐�
public:
	StageSelect();	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	StageSelect(int stage_score[]);

	~StageSelect() {}	//�f�X�g���N�^

	//�X�V
	void Update(void);

	//�`��
	void Draw(void)const;
};
#endif // !_STAGE_SELECT_H_