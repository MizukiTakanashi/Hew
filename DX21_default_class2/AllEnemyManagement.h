#pragma once
//=======================================
// 全ての敵の管理関係(ヘッダファイル)
// 作成日：2022/10/30
// 作成者：高梨水希
//=======================================

#ifndef _ALL_ENEMY_MANAGEMENT_H_
#define _ALL_ENEMY_MANAGEMENT_H_

#include "management.h"

class AllEnemyManagement
{
private:
	Management* m_pEnemy[];	//敵全クラス

public:
	//デフォルトコンストラクタ
	AllEnemyManagement(){}

	//デストラクタ
	~AllEnemyManagement(){}
};

#endif // !_ALL_ENEMY_MANAGEMENT_H_