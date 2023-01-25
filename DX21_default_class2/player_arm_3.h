#pragma once
//======================================================
// �v���C���[�̘r�A�K�g�����O�E���֌W(�w�b�_�t�@�C��)
// �쐬���F2022/10/28
// �쐬�ҁF��������
//======================================================

#ifndef _PLAYER_ARM_3_H_
#define _PLAYER_ARM_3_H_

#include "inh_player_arm.h"
#include "draw_object.h"
#include "bullet.h"

class PlayerArm3 :public inhPlayerArm
{
//�萔
public:
	enum class TYPE :int
	{
		GATORING,
		FIRE,
		ACID,
		FIREBALL,
		NUM
	};

private:
	//�����ŏ�����
	static const int BULLET_NUM_MAX = 50;		//�e�̐������@���ۂɌ��Ă鐔�͂�����P���Ȃ�
	static const int BULLET_SHOOT_MAX = 20;		//�e�̓����ő唭�ː�
	static const int BULLET_INTERVAL = 10;		//�e�̔��ˊԊu
	static const int ACID_INTERVAL = 120;		//�e�̔��ˊԊu
	static const int FIREBALL_INTERVAL = 60;		//�e�̔��ˊԊu
	
	//cpp�ŏ�����
	static const float BULLET_SIZE_X;		//�T�C�YX
	static const float BULLET_SIZE_Y;		//�T�C�YY
	static const float BULLET_SPEED;		//�X�s�[�h
	static const float FIRE_SPEED;			//���̃X�s�[�h
	static const float ACID_SPEED;			//���̃X�s�[�h
	static const float FIREBALL_SPEED;			//���̃X�s�[�h

//�����o�ϐ�
private:
	DrawObject m_bulletdraw;			//�e�̕`��I�u�W�F�N�g
	Bullet* m_pBullet = nullptr;		//�e�̃I�u�W�F�N�g
	TYPE m_type = TYPE::GATORING;		//�e�̃^�C�v

	int m_interval = BULLET_INTERVAL;

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	PlayerArm3() { m_pBullet = new Bullet[BULLET_SHOOT_MAX]; }

	//�����t���R���X�g���N�^
	PlayerArm3(DrawObject bulletdraw, bool right, int type, TYPE _type = TYPE::GATORING)
		:inhPlayerArm(BULLET_NUM_MAX, right, type), m_bulletdraw(bulletdraw), m_type(_type) 
	{

		m_pBullet = new Bullet[BULLET_SHOOT_MAX]; 
		if (m_type == TYPE::ACID)
		{
			m_interval = ACID_INTERVAL;
		}
		else if (m_type == TYPE::FIREBALL)
		{
			m_interval = FIREBALL_INTERVAL;
		}
	}

	//�f�X�g���N�^
	~PlayerArm3()override { delete[] m_pBullet; }

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