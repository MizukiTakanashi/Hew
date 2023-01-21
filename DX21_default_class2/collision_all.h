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
#include "score.h"
#include "Bom.h"

//各ステージ
#include "management_meteo.h"
#include "management_enemy_grenade.h"
#include "player_hp.h"
#include "management_poisonfield.h"

class CollisionAll
{
//定数
public:
	enum class STAGE :int
	{
		MOON,
		MARS,
		MERCURY,
		SATURN,
		NUM
	};

private:
	//ここで初期化
	static const int ENEMY_NUM = 10;		//全敵の種類数の制限数
	static const int SE_INTERVAL = 30;		//爆発の音の間隔


//メンバ変数
private:
	STAGE m_stage = STAGE::MOON;					//現在のステージ

	Player* m_pPlayer = nullptr;					//プレイヤー

	int m_enemy_num = 0;							//敵の種類の数
	EnemyManagement* m_pEnemy[ENEMY_NUM];			//敵全クラス

	inhPlayerArmBoth* m_pPlayerLeft = nullptr;		//プレイヤーの左腕
	inhPlayerArmBoth* m_pPlayerRight = nullptr;		//プレイヤーの右腕
	
	ExplosionManagement* m_pExplosion = nullptr;	//爆発
	ItemManagement* m_pItem = nullptr;				//アイテム
	Score* m_pScore = nullptr;						//倒した敵の数表示
	Number* m_pCombo = nullptr;						//コンボのポインタ

	bool m_player_enemy_col = false;				//プレイヤーと敵が当たったか判定

	int m_SE = 0;									//爆発の音
	int m_SE_interval_count = 0;					//爆発の音の間隔カウント

	Bom* m_pBom = nullptr;							//ボム

	//==========================
	// 各ステージ
	//月
	Management_Meteo* m_pMeteo = nullptr;			//隕石

	//火星
	EnemyGrenadeManagement* m_pGrenade = nullptr;	//グレネード敵
	int m_SE_08 = 0;								//バリアが弾を跳ね返す音
	int m_SE_09 = 0;								//バリアが壊れる音
	int m_SE_10 = 0;								//冷気を浴びた音

	//水星
	PlayerHP* m_pHP = nullptr;						//プレイヤーのHP

	//土星
	Management_PoisonField* m_pPoison = nullptr;	//毒沼

//メンバ関数
public:
	//デフォルトコンストラクタ
	CollisionAll();

	//引数付きコンストラクタ
	CollisionAll(STAGE stage, Player* pPlayer, inhPlayerArmBoth* pL, inhPlayerArmBoth* pR, 
		ExplosionManagement* pExplosion, ItemManagement* pItem, Score* pNumber, 
		Bom* pBom);

	//デストラクタ
	~CollisionAll(){}

	//敵のクラスのポインタを加える
	void AddEnemyPointer(EnemyManagement* pEnemy) { 
		m_pEnemy[m_enemy_num] = pEnemy; 
		m_enemy_num++;
	}
	 
	//当たり判定(プレイヤーのHPが削れる当たり判定)
	int Collision(void);

	//プレイヤーのHPが回復する当たり判定
	void HeelCollision(void);


	//==========================
	// 各ステージ
	
	//月
	//隕石をセット
	void SetMeteo(Management_Meteo* pMeteo) { m_pMeteo = pMeteo; }

	//火星
	//グレネード敵をセット
	void SetGrenade(EnemyGrenadeManagement* pGrenade) { m_pGrenade = pGrenade; }

	//水星
	//プレイヤーのHPをセット
	void SetHP(PlayerHP* pHP) { m_pHP = pHP; }

	//土星
	//毒沼をセット
	void SetPoison(Management_PoisonField* pPoison) { m_pPoison = pPoison; }
};

#endif // !_COLLISION_ALL_H_