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

	static const float RANGE;					//�G�������͈�

	static const D3DXVECTOR2 BARRIER_SIZE;		//�o���A�̃T�C�Y

private:
	//�����ŏ�����
	static const int INVINCIBLE_FLAME = 30;		//�G�̖��G����
	static const int HP_MAX = 1;				//�G��HP�ő�l
	static const int BARRIER_TIME_LIMIT = 200;	//�o���A�̎���
	static const int BARRIER_INTERVAL = -2;		//�o���A�̏o���Ԋu

	//cpp�ŏ�����
	static const float SPEED_X;					//�G�̃X�s�[�hY
	static const float SPEED_Y;					//�G�̃X�s�[�hY

	static const D3DXVECTOR2 INTERVAL_POS;		//�G�ƃo���A�̊Ԋu


//�����o�ϐ�
private:
	GameObject* m_pBarrier = nullptr;	//�o���A

	float m_move_width = 0.0f;			//�G����������cos�J�[�u
	float m_init_posx = 0.0f;			//�G�̏����ʒuX

	int m_hp = HP_MAX;					//�G�̌��݂�HP
	int m_invincible_flame = 0;			//���G���Ԃ̎c��

	int m_barrier_time = 0;				//�o���A�����鎞�Ԃ̃J�E���g
	int m_barrier_interval_time = -1;	//���̃o���A����������鎞�Ԃ̃J�E���g

	int m_barrier_index = 0;			//�o���A�Ǘ��̕��ō��A�o���A�̃C���f�b�N�X�ԍ����L�^


//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyBarrier() {}		

	//�����t���R���X�g���N�^
	EnemyBarrier(DrawObject& pDrawObject, DrawObject& pDrawObject2, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)),
		m_pBarrier(new GameObject(pDrawObject2, pos + INTERVAL_POS, BARRIER_SIZE)),
		m_init_posx(pos.x) {}

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
	
	//�o���A�̕`��
	void DrawBarrier(void)const;

	//�o���A�̍��W��Ԃ�
	const D3DXVECTOR2& GetBarrierPos(void)const { return m_pBarrier->GetPos(); }

	//�o���A������
	void DeleteBarrier(void) { m_barrier_interval_time = 0; m_barrier_time = -1; }

	//�o���A���������
	//bool IsBarrierMake(void) { return m_barrier_time == 0; }

	//�o���A���󂵂���
	//bool IsBarrierBreak(void) { return m_barrier_interval_time == 0; }
};

#endif // !_ENEMY_BARRIER_H_