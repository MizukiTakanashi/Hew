#pragma once
//============================================================
// 全てのゲームオブジェクトの当たり判定関係(ヘッダファイル)
// 作成日：2022/11/10
// 作成者：高梨水希
//============================================================

#ifndef _COLLISION_ALL_H_
#define _COLLISION_ALL_H_

#include "player.h"
#include "management_enemy.h"
#include "inh_player_arm_both.h"

#include "management_explosion.h"
#include "management_item.h"
#include "number.h"

class CollisionAll
{
//定数
private:
	//ここで初期化
	static const int ENEMY_NUM = 10;		//全敵の種類数の制限数	

//メンバ変数
private:
	Player* m_pPlayer = nullptr;					//プレイヤー

	int m_enemy_num = 0;							//敵の種類の数
	EnemyManagement* m_pEnemy[ENEMY_NUM];			//敵全クラス
	
	inhPlayerArmBoth* m_pPlayerRight = nullptr;		//プレイヤーの右腕
	inhPlayerArmBoth* m_pPlayerLeft = nullptr;		//プレイヤーの左腕
	
	ExplosionManagement* m_pExplosion = nullptr;	//爆発
	ItemManagement* m_pItem = nullptr;				//アイテム
	Number* m_pNumber = nullptr;					//倒した敵の数表示

	bool m_player_enemy_col = false;				//プレイヤーと

//メンバ関数
public:
	//デフォルトコンストラクタ
	CollisionAll();

	//引数付きコンストラクタ
	CollisionAll(Player* pPlayer, ExplosionManagement* pExplosion, 
		ItemManagement* pItem, Number* pNumber);

	//デストラクタ
	~CollisionAll(){}

	//敵のクラスのポインタを加える
	void AddEnemyPointer(EnemyManagement* pEnemy) { 
		m_pEnemy[m_enemy_num] = pEnemy; 
		m_enemy_num++;
	}

	//当たり判定
	int Collision(void);
};

#endif // !_COLLISION_ALL_H_