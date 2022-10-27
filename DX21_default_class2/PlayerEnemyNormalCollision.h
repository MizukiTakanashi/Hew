//=============================================================
// �v���C���[�ƕ��ʂ̓G�̏��X�̓����蔻��֌W(�w�b�_�t�@�C��)
// �쐬���F2022/09/22
// �쐬�ҁF��������
//=============================================================
#pragma once

#ifndef _PLAYER_ENEMY_NORMAL_COLLISION_H_
#define _PLAYER_ENEMY_NORMAL_COLLISION_H_

#include "player.h"
#include "EnemyNormalManagement.h"
#include "ExplosionManagement.h"
#include "number.h"
#include "ItemManagement.h"
	//�G�̃A�C�e��
static const float ENEMYITEM_SIZE_X;	//�T�C�YX
static const float ENEMYITEM_SIZE_Y;	//�T�C�YY
static const float ENEMYITEM_SPEED;		//�X�s�[�h
class PlayerEnemyNormalCollision
{
private:
	Player* m_rPlayer = nullptr;
	EnemyNormalManagement* m_rEnemyNormalManagement = nullptr;
	ExplosionManagement* m_rExplosionManagement = nullptr;
	Number* m_pNumber = nullptr;
	ItemManagement* m_rItemManagement = nullptr;
	bool m_PlayerEnemyNormalCol = false;	//�v���C���[���g�ƓG���g���������Ă��邩�t���O

public:
	PlayerEnemyNormalCollision() {}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	PlayerEnemyNormalCollision(Player* rPlayer, EnemyNormalManagement* rEnemyNormalManagement,
		ExplosionManagement* rExplosionManagement, Number* pNumber, ItemManagement* m_rItem)
		:m_rPlayer(rPlayer), m_rEnemyNormalManagement(rEnemyNormalManagement),
		m_rExplosionManagement(rExplosionManagement), m_pNumber(pNumber), m_rItemManagement(m_rItem) {}

	~PlayerEnemyNormalCollision() {}	//�f�X�g���N�^

	//�X�V����
	int Update(void);
};

#endif // !_PLAYER_ENEMY_NORMAL_COLLISION_H_