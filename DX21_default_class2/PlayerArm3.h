#pragma once
//=======================================
// �v���C���[�̘r1�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/10/28
// �쐬�ҁF��������
//=======================================

#ifndef _PLAYER_ARM_3_H_
#define _PLAYER_ARM_3_H_

#include "inhPlayerArm.h"
#include "DrawObject.h"
#include "bullet.h"

class PlayerArm3 :public inhPlayerArm
{
//�萔
private:
	//�����ŏ�����
	static const int BULLET_NUM_MAX = 100;		//�e�̐�����
	static const int BULLET_SHOOT_MAX = 20;		//�e�̓����ő唭�ː�
	static const int BULLET_INTERVAL = 10;		//�e�̔��ˊԊu
	
	//cpp�ŏ�����
	static const float BULLET_SIZE_X;		//�T�C�YX
	static const float BULLET_SIZE_Y;		//�T�C�YY
	static const float BULLET_SPEED;		//�X�s�[�h

//�����o�ϐ�
private:
	DrawObject m_bulletdraw;			//�e�̕`��I�u�W�F�N�g
	Bullet* m_pBullet = nullptr;		//�e�̃I�u�W�F�N�g
	int m_bullet_interval_count = 0;	//���ˊԊu�J�E���g

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	PlayerArm3() { m_pBullet = new Bullet[BULLET_SHOOT_MAX]; }

	//�����t���R���X�g���N�^
	PlayerArm3(DrawObject bulletdraw, bool right) 
		:inhPlayerArm(BULLET_NUM_MAX, right), m_bulletdraw(bulletdraw) { m_pBullet = new Bullet[BULLET_SHOOT_MAX]; }

	//�f�X�g���N�^
	~PlayerArm3() { delete[] m_pBullet; }

	//�X�V����(�I�[�o�[���C�h)
	void Update(const D3DXVECTOR2& arm_pos)override;

	//�`�揈��(�I�[�o�[���C�h)
	void PlayerArmDraw()const override;

	//�w�肵���ԍ��̒e������(�I�[�o�[���C�h)
	void DeleteBullet(int index_num)override;

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override
		{ return m_pBullet[index_num].GetPos();	}

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override
		{ return m_pBullet[index_num].GetSize(); }
};

#endif // !_PLAYER_ARM_1_H_