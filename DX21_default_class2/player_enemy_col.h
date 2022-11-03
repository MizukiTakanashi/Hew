#pragma once
//=================================================
// プレイヤーと敵の当たり判定関係(ヘッダファイル)
// 作成日：2022/10/31
// 作成者：高梨水希
//=================================================

#ifndef _PLAYER_ENEMY_COL_H_
#define _PLAYER_ENEMY_COL_H_

#include "player.h"
#include "enemy_management.h"
#include "explosion_management.h"
#include "item_management.h"
#include "number.h"

class PlayerEnemyCol
{
private:
	Player* m_pPlayer = nullptr;					//プレイヤー
	EnemyManagement* m_pEnemy = nullptr;			//全敵
	ExplosionManagement* m_pExplosion = nullptr;	//爆発
	ItemManagement* m_pItem = nullptr;				//アイテム
	Number* m_pNumber = nullptr;					//倒した敵の数表示

	int m_EnemyNum = 0;								//敵の種類の数
	bool m_PlayerEnemyCol = false;					//敵自身とプレイヤー自身の当たりフラグ

public:
	//デフォルトコンストラクタ
	PlayerEnemyCol(){}

	//引数付きコンストラクタ
	PlayerEnemyCol(Player* pPlayer, EnemyManagement* pEnemy, ExplosionManagement* pExplosion,
		ItemManagement* pItem, Number* pNumber, int EnemyNum)
		:m_pPlayer(pPlayer), m_pEnemy(pEnemy), m_pExplosion(pExplosion), 
		m_pItem(pItem), m_pNumber(pNumber), m_EnemyNum(EnemyNum) {}

	//デストラクタ
	~PlayerEnemyCol(){}

	//全ての敵とプレイヤーの当たり判定
	//プレイヤーの削れたHPの値を返す
	int Collision(void);

};

#endif // !_PLAYER_ENEMY_COL_H_