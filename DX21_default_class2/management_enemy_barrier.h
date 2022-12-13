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

private:
	//�����ŏ�����
	static const int ENEMY_NUM = 9;			//�G���o�������鐔

	//cpp�ŏ�����
	static const D3DXVECTOR2 BARRIER_SIZE;	//�o���A�̑傫��


//�����o�ϐ�
private:
	EnemyBarrier* m_pEnemy = nullptr;	//�G�̃N���X
	GameObject* m_pBarrier = nullptr;	//�o���A
	DrawObject m_pDrawObjectEnemy;		//�G�̕`��I�u�W�F�N�g
	DrawObject m_pDrawObjectBarrier;	//�o���A�̕`��I�u�W�F�N�g

	//�G�̈ʒu�z��
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(52.5f + (105 * 4), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 1), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 10), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 5), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 6), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 3), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 2), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 5), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 8), -EnemyBarrier::SIZE_Y / 2)
	};

	//�G���o������
	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 5,
		60 * 35,
		60 * 35 + 1,
		60 * 55,
		60 * 55 + 1,
		60 * 85,
		60 * 85 + 1,
		60 * 85 + 2,
		60 * 85 + 3,
	};

	//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	EnemyBarrierManagement() {
		m_pEnemy = new EnemyBarrier[ENEMY_NUM];
	}

	//�����t���R���X�g���N�^
	EnemyBarrierManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2);

	//�f�X�g���N�^
	~EnemyBarrierManagement()override { 
		delete[] m_pEnemy;
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

	//�w�肵���o���A(�e)������
	void DeleteBullet(int index_num)override{}

	//�w�肵���ԍ��̓G�̍��W��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemy[index_num].GetPos(); }

	//�w�肵���ԍ��̓G�̃T�C�Y��Ԃ�(�I�[�o�[���C�h)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemy[0].GetSize(); }

	//�w�肵���e�̍��W��Ԃ�
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pEnemy[index_num].GetBarrierPos(); }

	//�e�̃T�C�Y��Ԃ�
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return EnemyBarrier::BARRIER_SIZE; }
};

#endif // !_MANAGEMENT_ENEMY_BARRIER_H_