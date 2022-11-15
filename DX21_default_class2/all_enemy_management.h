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
	static const int ENEMY_NUM = 10;		//�S�G�̎�ސ��̐�����

//�����o�ϐ�
private:
	int m_enemy_num = 0;					//�G�̎�ނ̐�

	//�G�̃C���f�b�N�X�ԍ�(1�Ԗڂ͓G�̎�ނ̐��A2�Ԗڂ͓G�̔ԍ�)
	int m_enemy_index[2] = { -1, -1 };		
	int m_enemy_delete_before = -1;			//�O�t���[���ŏ����ꂽ�G�̔ԍ����L�^

	EnemyManagement* m_pEnemy[ENEMY_NUM];	//�G�S�N���X

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	AllEnemyManagement() { 
		for (int i = 0; i < ENEMY_NUM; i++) {	//�|�C���^�̏�����
			m_pEnemy[i] = nullptr;
		}
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