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
//�����o�ϐ�
private:
	StageSelectMars* m_mars = nullptr;			//�ΐ�
	StageSelectMercury* m_mercury = nullptr;	//����

public:
	//�f�t�H���g�R���X�g���N�^
	StageSelectPlanet(){}

	//�����t���R���X�g���N�^
	StageSelectPlanet(DrawObject& mars, DrawObject& mercury)
		:m_mars(new StageSelectMars(mars)), m_mercury(new StageSelectMercury(mercury)) {}

	//�f�X�g���N�^
	~StageSelectPlanet() {
		delete m_mars;
	}

	//�X�V����
	void Update();

	//�`�揈��
	void Draw()const;
};

#endif // !_STAGE_SELECT_PLANET_H_