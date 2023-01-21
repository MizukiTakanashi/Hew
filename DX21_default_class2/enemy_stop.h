//=======================================
// �������~�߂�G�֌W(�w�b�_�t�@�C��)
// �쐬���F
// �쐬�ҁF���c�m�s
//=======================================
#pragma once

#ifndef _ENEMY_STOP_H_
#define _ENEMY_STOP_H_

#include "main.h"
#include "inh_enemy.h"

class EnemyStop :public Inh_Enemy
{
//�萔
public:
	//cpp�ŏ�����
	static const float SIZE_X;			//�T�C�YX
	static const float SIZE_Y;			//�T�C�YY
	static const float STOP_POS_Y;		//�G���~�܂�ꏊ
	static const float RANGE;			//�G�������͈�

private:
	//�����ŏ�����
	static const int BULLET_TIME = 240;	//�e�̔��ˊԊu
	static const int INVINCIBLE_FLAME = 30;	//�G�̖��G����

	//cpp�ŏ�����
	static const float SPEED_X;			//�G�̃X�s�[�hY
	static const float SPEED_Y;			//�G�̃X�s�[�hY
	static const int HP_MAX = 3;		//�G��HP�ő�l

//�����o�ϐ�
private:


//�����o�֐�
public:
	EnemyStop() {}		//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	EnemyStop(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}

	EnemyStop(DrawObject& pDrawObject, const D3DXVECTOR2& pos, D3DXVECTOR2 size)
		:Inh_Enemy(pDrawObject, pos, size, HP_MAX) {}

	~EnemyStop()override {}	//�f�X�g���N�^

	void Update(void);	//�X�V����
};

#endif // !_ENEMY_STOP_H_