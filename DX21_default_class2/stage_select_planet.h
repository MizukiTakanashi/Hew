#pragma once
//=============================================
// �X�e�[�W�I����ʂ̘f���֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/29
// �쐬�ҁF��������
//=============================================

#ifndef _STAGE_SELECT_PLANET_H_
#define _STAGE_SELECT_PLANET_H_

#include "game_object.h"
#include "draw_object.h"
#include "stage_select_planet_make.h"

//==========================
// �f���S��
//==========================
class StageSelectPlanet
{
//�萔
private:
	//�f��(���������)(SUN�͍Ō�)
	enum class PLANET :int
	{
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
	inhStageSelectPlanetMake* m_planets[(int)PLANET::NUM];	//�f���B

	bool m_sun_appearance = false;							//���z���o�Ă邩�ǂ���

	int m_planet_index = 0;									//�f���̌��݂̃C���f�b�N�X�ԍ�
	int m_planet_index_before = 0;							//�f���̑O�̃C���f�b�N�X�ԍ�

	int m_thumb_before = 0;									//�O�t���[���̃X�e�B�b�N�̒l

public:
	//�f�t�H���g�R���X�g���N�^
	StageSelectPlanet(){
		for (int i = 0; i < (int)PLANET::NUM; i++) {
			m_planets[i] = nullptr;
		}
	}

	//�����t���R���X�g���N�^
	StageSelectPlanet(DrawObject& mars, DrawObject& mercury, DrawObject& jupiter,
		DrawObject& venus, DrawObject& saturn, DrawObject& sun, bool sun_appearance = false);

	//�f�X�g���N�^
	~StageSelectPlanet() {
		for (int i = 0; i < (int)PLANET::NUM; i++) {
			delete m_planets[i];
		}
	}

	//�X�V����
	void Update();

	//�`�揈��
	void Draw()const;
};

#endif // !_STAGE_SELECT_PLANET_H_