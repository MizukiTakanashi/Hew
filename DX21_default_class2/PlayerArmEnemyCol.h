#pragma once
//=================================================
// �r����o��e�ƓG�̓����蔻��(�w�b�_�t�@�C��)
// �쐬���F2022/11/01
// �쐬�ҁF�R�{����
//=================================================

#ifndef _PLAYER_ARM_ENEMY_COL_H_
#define _PLAYER_ARM_ENEMY_COL_H_

#include "ExplosionManagement.h"
#include "ItemManagement.h"
#include "number.h"
#include "inhPlayerArm.h"
#include "EnemyManagement.h"

class PlayerArmEnemyCol
{
private:
	EnemyManagement* m_pEnemy = nullptr;			//�S�G
	ExplosionManagement* m_pExplosion = nullptr;	//����
	ItemManagement* m_pItem = nullptr;				//�A�C�e��
	Number* m_pNumber = nullptr;					//�|�����G�̐��\��
	inhPlayerArm* m_pArm = nullptr;					//�r����o��e

	int m_EnemyNum = 0;								//�G�̎�ނ̐�
	bool m_PlayerEnemyCol = false;					//�G���g�ƃv���C���[���g�̓�����t���O

public:
	//�f�t�H���g�R���X�g���N�^
	PlayerArmEnemyCol() {}

	//�����t���R���X�g���N�^
	PlayerArmEnemyCol(inhPlayerArm* pPlayer, EnemyManagement* pEnemy, ExplosionManagement* pExplosion,
		ItemManagement* pItem, Number* pNumber, int EnemyNum)
		:m_pArm(pPlayer), m_pEnemy(pEnemy), m_pExplosion(pExplosion),
		m_pItem(pItem), m_pNumber(pNumber), m_EnemyNum(EnemyNum) {}

	//�f�X�g���N�^
	~PlayerArmEnemyCol() {}

	//�S�Ă̓G�ƃv���C���[�̓����蔻��
	void Collision(void);

	//�v���C���[�̘r�̃A�C�e�����Z�b�g
	void SetPlayerArm(inhPlayerArm* pArm) { m_pArm = pArm; }
};

#endif // !_PLAYER_ARM_ENEMY_COL_H_#pragma once
