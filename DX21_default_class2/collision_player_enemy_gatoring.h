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
#include "number.h"
#include "management_item.h"
	
class PlayerEnemyGatoringCollision
{
private:
	Player* m_rPlayer = nullptr;
	EnemyGatoringManagement* m_rEnemyGatoringManagement = nullptr;
	ExplosionManagement* m_rExplosionManagement = nullptr;
	Number* m_pNumber = nullptr;
	ItemManagement* m_rItemManagement = nullptr;
	bool m_PlayerEnemyGatoringCol = false;	//プレイヤー自身と敵自身が当たっているかフラグ

public:
	PlayerEnemyGatoringCollision() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerEnemyGatoringCollision(Player* rPlayer, EnemyGatoringManagement* rEnemyGatoringManagement,
		ExplosionManagement* rExplosionManagement, Number* pNumber, ItemManagement* m_rItem)
		:m_rPlayer(rPlayer), m_rEnemyGatoringManagement(rEnemyGatoringManagement),
		m_rExplosionManagement(rExplosionManagement), m_pNumber(pNumber), m_rItemManagement(m_rItem) {}

	~PlayerEnemyGatoringCollision() {}	//デストラクタ

	//更新処理
	int Update(void);
};

#endif // !_PLAYER_ENEMY_GATORING_COLLISION_H_