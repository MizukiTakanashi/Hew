#pragma once
//=================================================
// 腕から出る弾と敵の当たり判定(ヘッダファイル)
// 作成日：2022/11/01
// 作成者：山本亮太
//=================================================

#ifndef _PLAYER_ARM_ENEMY_COL_H_
#define _PLAYER_ARM_ENEMY_COL_H_

#include "ExplosionManagement.h"
#include "ItemManagement.h"
#include "number.h"
#include "inhPlayerArm.h"
#include "EnemyManagement.h"

class PlayerArmEnemyCol
{
private:
	EnemyManagement* m_pEnemy = nullptr;			//全敵
	ExplosionManagement* m_pExplosion = nullptr;	//爆発
	ItemManagement* m_pItem = nullptr;				//アイテム
	Number* m_pNumber = nullptr;					//倒した敵の数表示
	inhPlayerArm* m_pArm = nullptr;					//腕から出る弾

	int m_EnemyNum = 0;								//敵の種類の数
	bool m_PlayerEnemyCol = false;					//敵自身とプレイヤー自身の当たりフラグ

public:
	//デフォルトコンストラクタ
	PlayerArmEnemyCol() {}

	//引数付きコンストラクタ
	PlayerArmEnemyCol(inhPlayerArm* pPlayer, EnemyManagement* pEnemy, ExplosionManagement* pExplosion,
		ItemManagement* pItem, Number* pNumber, int EnemyNum)
		:m_pArm(pPlayer), m_pEnemy(pEnemy), m_pExplosion(pExplosion),
		m_pItem(pItem), m_pNumber(pNumber), m_EnemyNum(EnemyNum) {}

	//デストラクタ
	~PlayerArmEnemyCol() {}

	//全ての敵とプレイヤーの当たり判定
	void Collision(void);

	//プレイヤーの腕のアイテムをセット
	void SetPlayerArm(inhPlayerArm* pArm) { m_pArm = pArm; }
};

#endif // !_PLAYER_ARM_ENEMY_COL_H_#pragma once
