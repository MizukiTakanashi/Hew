#pragma once
//=================================================
// �r����o��e�ƓG�̓����蔻��(�w�b�_�t�@�C��)
// �쐬���F2022/11/01
// �쐬�ҁF�R�{����
//=================================================

#ifndef _PLAYER_ARM_ENEMY_COL_H_
#define _PLAYER_ARM_ENEMY_COL_H_

#include "management_explosion.h"
#include "management_item.h"
#include "score.h"
#include "inh_player_arm.h"
#include "management_enemy.h"

class PlayerArmEnemyCol
{
//�萔
private:
	//�����ŏ�����
	static const int ENEMY_NUM = 3;					//�S�G�̎�ނ̐�

private:
	EnemyManagement* m_pEnemy[ENEMY_NUM];			//�S�G
	ExplosionManagement* m_pExplosion = nullptr;	//����
	ItemManagement* m_pItem = nullptr;				//�A�C�e��
	Score* m_pNumber = nullptr;						//�|�����G�̐��\��
	inhPlayerArm* m_pArm = nullptr;					//�r����o��e

public:
	//�f�t�H���g�R���X�g���N�^
	PlayerArmEnemyCol() { m_pEnemy[0] = nullptr; m_pEnemy[1] = nullptr; m_pEnemy[2] = nullptr; }

	//�����t���R���X�g���N�^
	PlayerArmEnemyCol(EnemyManagement* p1, EnemyManagement* p2, EnemyManagement* p3,
		ExplosionManagement* pExplosion, ItemManagement* pItem, Score* pNumber);

	//�f�X�g���N�^
	~PlayerArmEnemyCol() {}

	//�S�Ă̓G�ƃv���C���[�̓����蔻��
	void Collision(void);

	//�v���C���[�̘r�̃A�C�e�����Z�b�g
	void SetPlayerArm(inhPlayerArm* pArm) { m_pArm = pArm; }
};

#endif // !_PLAYER_ARM_ENEMY_COL_H_#pragma once
