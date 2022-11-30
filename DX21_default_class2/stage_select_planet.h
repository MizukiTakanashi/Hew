#pragma once
//=============================================
// �X�e�[�W�I����ʂ̘f���֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/29
// �쐬�ҁF��������
//=============================================

#ifndef _STAGE_SELECT_PLANET_H_
#define _STAGE_SELECT_PLANET_H_

#include "game_object.h"
#include "stage_select_mars.h"
#include "draw_object.h"

//==========================
// ����
//==========================
class StageSelectMercury:public GameObject
{
//�萔
private:
	//cpp�ŏ�����
	static const float BOX_W;		//�l�p�`�̉��̃T�C�Y
	static const float BOX_H;		//�l�p�`�̏c�̃T�C�Y
	static const float START_POS_X;	//�����ʒuX
	static const float START_POS_Y;	//�����ʒuY


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	StageSelectMercury() {}

	//�����t���R���X�g���N�^
	StageSelectMercury(DrawObject& pDrawObj) :GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//�f�X�g���N�^
	~StageSelectMercury() {}
};

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