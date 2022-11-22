//=============================================================
// プレイヤーと普通の敵の諸々の当たり判定関係(ヘッダファイル)
// 作成日：2022/09/22
// 作成者：高梨水希
//=============================================================
#pragma once

#ifndef _PLAYER_ENEMY_NORMAL_COLLISION_H_
#define _PLAYER_ENEMY_NORMAL_COLLISION_H_

#include "player.h"
#include "management_enemy_normal.h"
#include "management_explosion.h"
#include "score.h"
#include "management_item.h"
//敵のアイテム
static const float ENEMYITEM_SIZE_X;	//サイズX
static const float ENEMYITEM_SIZE_Y;	//サイズY
static const float ENEMYITEM_SPEED;		//スピード
class PlayerEnemyNormalCollision
{
private:
	Player* m_rPlayer = nullptr;
	EnemyNormalManagement* m_rEnemyNormalManagement = nullptr;
	ExplosionManagement* m_rExplosionManagement = nullptr;
	Score* m_pScore = nullptr;
	ItemManagement* m_rItemManagement = nullptr;
	bool m_PlayerEnemyNormalCol = false;	//プレイヤー自身と敵自身が当たっているかフラグ

public:
	PlayerEnemyNormalCollision() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerEnemyNormalCollision(Player* rPlayer, EnemyNormalManagement* rEnemyNormalManagement,
		ExplosionManagement* rExplosionManagement, Score* pNumber, ItemManagement* m_rItem)
		:m_rPlayer(rPlayer), m_rEnemyNormalManagement(rEnemyNormalManagement),
		m_rExplosionManagement(rExplosionManagement), m_pScore(pNumber), m_rItemManagement(m_rItem) {}

	~PlayerEnemyNormalCollision() {}	//デストラクタ

	//更新処理
	int Update(void);
};

#endif // !_PLAYER_ENEMY_NORMAL_COLLISION_H_