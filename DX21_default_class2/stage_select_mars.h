#pragma once
//=============================================
// �X�e�[�W�I����ʂ̉ΐ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/29
// �쐬�ҁF��������
//=============================================

#ifndef _STAGE_SELECT_MARS_H_
#define _STAGE_SELECT_MARS_H_

#include "game_object.h"
#include "draw_object.h"

class StageSelectMars:public GameObject
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
	StageSelectMars(){}

	//�����t���R���X�g���N�^
	StageSelectMars(DrawObject& pDrawObj):GameObject(pDrawObj, D3DXVECTOR2(START_POS_X, START_POS_Y), D3DXVECTOR2(BOX_W, BOX_H)) {}

	//�f�X�g���N�^
	~StageSelectMars() {}
};

#endif // !_STAGE_SELECT_MARS_H_