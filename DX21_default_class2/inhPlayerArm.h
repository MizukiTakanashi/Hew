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
private:
	int m_BulletNum = 0;	//�e�̐�


public:
	//�f�t�H���g�R���X�g���N�^
	inhPlayerArm(){}

	//�f�X�g���N�^
	~inhPlayerArm(){}

	//�X�V����(�I�[�o�[���C�h)
	virtual void Update() = 0;

	//�`�揈��(�I�[�o�[���C�h)
	virtual void PlayerArmDraw(void)const = 0;

	//�w�肵���ԍ��̃I�u�W�F�N�g������
	virtual void DeleteBullet(int index_num) = 0;

	//���݂̒e���𑝂₷
	void IncreaseBulletNum(int num = 1) { m_BulletNum += num; }

	//�e�̐����擾
	int GetBulletNum(void)const { return m_BulletNum;}

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetBulletPos(int index_num)const = 0;

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h�p)
	virtual const D3DXVECTOR2& GetBulletSize(int index_num = 0)const = 0;
};

#endif // !_INH_PLAYER_ARM_H_