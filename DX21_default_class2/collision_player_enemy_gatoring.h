//============================================================
// PlayerEnemyGatoringCollision.h
// �쐬���F2022/11/01
// �쐬�ҁF���� �@
//============================================================
#pragma once

#ifndef _PLAYER_ENEMY_GATORING_COLLISION_H_
#define _PLAYER_ENEMY_GATORING_COLLISION_H_

#include "player.h"
#include "management_enemy_gatoring.h"
#include "management_explosion.h"
#include "score.h"
#include "management_item.h"
	
class PlayerEnemyGatoringCollision
{
private:
	Player* m_rPlayer = nullptr;
	EnemyGatoringManagement* m_rEnemyGatoringManagement = nullptr;
	ExplosionManagement* m_rExplosionManagement = nullptr;
	Score* m_pScore = nullptr;
	ItemManagement* m_rItemManagement = nullptr;
	bool m_PlayerEnemyGatoringCol = false;	//�v���C���[���g�ƓG���g���������Ă��邩�t���O

public:
	PlayerEnemyGatoringCollision() {}	//�f�t�H���g�R���X�g���N�^

	//�����t���R���X�g���N�^
	PlayerEnemyGatoringCollision(Player* rPlayer, EnemyGatoringManagement* rEnemyGatoringManagement,
		ExplosionManagement* rExplosionManagement, Score* pNumber, ItemManagement* m_rItem)
		:m_rPlayer(rPlayer), m_rEnemyGatoringManagement(rEnemyGatoringManagement),
		m_rExplosionManagement(rExplosionManagement), m_pScore(pNumber), m_rItemManagement(m_rItem) {}

	~PlayerEnemyGatoringCollision() {}	//�f�X�g���N�^

	//�X�V����
	int Update(void);
};

#endif // !_PLAYER_ENEMY_GATORING_COLLISION_H_