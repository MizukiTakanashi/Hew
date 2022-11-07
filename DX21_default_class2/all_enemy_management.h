#pragma once
//=======================================
// �S�Ă̓G�̊Ǘ��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/10/30
// �쐬�ҁF��������
//=======================================

#ifndef _ALL_ENEMY_MANAGEMENT_H_
#define _ALL_ENEMY_MANAGEMENT_H_

#include "management_enemy.h"

class AllEnemyManagement
{
//�萔
private:
	//�����ŏ�����
	static const int ENEMY_NUM = 3;			//�S�G�̎�ސ�

//�����o�ϐ�
private:
	int m_enemy_num = 0;					//�G�̎�ނ̐�
	EnemyManagement* m_pEnemy[ENEMY_NUM];	//�G�S�N���X

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	AllEnemyManagement(){}

	//�����t���R���X�g���N�^
	AllEnemyManagement(EnemyManagement* p1, EnemyManagement* p2, EnemyManagement* p3) {
		m_pEnemy[0] = p1;
		m_pEnemy[1] = p2;
		m_pEnemy[2] = p3;
	}

	//�f�X�g���N�^
	~AllEnemyManagement(){}

	//�N���X�̃|�C���^��������
	void AddPointer(EnemyManagement* p){
		m_pEnemy[m_enemy_num] = p;
		m_enemy_num++;				//�G�̎�ނ̐��𑝂₷
	}

	//���������ԋ߂��G�̈ʒu��Ԃ�
	const D3DXVECTOR2& GetCloltestEnemyPos(const D3DXVECTOR2& pos);
};

#endif // !_ALL_ENEMY_MANAGEMENT_H_