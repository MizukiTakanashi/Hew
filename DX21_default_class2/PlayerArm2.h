#pragma once
//=======================================
// �v���C���[�̘r2�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/01
// �쐬�ҁF����đ�
//=======================================

#ifndef _PLAYER_ARM_2_H_
#define _PLAYER_ARM_2_H_

#include "inhPlayerArm.h"
#include "DrawObject.h"
#include "laser.h"
#include "player.h"

class PlayerArm2 :public inhPlayerArm
{
	//�萔
private:
	//�����ŏ�����
	static const int BULLET_NUM_MAX = 10;		//�e�̍ő吔
	static const int BULLET_INTERVAL = 200;		//�e�̔��ˊԊu
	static const int BULLET_BREAK_TIME = 200;	//�z�[�~���O�e�����鎞��

	static const int LASER_TIME = 150;			//���[�U�[�̎ˏo����

	//cpp�ŏ�����
	static const float BULLET_SIZE_X;		//�T�C�YX
	static const float BULLET_SIZE_Y;		//�T�C�YY
	static const float BULLET_SPEED;		//�X�s�[�h

	static const float SPEED_Y;			//���[�U�[�̃X�s�[�hY

//�����o�ϐ�
private:
	DrawObject m_laser_draw;			//�e�̕`��I�u�W�F�N�g
	Laser* m_pLaser = nullptr;			//�e�̃I�u�W�F�N�g
	int m_bullet_interval_count = 0;	//���ˊԊu�J�E���g
	int m_lasertime = LASER_TIME;		//���[�U�[�̎ˏo����

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	PlayerArm2() { m_pLaser = new Laser[BULLET_NUM_MAX]; }

	//�����t���R���X�g���N�^
	PlayerArm2(DrawObject bulletdraw) 
		:inhPlayerArm(), m_laser_draw(bulletdraw) { m_pLaser = new Laser[BULLET_NUM_MAX]; }

	//�f�X�g���N�^
	~PlayerArm2() { delete[] m_pLaser; }

	//�X�V����(�I�[�o�[���C�h)
	void Update(const D3DXVECTOR2& arm_pos)override;

	//�`�揈��(�I�[�o�[���C�h)
	void PlayerArmDraw()const override;

	void SetArmPos(const D3DXVECTOR2&){}
};

#endif // !_PLAYER_ARM_1_H_