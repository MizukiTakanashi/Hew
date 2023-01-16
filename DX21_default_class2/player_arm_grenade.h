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
#include "explosion.h"

class PlayerArmGrenade :public inhPlayerArm
{
//�萔
public:
	//cpp�ŏ�����
	static const D3DXVECTOR2 FINAD_RANGE;	//�T���Ă��鎞�̍U���͈�

private:
	//�����ŏ�����
	static const int BULLET_NUM_MAX = 50;	//�e�̐������@���ۂɌ��Ă鐔�͂�����P���Ȃ�
	static const int BULLET_SHOOT_MAX = 10;	//�e�̓����ő唭�ː�
	static const int BULLET_BREAK_TIME = 200;	//�z�[�~���O�e�����鎞��
	static const int BULLET_INTERVAL = 20;	//�e�̔��ˊԊu
	static const int EXPLOSION_WAIT_TIME = 200;	//�����҂�����
	static const int EXPLOSION_TIME = 100;		//��������

	//cpp�ŏ�����
	static const D3DXVECTOR2 BULLET_SIZE;		//�T�C�Y
	static const float BULLET_SPEED;			//�X�s�[�h
	static const D3DXVECTOR2 EXPLOSION_RANGE;	//�����̃T�C�Y

//�����o�ϐ�
private:
	DrawObject m_bulletdraw;				//�e�̕`��I�u�W�F�N�g
	DrawObject m_explosiondraw;				//�����̕`��I�u�W�F�N�g
	Bullet* m_pBullet[BULLET_SHOOT_MAX];	//�e�̃I�u�W�F�N�g
	Explosion* m_pExplosionDraw[BULLET_SHOOT_MAX];	//�`��p�̔���
	int m_interval_count = 0;				//���ˊԊu�̃J�E���g
	int m_attack_count[BULLET_SHOOT_MAX];	//�����J�n������J�E���g


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	PlayerArmGrenade();

	//�����t���R���X�g���N�^
	PlayerArmGrenade(DrawObject bulletdraw, DrawObject explosiondraw, bool right, int type);

	//�f�X�g���N�^
	~PlayerArmGrenade()override;

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

	//�w�肵���ԍ��̒e�̔�������t���O��Ԃ�
	bool GetIsAttack(int index_num) {
		if (m_attack_count[index_num] == -1) {
			return false;
		}
		return true;
	}

	//�w�肵���ԍ��̒e�̔������邩�t���O���I��
	void SetIsAttack(int index_num);
};

#endif // !_PLAYER_ARM_GRENADE_H_