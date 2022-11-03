#pragma once
//=================================================
// 腕から出る弾と敵の当たり判定(ヘッダファイル)
// 作成日：2022/11/01
// 作成者：山本亮太
//=================================================

#ifndef _PLAYER_ARM_ENEMY_COL_H_
#define _PLAYER_ARM_ENEMY_COL_H_

#include "explosion_management.h"
#include "item_management.h"
#include "number.h"
#include "inh_player_arm.h"
#include "enemy_management.h"

class PlayerArmEnemyCol
{
//定数
private:
	//ここで初期化
	static const int ENEMY_NUM = 3;

private:
	EnemyManagement* m_pEnemy[ENEMY_NUM];			//全敵
	ExplosionManagement* m_pExplosion = nullptr;	//爆発
	ItemManagement* m_pItem = nullptr;				//アイテム
	Number* m_pNumber = nullptr;					//倒した敵の数表示
	inhPlayerArm* m_pArm = nullptr;					//腕から出る弾

	bool m_PlayerEnemyCol = false;					//敵自身とプレイヤー自身の当たりフラグ

public:
	//デフォルトコンストラクタ
	PlayerArmEnemyCol() { m_pEnemy[0] = nullptr; m_pEnemy[1] = nullptr; m_pEnemy[2] = nullptr; }

	//引数付きコンストラクタ
	PlayerArmEnemyCol(EnemyManagement* p1, EnemyManagement* p2, EnemyManagement* p3,
		ExplosionManagement* pExplosion, ItemManagement* pItem, Number* pNumber);

	//デストラクタ
	~PlayerArmEnemyCol() {}

	//全ての敵とプレイヤーの当たり判定
	void Collision(void);

	//プレイヤーの腕のアイテムをセット
	void SetPlayerArm(inhPlayerArm* pArm) { m_pArm = pArm; }
};

#endif // !_PLAYER_ARM_ENEMY_COL_H_#pragma once
