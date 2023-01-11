//=======================================
// �v���C���[�̘r�A�X�̒e�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/1/1
// �쐬�ҁF����đ�
//=======================================
#pragma once

#include "inh_player_arm.h"
#include "draw_object.h"
#include "bullet.h"

class PlayerArmIceRain :public inhPlayerArm
{
	//�萔
private:
	//�����ŏ�����
	static const int BULLET_NUM_MAX = 50;		//�e�̐������@���ۂɌ��Ă鐔�͂�����P���Ȃ�
	static const int BULLET_SHOOT_MAX = 100;		//�e�̓����ő唭�ː�
	static const int BULLET_INTERVAL = 10;		//�e�̔��ˊԊu
	static const int BULLET_INTERVAL1 = 11;		//�e�̔��ˊԊu
	static const int BULLET_INTERVAL2 = 12;		//�e�̔��ˊԊu
	static const int BULLET_INTERVAL3 = 13;		//�e�̔��ˊԊu
	static const int BULLET_INTERVAL4 = 14;		//�e�̔��ˊԊu

	//cpp�ŏ�����
	static const float BULLET_SIZE_X;		//�T�C�YX
	static const float BULLET_SIZE_Y;		//�T�C�YY
	static const float BULLET_SPEED;		//�X�s�[�h

	//�����o�ϐ�
private:
	DrawObject m_bulletdraw;			//�e�̕`��I�u�W�F�N�g
	Bullet* m_pBullet = nullptr;		//�e�̃I�u�W�F�N�g
	int m_bullet_interval_count = 0;	//���ˊԊu�J�E���g
	int m_bullet_interval_count1 = 0;	//���ˊԊu�J�E���g
	int m_bullet_interval_count2 = 0;	//���ˊԊu�J�E���g
	int m_bullet_interval_count3 = 0;	//���ˊԊu�J�E���g
	int m_bullet_interval_count4 = 0;	//���ˊԊu�J�E���g

	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	PlayerArmIceRain() { m_pBullet = new Bullet[BULLET_SHOOT_MAX]; }

	//�����t���R���X�g���N�^
	PlayerArmIceRain(DrawObject bulletdraw, bool right, int type)
		:inhPlayerArm(BULLET_NUM_MAX, right, type), m_bulletdraw(bulletdraw) {
		m_pBullet = new Bullet[BULLET_SHOOT_MAX];
	}

	//�f�X�g���N�^
	~PlayerArmIceRain()override { delete[] m_pBullet; }

	//�X�V����(�I�[�o�[���C�h)
	void Update(const D3DXVECTOR2& arm_pos)override;

	//�`�揈��(�I�[�o�[���C�h)
	void PlayerArmDraw()const override;

	//�w�肵���ԍ��̒e������(�I�[�o�[���C�h)
	void DeleteBullet(int index_num)override;

	//�w�肵���ԍ��̒e�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override
	{
		return m_pBullet[index_num].GetPos();
	}

	//�w�肵���ԍ��̒e�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override
	{
		return m_pBullet[index_num].GetSize();
	}
};