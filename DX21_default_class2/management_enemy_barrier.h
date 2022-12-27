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
	static const int ENEMY_NUM = 4;			//�G���o�������鐔

	//cpp�ŏ�����
	static const D3DXVECTOR2 BARRIER_SIZE;	//�o���A�̑傫��
	static const D3DXVECTOR2 INTERVAL_POS;	//�G�ƃo���A�̊Ԋu

//�����o�ϐ�
private:
	EnemyBarrier* m_pEnemy = nullptr;	//�G�̃N���X
	GameObject* m_pBarrier = nullptr;	//�o���A
	int m_BarrierHP[ENEMY_NUM];			//�o���A��HP
	DrawObject m_pDrawObjectEnemy;		//�G�̕`��I�u�W�F�N�g
	DrawObject m_pDrawObjectBarrier;	//�o���A�̕`��I�u�W�F�N�g

	//�G�̈ʒu�z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(52.5f + (105 * 2), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 2), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 4), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 10), -EnemyBarrier::SIZE_Y / 2)
	};

	//�G���o������
	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 5,
		60 * 80,
		60 * 160,
		60 * 170
	};

	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyBarrierManagement() {
		m_pEnemy = new EnemyBarrier[ENEMY_NUM];
		m_pBarrier = new GameObject[ENEMY_NUM];

		for (int i = 0; i < ENEMY_NUM; i++) {
			m_BarrierHP[i] = BARRIER_HP_MAX;
		}
	}

	//�����t���R���X�g���N�^
	EnemyBarrierManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2);

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