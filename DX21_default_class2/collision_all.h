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

class CollisionAll
{
//定数
private:
	//ここで初期化
	static const int ENEMY_NUM = 10;		//全敵の種類数の制限数	

//メンバ変数
private:
	Player* m_pPlayer = nullptr;			//プレイヤー

	int m_enemy_num = 0;					//敵の種類の数
	EnemyManagement* m_pEnemy[ENEMY_NUM];	//敵全クラス

//メンバ関数
public:
	//デフォルトコンストラクタ
	CollisionAll();

	//引数付きコンストラクタ
	CollisionAll(Player* pPlayer):m_pPlayer(pPlayer);

	//デストラクタ
	~CollisionAll(){}
};

#endif // !_COLLISION_ALL_H_