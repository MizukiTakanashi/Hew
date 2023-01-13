#pragma once
//=========================================================
// �v���C���[�̘r�̃A�C�e��(�o���A)�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/12/19
// �쐬�ҁF��������
//========================================================

#ifndef _PLAYER_ARM_BARRIER_H_
#define _PLAYER_ARM_BARRIER_H_

#include "inh_player_arm.h"
#include "draw_object.h"
#include "bullet.h"

class PlayerArmBarrier :public inhPlayerArm
{
//�萔
private:
	//�����ŏ�����
	static const int BULLET_NUM_MAX = 5;	//�e�̐������@���ۂɌ��Ă鐔�͂�����P���Ȃ�
	static const int BULLET_SHOOT_MAX = 1;	//�e�̓����ő唭�ː�
	static const int BARRIER_HP_MAX = 5;	//�o���A�̍ő�HP

	//cpp�ŏ�����
	static const float BULLET_SIZE_X;		//�T�C�YX
	static const float BULLET_SIZE_Y;		//�T�C�YY
	static const D3DXVECTOR2 RIGHT_BARRIER_INTERVAL_POS;	//�o���A�ƉE�r�̊Ԋu
	static const D3DXVECTOR2 LEFT_BARRIER_INTERVAL_POS;		//�o���A�ƍ��r�̊Ԋu
	static const D3DXVECTOR2 CENTER_BARRIER_INTERVAL_POS;	//�o���A�ƒ����̊Ԋu


//�����o�ϐ�
private:
	DrawObject m_bulletdraw;			//�e�̕`��I�u�W�F�N�g
	Bullet* m_pBullet = nullptr;		//�e�̃I�u�W�F�N�g


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	PlayerArmBarrier() { m_pBullet = new Bullet; }

	//�����t���R���X�g���N�^
	PlayerArmBarrier(DrawObject bulletdraw, bool right, int type)
		:inhPlayerArm(BULLET_NUM_MAX, right, type, BARRIER_HP_MAX), m_bulletdraw(bulletdraw) {
		m_pBullet = new Bullet[BULLET_SHOOT_MAX];
	}

	//�f�X�g���N�^
	~PlayerArmBarrier()override { 
		if (m_pBullet != nullptr) {
			delete m_pBullet;
		}
	}

	//�X�V����(�I�[�o�[���C�h)
	void Update(const D3DXVECTOR2& arm_pos)override;

	//�`�揈��(�I�[�o�[���C�h)
	void PlayerArmDraw()const override;

	//�w�肵���ԍ��̒e������(�I�[�o�[���C�h)
	void DeleteBullet(int index_num)override;

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override
	{
		return m_pBullet->GetPos();
	}

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override
	{
		return m_pBullet->GetSize();
	}
};

#endif // !_PLAYER_ARM_BARRIER_H_