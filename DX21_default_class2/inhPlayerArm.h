#pragma once
//==============================================
// (�p���p)�v���C���[�̘r�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/10/28
// �쐬�ҁF��������
//==============================================

#ifndef _INH_PLAYER_ARM_H_
#define _INH_PLAYER_ARM_H_

#include "GameObject.h"

class inhPlayerArm:public GameObject
{
public:
	//�f�t�H���g�R���X�g���N�^
	inhPlayerArm(){}

	//�f�X�g���N�^
	~inhPlayerArm(){}

	//�X�V����(�I�[�o�[���C�h)
	virtual void Update() = 0;

	//�`�揈��(�I�[�o�[���C�h)
	virtual void Draw() = 0;
};

#endif // !_INH_PLAYER_ARM_H_