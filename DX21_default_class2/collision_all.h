#pragma once
//============================================================
// �S�ẴQ�[���I�u�W�F�N�g�̓����蔻��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/11/10
// �쐬�ҁF��������
//============================================================

#ifndef _COLLISION_ALL_H_
#define _COLLISION_ALL_H_

#include "player.h"
#include "management_enemy.h"
#include "inh_player_arm_both.h"

#include "management_explosion.h"
#include "management_item.h"
#include "number.h"

class CollisionAll
{
//�萔
private:
	//�����ŏ�����
	static const int ENEMY_NUM = 10;		//�S�G�̎�ސ��̐�����	

//�����o�ϐ�
private:
	Player* m_pPlayer = nullptr;					//�v���C���[

	int m_enemy_num = 0;							//�G�̎�ނ̐�
	EnemyManagement* m_pEnemy[ENEMY_NUM];			//�G�S�N���X
	
	inhPlayerArmBoth* m_pPlayerRight = nullptr;		//�v���C���[�̉E�r
	inhPlayerArmBoth* m_pPlayerLeft = nullptr;		//�v���C���[�̍��r
	
	ExplosionManagement* m_pExplosion = nullptr;	//����
	ItemManagement* m_pItem = nullptr;				//�A�C�e��
	Number* m_pNumber = nullptr;					//�|�����G�̐��\��

	bool m_player_enemy_col = false;				//�v���C���[��

//�����o�֐�
public:
	//�f�t�H���g�R���X�g���N�^
	CollisionAll();

	//�����t���R���X�g���N�^
	CollisionAll(Player* pPlayer, ExplosionManagement* pExplosion, 
		ItemManagement* pItem, Number* pNumber);

	//�f�X�g���N�^
	~CollisionAll(){}

	//�G�̃N���X�̃|�C���^��������
	void AddEnemyPointer(EnemyManagement* pEnemy) { 
		m_pEnemy[m_enemy_num] = pEnemy; 
		m_enemy_num++;
	}

	//�����蔻��
	int Collision(void);
};

#endif // !_COLLISION_ALL_H_