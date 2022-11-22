//=============================================================
// プレイヤーとレーザーの敵の諸々の当たり判定関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=============================================================
#pragma once

#ifndef _PLAYER_ENEMY_LASER_COLLISION_H_
#define _PLAYER_ENEMY_LASER_COLLISION_H_

#include "player.h"
#include "management_enemy_laser.h"
#include "management_explosion.h"
#include "score.h"
#include "management_item.h"
	//敵のアイテム
//static const float ENEMYITEM_SIZE_X;	//サイズX
//static const float ENEMYITEM_SIZE_Y;	//サイズY
//static const float ENEMYITEM_SPEED;		//スピード
class PlayerEnemyLaserCollision
{
private:
	Player* m_rPlayer = nullptr;
	EnemyLaserManagement* m_rEnemyManagement = nullptr;
	ExplosionManagement* m_rExplosionManagement = nullptr;
	Score* m_pScore = nullptr;
	ItemManagement* m_rItemManagement = nullptr;
	bool m_PlayerEnemyNormalCol = false;	//プレイヤー自身と敵自身が当たっているかフラグ

public:
	PlayerEnemyLaserCollision() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerEnemyLaserCollision(Player* rPlayer, EnemyLaserManagement* rEnemyNormalManagement,
		ExplosionManagement* rExplosionManagement, Score* pNumber, ItemManagement* m_rItem)
		:m_rPlayer(rPlayer), m_rEnemyManagement(rEnemyNormalManagement),
		m_rExplosionManagement(rExplosionManagement), m_pScore(pNumber), m_rItemManagement(m_rItem) {}

	~PlayerEnemyLaserCollision() {}	//デストラクタ

	//更新処理
	int Update(void);
};

#endif // !_PLAYER_ENEMY_LASER_COLLISION_H_