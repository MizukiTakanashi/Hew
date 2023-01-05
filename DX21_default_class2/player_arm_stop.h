#pragma once
//=========================================================
// �v���C���[�̘r�̃A�C�e��(STOP)�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//========================================================

#ifndef _PLAYER_ARM_STOP_H_
#define _PLAYER_ARM_STOP_H_

#include "inh_player_arm.h"
#include "draw_object.h"
#include "bullet_stop.h"

class PlayerArmStop :public inhPlayerArm
{
//�萔
private:
	//�����ŏ�����
	static const int BULLET_NUM_MAX = 5;	//�e�̐������@���ۂɌ��Ă鐔�͂�����P���Ȃ�
	static const int BULLET_SHOOT_MAX = 1;	//�e�̓����ő唭�ː�
	static const int BULLET_INTERVAL = 120;		//�e�̔��ˊԊu
	static const int BULLET_TIME = 120;

	//cpp�ŏ�����
	static const float BULLET_SIZE_X;		//�T�C�YX
	static const float BULLET_SIZE_Y;		//�T�C�YY


//�����o�ϐ�
private:
	DrawObject m_bulletdraw;			//�e�̕`��I�u�W�F�N�g
	BulletStop* m_pBullet = nullptr;	//�e�̃I�u�W�F�N�g
	int m_SE_11 = 0;					//��C���o����


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	PlayerArmStop() { m_pBullet = new BulletStop[BULLET_SHOOT_MAX]; }

	//�����t���R���X�g���N�^
	PlayerArmStop(DrawObject bulletdraw, bool right, int type);

	//�f�X�g���N�^
	~PlayerArmStop()override { delete[] m_pBullet; }

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

#endif // !_PLAYER_ARM_STOP_H_