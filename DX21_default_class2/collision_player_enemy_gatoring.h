//============================================================
// PlayerEnemyGatoringCollision.h
// 作成日：2022/11/01
// 作成者：小西 蓮
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
	bool m_PlayerEnemyGatoringCol = false;	//プレイヤー自身と敵自身が当たっているかフラグ

public:
	PlayerEnemyGatoringCollision() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerEnemyGatoringCollision(Player* rPlayer, EnemyGatoringManagement* rEnemyGatoringManagement,
		ExplosionManagement* rExplosionManagement, Score* pNumber, ItemManagement* m_rItem)
		:m_rPlayer(rPlayer), m_rEnemyGatoringManagement(rEnemyGatoringManagement),
		m_rExplosionManagement(rExplosionManagement), m_pScore(pNumber), m_rItemManagement(m_rItem) {}

	~PlayerEnemyGatoringCollision() {}	//デストラクタ

	//更新処理
	int Update(void);
};

#endif // !_PLAYER_ENEMY_GATORING_COLLISION_H_