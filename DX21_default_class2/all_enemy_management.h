#pragma once
//=======================================
// 全ての敵の管理関係(ヘッダファイル)
// 作成日：2022/10/30
// 作成者：高梨水希
//=======================================

#ifndef _ALL_ENEMY_MANAGEMENT_H_
#define _ALL_ENEMY_MANAGEMENT_H_

#include "enemy_management.h"

class AllEnemyManagement
{
private:
	EnemyManagement* m_pEnemy = nullptr;	//敵全クラス

public:
	//デフォルトコンストラクタ
	AllEnemyManagement(){}

	//引数付きコンストラクタ
	AllEnemyManagement(EnemyManagement* p[]) :m_pEnemy(p[0]){}

	//デストラクタ
	~AllEnemyManagement(){}
};

#endif // !_ALL_ENEMY_MANAGEMENT_H_