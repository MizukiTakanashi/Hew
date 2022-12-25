#pragma once
//=======================================
// �o���A�̓G�֌W(�w�b�_�t�@�C��)
// �쐬���F2022/12/08
// �쐬�ҁF��������
//=======================================

#ifndef _ENEMY_BARRIER_H_
#define _ENEMY_BARRIER_H_

#include "game_object.h"

class EnemyBarrier:public GameObject
{
//�萔
public:
	//cpp�ŏ�����
	static const float SIZE_X;					//�T�C�YX
	static const float SIZE_Y;					//�T�C�YY

	static const float STOP_POS_Y;				//�G���~�܂�ꏊ

private:
	//�����ŏ�����
	static const int INVINCIBLE_FLAME = 30;		//�G�̖��G����
	static const int HP_MAX = 1;				//�G��HP�ő�l

	//cpp�ŏ�����
	static const float SPEED_Y;					//�G�̃X�s�[�hY


//�����o�ϐ�
private:
	int m_barrier_index = -1;			//�o���A�̃C���f�b�N�X�ԍ�

	int m_hp = HP_MAX;					//�G�̌��݂�HP
	int m_invincible_flame = 0;			//���G���Ԃ̎c��


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyBarrier() {}		

	//�����t���R���X�g���N�^
	EnemyBarrier(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)){}

	~EnemyBarrier()override {}	//�f�X�g���N�^

	void Update(void);	//�X�V����

	//HP�����炷
	void ReduceHP(int amount)
	{
		if (m_invincible_flame <= 0)
		{
			m_hp -= amount;
			m_invincible_flame = INVINCIBLE_FLAME;
		}
	}

	//HP��Ԃ�
	int GetHP(void) { return m_hp; }

	//���[�U�[�ԍ����Z�b�g
	void SetBarrierIndex(int num) { m_barrier_index = num; }

	//���[�U�[�ԍ���Ԃ�
	int GetBarrierIndex() const { return m_barrier_index; }
};

#endif // !_ENEMY_BARRIER_H_