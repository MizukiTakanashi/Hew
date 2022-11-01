//=============================================================
// プレイヤーとレーザーの敵の諸々の当たり判定関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=============================================================
#pragma once

#ifndef _PLAYER_ENEMY_LASER_COLLISION_H_
#define _PLAYER_ENEMY_LASER_COLLISION_H_

#include "player.h"
#include "enemy_laser_management.h"
#include "explosion_management.h"
#include "number.h"
#include "item_management.h"
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
	Number* m_pNumber = nullptr;
	ItemManagement* m_rItemManagement = nullptr;
	bool m_PlayerEnemyNormalCol = false;	//プレイヤー自身と敵自身が当たっているかフラグ

public:
	PlayerEnemyLaserCollision() {}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerEnemyLaserCollision(Player* rPlayer, EnemyLaserManagement* rEnemyNormalManagement,
		ExplosionManagement* rExplosionManagement, Number* pNumber, ItemManagement* m_rItem)
		:m_rPlayer(rPlayer), m_rEnemyManagement(rEnemyNormalManagement),
		m_rExplosionManagement(rExplosionManagement), m_pNumber(pNumber), m_rItemManagement(m_rItem) {}

	~PlayerEnemyLaserCollision() {}	//デストラクタ

	//更新処理
	int Update(void);
};

#endif // !_PLAYER_ENEMY_LASER_COLLISION_H_