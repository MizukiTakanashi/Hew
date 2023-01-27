#pragma once
//=======================================
// �o���A�̓G�̊֌W(�w�b�_�t�@�C��)
// �쐬���F2022/12/08
// �쐬�ҁF��������
//=======================================

#ifndef _MANAGEMENT_ENEMY_BARRIER_H_
#define _MANAGEMENT_ENEMY_BARRIER_H_

#include "management_enemy.h"
#include "enemy_barrier.h"

class EnemyBarrierManagement:public EnemyManagement
{
//�萔
public:
	//�����ŏ�����
	static const int ATTACK = 5;			//�G���g�̍U���l
	static const int BARRIER_ATTACK = 0;	//�o���A�̍U���l
	static const int BARRIER_HP_MAX = 5;	//�G�̃o���A��HP�ő�l

private:
	//�����ŏ�����
	static const int ENEMY_NUM[(int)STAGE::NUM];	//�G���o�������鐔

	//cpp�ŏ�����
	static const D3DXVECTOR2 BARRIER_SIZE;	//�o���A�̑傫��
	static const D3DXVECTOR2 INTERVAL_POS;	//�G�ƃo���A�̊Ԋu

//�����o�ϐ�
private:
	EnemyBarrier* m_pEnemy = nullptr;	//�G�̃N���X
	GameObject* m_pBarrier = nullptr;	//�o���A
	int m_BarrierHP[9];			//�o���A��HP
	DrawObject m_pDrawObjectEnemy;		//�G�̕`��I�u�W�F�N�g
	DrawObject m_pDrawObjectBarrier;	//�o���A�̕`��I�u�W�F�N�g

	int m_stage_num = 0;				//�X�e�[�W

	//�G�̈ʒu�z��
	D3DXVECTOR2 m_SetEnemy[(int)STAGE::NUM][15] = {
		//�`���[�g���A��
		{
			D3DXVECTOR2(52.5f + (105 * 1), -EnemyBarrier::SIZE_Y / 2),
		},
		//�ΐ�
		{
			// 5
			D3DXVECTOR2(52.5f + (105 * 2), -EnemyBarrier::SIZE_Y / 2),
			// 40
			D3DXVECTOR2(52.5f + (105 * 0), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 2), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 4), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 6), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 8), -EnemyBarrier::SIZE_Y / 2),
			// 60
			D3DXVECTOR2(52.5f + (105 * 2), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 8), -EnemyBarrier::SIZE_Y / 2),
			// 160
			D3DXVECTOR2(52.5f + (105 * 1), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 2), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 3), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 5), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 7), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 8), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 9), -EnemyBarrier::SIZE_Y / 2)
		},
		//����
		{
			D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyBarrier::SIZE_Y / 2),
		},
		//�y��
		{
			D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyBarrier::SIZE_Y / 2),

		},
		//����
		{
			D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyBarrier::SIZE_Y / 2),
		},
		//�ؐ�
		{
			D3DXVECTOR2(71.0f + (142.0f * 1), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 7), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 3), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 5), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 8), -EnemyBarrier::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyBarrier::SIZE_Y / 2)
		}
	};

	//�G���o������
	int m_SetEnemyTime[(int)STAGE::NUM][15] = {
		//�`���[�g���A��
		{
			60 * 40,
		},
		//�ΐ�
		{
			60 * 5,
			60 * 40,
			60 * 40 + 1,
			60 * 40 + 2,
			60 * 40 + 3,
			60 * 40 + 4,
			60 * 60,
			60 * 60 + 1,
			60 * 160,
			60 * 160 + 1,
			60 * 160 + 2,
			60 * 160 + 3,
			60 * 160 + 4,
			60 * 160 + 5,
			60 * 160 + 6
		},
		//����
		{
			60 * 140,
		},
		//�y��
		{
			60 * 10,
		},
		//����
		{
			60 * 100,
		},
		//�ؐ�
		{
			60 * 20,
			60 * 20 + 1,
			60 * 35,
			60 * 35 + 1,
			60 * 100,
			60 * 100 + 1,
			60 * 105,
			60 * 105 + 1,
			60 * 145,
		}
	};

	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyBarrierManagement() {}

	//�����t���R���X�g���N�^
	EnemyBarrierManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage_num);

	//�f�X�g���N�^
	~EnemyBarrierManagement()override { 
		delete[] m_pEnemy;
		delete[] m_pBarrier;
	}

	//�X�V����
	void Update();

	//�`�揈��
	void Draw(void)const;

	//�w�肵����HP�����炷�@�G�����񂾂�true��Ԃ�
	bool ReduceHP(int index_num, int reduceHP)override;

	//�w�肵���ԍ��̕ʃI�u�W�F�N�g��HP�����炷 �G�����񂾂�true��Ԃ�
	//(�I�[�o�[���C�h�p)
	bool ReduceOtherHP(int index_num, int reduceHP)override;

	//�w�肵���G������
	void DeleteObj(int index_num)override;

	//�w�肵���e������(���g���ĂȂ�)
	void DeleteBullet(int index_num)override{}

	//�w�肵���o���A������
	void DeleteOther(int index_num)override;

	//�w�肵���ԍ��̓G�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemy[index_num].GetPos(); }

	//�w�肵���ԍ��̓G�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemy[0].GetSize(); }

	//�w�肵���e�̍��W��Ԃ�
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return D3DXVECTOR2(-30.0f, -30.0f); }

	//�e�̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return D3DXVECTOR2(0.0f, 0.0f);}

	//�w�肵���ԍ��̃o���A�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetOtherPos(int index_num)const override { return m_pBarrier[index_num].GetPos(); };

	//�w�肵���ԍ��̃o���A�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetOtherSize(int index_num = 0)const override { return m_pBarrier[index_num].GetSize(); };

	//�w�肵���ԍ��̓G���~�߂�
	void StopEnemy(int index_num, int time) override { m_pEnemy[index_num].StopEnemy(time); }

};

#endif // !_MANAGEMENT_ENEMY_BARRIER_H_