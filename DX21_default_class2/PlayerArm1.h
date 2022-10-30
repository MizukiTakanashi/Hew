#pragma once
//=======================================
// �v���C���[�̘r1�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/10/28
// �쐬�ҁF��������
//=======================================

#ifndef _PLAYER_ARM_1_H_
#define _PLAYER_ARM_1_H_

#include "inhPlayerArm.h"
#include "DrawObject.h"
#include "bullet.h"

class PlayerArm1:public inhPlayerArm
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

//�����o�ϐ�
private:
	DrawObject m_bulletdraw;			//�e�̕`��I�u�W�F�N�g
	Bullet* m_pBullet = nullptr;		//�e�̃I�u�W�F�N�g
	int m_bullet_num = 0;				//���݂̒e�̐�
	int m_bullet_interval_count = 0;	//���ˊԊu�J�E���g
	D3DXVECTOR2 m_enemy_pos = D3DXVECTOR2(0.0f, 0.0f);	//��ԋ߂��G�̈ʒu

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	PlayerArm1(){ m_pBullet = new Bullet[BULLET_NUM_MAX]; }

	//�����t���R���X�g���N�^
	PlayerArm1(DrawObject bulletdraw):m_bulletdraw(bulletdraw){ m_pBullet = new Bullet[BULLET_NUM_MAX]; }

	//�f�X�g���N�^
	~PlayerArm1() { delete[] m_pBullet; }

	//�X�V����(�I�[�o�[���C�h)
	void Update()override;

	//�`�揈��(�I�[�o�[���C�h)
	void PlayerArmDraw()override;

	//��ԋ߂��G�̈ʒu���Z�b�g
	void SetEnemyPos(const D3DXVECTOR2& enemy_pos) { m_enemy_pos = enemy_pos; }
};

#endif // !_PLAYER_ARM_1_H_