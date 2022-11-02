#pragma once
//=======================================
// 全ての敵の管理関係(ヘッダファイル)
// 作成日：2022/10/30
// 作成者：高梨水希
//=======================================

#ifndef _ALL_ENEMY_MANAGEMENT_H_
#define _ALL_ENEMY_MANAGEMENT_H_

#include "EnemyManagement.h"

class AllEnemyManagement
{
//定数
private:
	//ここで初期化
	static const int ENEMY_NUM = 2;			//全敵の種類数

//メンバ変数
private:
	EnemyManagement* m_pEnemy[ENEMY_NUM];	//敵全クラス

//メンバ関数
public:
	//デフォルトコンストラクタ
	AllEnemyManagement(){}

	//引数付きコンストラクタ
	AllEnemyManagement(EnemyManagement* p1, EnemyManagement* p2) {
		m_pEnemy[0] = p1;
		m_pEnemy[1] = p2;
	}

	//デストラクタ
	~AllEnemyManagement(){}

	//引数から一番近い敵の位置を返す
	const D3DXVECTOR2& GetCloltestEnemyPos(const D3DXVECTOR2& pos);
};

#endif // !_ALL_ENEMY_MANAGEMENT_H_