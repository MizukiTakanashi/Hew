//=============================================================
// プレイヤーと普通の敵の諸々の当たり判定関係(ヘッダファイル)
// 作成日：2022/09/22
// 作成者：高梨水希
//=============================================================
#pragma once

#ifndef _PLAYER_ENEMY_NORMAL_COLLISION_H_
#define _PLAYER_ENEMY_NORMAL_COLLISION_H_

#include "player.h"
#include "EnemyNormalManagement.h"
#include "ExplosionManagement.h"
#include "number.h"

class PlayerEnemyNormalCollision
{
private:
	Player* m_rPlayer = nullptr;
	EnemyNormalManagement* m_rEnemyNormalManagement = nullptr;
	ExplosionManagement* m_rExplosionManagement = nullptr;
	Number* m_pNumber = nullptr;
	bool m_PlayerEnemyNormalCol = false;	//プレイヤー自身と敵自身が当たっているかフラグ

public:
	PlayerEnemyNormalCollision(){}	//デフォルトコンストラクタ

	//引数付きコンストラクタ
	PlayerEnemyNormalCollision(Player* rPlayer, EnemyNormalManagement* rEnemyNormalManagement, 
		ExplosionManagement* rExplosionManagement, Number* pNumber)
		:m_rPlayer(rPlayer), m_rEnemyNormalManagement(rEnemyNormalManagement), 
		m_rExplosionManagement(rExplosionManagement), m_pNumber(pNumber){}

	~PlayerEnemyNormalCollision(){}	//デストラクタ

	//更新処理
	int Update(void);
};

#endif // !_PLAYER_ENEMY_NORMAL_COLLISION_H_