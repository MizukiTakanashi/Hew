#pragma once
//=======================================
// �v���C���[�̘r1�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/10/28
// �쐬�ҁF��������
//=======================================

#ifndef _PLAYER_ARM_1_H_
#define _PLAYER_ARM_1_H_

#include "inhPlayerArm.h"

class PlayerArm1:public inhPlayerArm
{
public:
	//�f�t�H���g�R���X�g���N�^
	PlayerArm1(){}

	//�f�X�g���N�^
	~PlayerArm1(){}

	void Update()override;

	void PlayerArmDraw()override;
};

#endif // !_PLAYER_ARM_1_H_