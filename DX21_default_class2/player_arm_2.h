#pragma once
//=======================================
// �v���C���[�̘r2�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/01
// �쐬�ҁF����đ�
//=======================================

#ifndef _PLAYER_ARM_2_H_
#define _PLAYER_ARM_2_H_

#include "inh_player_arm.h"
#include "draw_object.h"
#include "laser.h"
#include "player.h"

class PlayerArm2 :public inhPlayerArm
{
	//�萔
private:
	//�����ŏ�����
	static const int BULLET_NUM_MAX = 5;		//�e�̐������@���ۂɌ��Ă鐔�͂�����P���Ȃ�
	static const int BULLET_SHOOT_MAX = 5;		//�e�̓����ő唭�ː�
	static const int BULLET_INTERVAL = 20;		//�e�̔��ˊԊu

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
	PlayerArm2() { m_pLaser = new Laser[BULLET_SHOOT_MAX]; }

	//�����t���R���X�g���N�^
	PlayerArm2(DrawObject& bulletdraw, bool right, int type) 
		:inhPlayerArm(BULLET_NUM_MAX, right, type), m_laser_draw(bulletdraw) { m_pLaser = new Laser[BULLET_SHOOT_MAX]; }

	//�f�X�g���N�^
	~PlayerArm2()override { delete[] m_pLaser; }

	//�X�V����(�I�[�o�[���C�h)
	void Update(const D3DXVECTOR2& arm_pos)override;

	//�`�揈��(�I�[�o�[���C�h)
	void PlayerArmDraw()const override;

	//�w�肵���ԍ��̒e������(�I�[�o�[���C�h)
	void DeleteBullet(int index_num)override;

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h�p)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override
		{ return m_pLaser[index_num].GetPos(); }

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h�p)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override
		{ return m_pLaser[index_num].GetSize();	}
};

#endif // !_PLAYER_ARM_1_H_