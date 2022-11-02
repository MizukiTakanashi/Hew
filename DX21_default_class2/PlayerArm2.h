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
#include "bullet.h"
#include "player.h"

class PlayerArm2 :public inhPlayerArm
{
	//�萔
private:
	//�����ŏ�����
	static const int BULLET_NUM_MAX = 10;		//�e�̍ő吔
	static const int BULLET_INTERVAL = 200;		//�e�̔��ˊԊu
	static const int BULLET_BREAK_TIME = 200;	//�z�[�~���O�e�����鎞��

	//cpp�ŏ�����
	static const float BULLET_SIZE_X;		//�T�C�YX
	static const float BULLET_SIZE_Y;		//�T�C�YY
	static const float BULLET_SPEED;		//�X�s�[�h
	int m_lasertime = LASER_TIME;

public:
	static const float SPEED_Y;			//���[�U�[�̃X�s�[�hY
	static const int LASER_TIME;			//���[�U�[�̎ˏo����
	//�����o�ϐ�
private:
	DrawObject m_bulletdraw;			//�e�̕`��I�u�W�F�N�g
	Bullet* m_pBullet = nullptr;		//�e�̃I�u�W�F�N�g
	int m_bullet_num = 0;				//���݂̒e�̐�
	int m_bullet_interval_count = 0;	//���ˊԊu�J�E���g
	Player* m_pPlayer = nullptr;	//�v���C���[�ʒu�m�F�p
	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	PlayerArm2() { m_pBullet = new Bullet[BULLET_NUM_MAX]; }

	//�����t���R���X�g���N�^
	PlayerArm2(DrawObject bulletdraw) :m_bulletdraw(bulletdraw) { m_pBullet = new Bullet[BULLET_NUM_MAX]; }

	//�f�X�g���N�^
	~PlayerArm2() { delete[] m_pBullet; }

	//�X�V����(�I�[�o�[���C�h)
	void Update()override;

	//�`�揈��(�I�[�o�[���C�h)
	void PlayerArmDraw()const override;
};

#endif // !_PLAYER_ARM_1_H_