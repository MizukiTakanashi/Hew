#pragma once
//=================================================
// �v���C���[�̘r�̃O���l�[�h�֌W(�w�b�_�t�@�C��)
// �쐬���F2023/01/13
// �쐬�ҁF��������
//=================================================

#ifndef _PLAYER_ARM_GRENADE_H_
#define _PLAYER_ARM_GRENADE_H_

#include "inh_player_arm.h"
#include "draw_object.h"
#include "bullet.h"

class PlayerArmGrenad :public inhPlayerArm
{
//�萔
public:
	//cpp�ŏ�����
	static const D3DXVECTOR2 FINAD_RANGE;	//�T���Ă��鎞�̍U���͈�

private:
	//�����ŏ�����
	static const int BULLET_NUM_MAX = 50;	//�e�̐������@���ۂɌ��Ă鐔�͂�����P���Ȃ�
	static const int BULLET_SHOOT_MAX = 10;	//�e�̓����ő唭�ː�

	//cpp�ŏ�����
	static const D3DXVECTOR2 BULLET_SIZE;	//�T�C�Y

//�����o�ϐ�
private:
	DrawObject m_bulletdraw;				//�e�̕`��I�u�W�F�N�g
	Bullet* m_pBullet[BULLET_SHOOT_MAX];	//�e�̃I�u�W�F�N�g


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	PlayerArmGrenad() {
		for (int i = 0; i < BULLET_SHOOT_MAX; i++) {
			m_pBullet[i] = nullptr;
		}	
	}

	//�����t���R���X�g���N�^
	PlayerArmGrenad(DrawObject bulletdraw, bool right, int type)
		:inhPlayerArm(BULLET_NUM_MAX, right, type), m_bulletdraw(bulletdraw) {
		for (int i = 0; i < BULLET_SHOOT_MAX; i++) {
			m_pBullet[i] = nullptr;
		}
	}

	//�f�X�g���N�^
	~PlayerArmGrenad()override {
		for (int i = 0; i < BULLET_SHOOT_MAX; i++) {
			if (m_pBullet[i] != nullptr) {
				delete m_pBullet[i];
			}
		}
	}

	//�X�V����(�I�[�o�[���C�h)
	void Update(const D3DXVECTOR2& arm_pos)override;

	//�`�揈��(�I�[�o�[���C�h)
	void PlayerArmDraw()const override;

	//�w�肵���ԍ��̒e������(�I�[�o�[���C�h)
	void DeleteBullet(int index_num)override;

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override{
		return m_pBullet[index_num]->GetPos();
	}

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override{
		return m_pBullet[index_num]->GetSize();
	}
};

#endif // !_PLAYER_ARM_GRENADE_H_