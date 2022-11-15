#pragma once
//=======================================
// 全ての敵の管理関係(ヘッダファイル)
// 作成日：2022/10/30
// 作成者：高梨水希
//=======================================

#ifndef _ALL_ENEMY_MANAGEMENT_H_
#define _ALL_ENEMY_MANAGEMENT_H_

#include "management_enemy.h"

class AllEnemyManagement
{
//定数
private:
	//ここで初期化
	static const int ENEMY_NUM = 10;		//全敵の種類数の制限数

//メンバ変数
private:
	int m_enemy_num = 0;					//敵の種類の数

	//敵のインデックス番号(1番目は敵の種類の数、2番目は敵の番号)
	int m_enemy_index[2] = { -1, -1 };		
	int m_enemy_delete_before = -1;			//前フレームで消された敵の番号を記録

	EnemyManagement* m_pEnemy[ENEMY_NUM];	//敵全クラス

//メンバ関数
public:
	//デフォルトコンストラクタ
	AllEnemyManagement() { 
		for (int i = 0; i < ENEMY_NUM; i++) {	//ポインタの初期化
			m_pEnemy[i] = nullptr;
		}
	}

	//デストラクタ
	~AllEnemyManagement(){}

	//クラスのポインタを加える
	void AddPointer(EnemyManagement* p){
		m_pEnemy[m_enemy_num] = p;
		m_enemy_num++;				//敵の種類の数を増やす
	}

	//引数から一番近い敵の位置を返す
	const D3DXVECTOR2& GetCloltestEnemyPos(const D3DXVECTOR2& pos);
};

#endif // !_ALL_ENEMY_MANAGEMENT_H_