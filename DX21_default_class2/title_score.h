#pragma once
//=======================================
// �X�R�A�\���֌W(�w�b�_�t�@�C��)
// �쐬���F2022/12/16
// �쐬�ҁF��������
//=======================================

#ifndef _TITLE_SCORE_H_
#define _TITLE_SCORE_H_

#include "number.h"
#include "scene.h"
#include "UI.h"

class TitleScore
{
//�萔
private:
	enum class TEXTURE_TYPE :int 
	{
		BG,
		FLAME,
		WORD,
		NUMBER,
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
		BG,
		WORD,
		NUMBER,
		MERCURY,
		VENUS,
		MARS,
		JUPITER,
		SATURN,
		SUN,
		FLAME_MERCURY,
		FLAME_VENUS,
		FLAME_MARS,
		FLAME_JUPITER,
		FLAME_SATURN,
		FLAME_SUN,
		NUM
	};

	enum class UI_TYPE :int
	{
		BG,
		WORD,
		MERCURY,
		VENUS,
		MARS,
		JUPITER,
		SATURN,
		SUN,
		FLAME_MERCURY,
		FLAME_VENUS,
		FLAME_MARS,
		FLAME_JUPITER,
		FLAME_SATURN,
		FLAME_SUN,
		NUM
	};

	//�����ŏ�����
	static const int NUMBER_DIGIT = 5;		//�����̌�

	//cpp�ŏ�����
	static const D3DXVECTOR2 NUMBER_SIZE;
	static const float NUMBER_INIT_POS_X;

	static const D3DXVECTOR2 FLAME_SIZE;
	static const float FLAME_POS_X;

	static const D3DXVECTOR2 PLANET_SIZE;
	static const D3DXVECTOR2 PLANET_SATURN_SIZE;
	static const float PLANET_POS_X;

	static const D3DXVECTOR2 WORD_SIZE;
	static const float WORD_POS_Y;


//�����o�ϐ�
private:
	TextureUseful* m_pTexUseful = nullptr;
	DrawObject* m_pDrawObject = nullptr;

	UI* m_pUI[(int)UI_TYPE::NUM];
	Number* m_pScore[(int)UI_TYPE::SUN - (int)UI_TYPE::MERCURY + 1];
	int m_score[STAGE_NUM];
	bool m_sun_appearance = true;

	int m_SE_02 = 0;	//�L�����Z����

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	TitleScore();

	//�����t���R���X�g���N�^
	TitleScore(int score[]);

	//�X�V����
	void Update(void);

	//�`�揈��
	void Draw(void);
};

#endif // !_TITLE_SCORE_H_