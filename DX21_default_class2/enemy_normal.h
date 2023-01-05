//=======================================
// ���ʂ̓G�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/13
// �쐬�ҁF��������
//=======================================
#pragma once

#ifndef _ENEMY_NORMAL_H_
#define _ENEMY_NORMAL_H_

#include "main.h"
#include "inh_enemy.h"

class EnemyNormal:public Inh_Enemy
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
	static const int BULLET_TIME = 200;	//�e�̔��ˊԊu
	static const int HP_MAX = 2;		//�G��HP�ő�l

	//cpp�ŏ�����
	static const float SPEED_X;			//�G�̃X�s�[�hY
	static const float SPEED_Y;			//�G�̃X�s�[�hY
	static const float ALPHA_SPEED;		//�A���t�@�l�ύX�X�s�[�h

//�����o�ϐ�
private:
//�����o�֐�
public:
	EnemyNormal(){}		//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	EnemyNormal(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}

	~EnemyNormal()override{}	//�f�X�g���N�^

	void Update(void);	//�X�V����

};

#endif // !_ENEMY_NORMAL_H_