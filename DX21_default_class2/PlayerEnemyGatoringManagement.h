//=============================================================
// プレイヤーと発射レートの敵の諸々の当たり判定関係(ヘッダファイル)
// 作成日：2022/10/28
// 作成者：小西 蓮
//=============================================================
#pragma once

#ifndef _PLAYER_ENEMY_NORMAL_COLLISION_H_
#define _PLAYER_ENEMY_NORMAL_COLLISION_H_

#include "player.h"
#include "EnemyNormalManagement.h"
#include "ExplosionManagement.h"
#include "number.h"
#include "ItemManagement.h"
#include "game.h"

//敵のアイテム
static const float ENEMYITEM_SIZE_X;	//サイズX
static const float ENEMYITEM_SIZE_Y;	//サイズY
static const float ENEMYITEM_SPEED;		//スピード
class PlayerEnemyGatoringCollision
{
private:
	Player* m_rPlayer = nullptr;
	EnemyNormalManagement* m_rEnemyNormalManagement = nullptr;
	ExplosionManagement* m_rExplosionManagement = nullptr;
	Number* m_pNumber = nullptr;
	ItemManagement* m_rItemManagement = nullptr;
	bool m_PlayerEnemyNormalCol = false;	//プレイヤー自身と敵自身が当たっているかフラグ

public:
	PlayerEnemyGatoringCollision() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerEnemyGatoringCollision(Player* rPlayer, EnemyNormalManagement* rEnemyNormalManagement,
		ExplosionManagement* rExplosionManagement, Number* pNumber, ItemManagement* m_rItem)
		:m_rPlayer(rPlayer), m_rEnemyNormalManagement(rEnemyNormalManagement),
		m_rExplosionManagement(rExplosionManagement), m_pNumber(pNumber), m_rItemManagement(m_rItem) {}

	~PlayerEnemyGatoringCollision() {}	//デストラクタ

	//更新処理
	int Update(void);
};

#endif // !_PLAYER_ENEMY_NORMAL_COLLISION_H_