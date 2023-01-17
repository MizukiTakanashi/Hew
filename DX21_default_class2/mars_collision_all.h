#pragma once
//============================================================
// 火星の全てのゲームオブジェクトの当たり判定関係(ヘッダファイル)
// 作成日：2022/12/19
// 作成者：高梨水希
//============================================================

#ifndef _MARS_COLLISION_ALL_H_
#define _MARS_COLLISION_ALL_H_

#include "player.h"
#include "management_enemy.h"
#include "inh_player_arm_both.h"
#include "management_explosion.h"
#include "management_item.h"
#include "score.h"
#include "Bom.h"
#include "management_enemy_grenade.h"

class MarsCollisionAll
{
//定数
private:
	//ここで初期化
	static const int ENEMY_NUM = 10;		//全敵の種類数の制限数
	static const int SE_INTERVAL = 30;		//爆発の音の間隔


//メンバ変数
private:
	Player* m_pPlayer = nullptr;					//プレイヤー

	int m_enemy_num = 0;							//敵の種類の数
	EnemyManagement* m_pEnemy[ENEMY_NUM];			//敵全クラス
	EnemyGrenadeManagement* m_pGrenade;				//グレネード敵

	inhPlayerArmBoth* m_pPlayerLeft = nullptr;		//プレイヤーの左腕
	inhPlayerArmBoth* m_pPlayerRight = nullptr;		//プレイヤーの右腕

	ExplosionManagement* m_pExplosion = nullptr;	//爆発
	ItemManagement* m_pItem = nullptr;				//アイテム
	Score* m_pScore = nullptr;						//倒した敵の数表示
	Number* m_pCombo = nullptr;						//コンボのポインタ

	bool m_player_enemy_col = false;				//プレイヤーと敵が当たったか判定

	Bom* m_pBom = nullptr;							//ボム

	int m_SE = 0;									//爆発の音
	int m_SE_interval_count = 0;					//爆発の音の間隔カウント
	int m_SE_08 = 0;								//バリアが弾を跳ね返す音
	int m_SE_09 = 0;								//バリアが壊れる音
	int m_SE_10 = 0;								//冷気を浴びた音

	
//メンバ関数
public:
	//デフォルトコンストラクタ
	MarsCollisionAll();

	//引数付きコンストラクタ
	MarsCollisionAll(Player* pPlayer, inhPlayerArmBoth* pL, inhPlayerArmBoth* pR,
		ExplosionManagement* pExplosion, ItemManagement* pItem, Score* pNumber, 
		Bom* pBom, EnemyGrenadeManagement* pGrenade);

	//デストラクタ
	~MarsCollisionAll() {}

	//敵のクラスのポインタを加える
	void AddEnemyPointer(EnemyManagement* pEnemy) {
		m_pEnemy[m_enemy_num] = pEnemy;
		m_enemy_num++;
	}

	//当たり判定(プレイヤーのHPが削れる当たり判定)
	int Collision(void);

	//プレイヤーのHPが回復する当たり判定
	void HeelCollision(void);
};

#endif // !_MARS_COLLISION_ALL_H_