#pragma once
//=======================================
// バリアの敵関係(ヘッダファイル)
// 作成日：2022/12/08
// 作成者：高梨水希
//=======================================

#ifndef _ENEMY_BARRIER_H_
#define _ENEMY_BARRIER_H_

#include "inh_enemy.h"

class EnemyBarrier:public Inh_Enemy
{
//定数
public:
	//cppで初期化
	static const float SIZE_X;					//サイズX
	static const float SIZE_Y;					//サイズY

	static const float STOP_POS_Y;				//敵が止まる場所

private:
	//ここで初期化
	static const int INVINCIBLE_FLAME = 30;		//敵の無敵時間
	static const int HP_MAX = 1;				//敵のHP最大値

	//cppで初期化
	static const float SPEED_Y;					//敵のスピードY


//メンバ変数
private:
	int m_barrier_index = -1;			//バリアのインデックス番号

	int m_hp = HP_MAX;					//敵の現在のHP
	int m_invincible_flame = 0;			//無敵時間の残り


//メンバ関数
public:
	//デフォルトコンストラクタ
	EnemyBarrier() {}		

	//引数付きコンストラクタ
	EnemyBarrier(DrawObject& pDrawObject, const D3DXVECTOR2& pos)

		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX),
		m_init_posx(pos.x) {}

	~EnemyBarrier()override {}	//デストラクタ

	void Update(void);	//更新処理

	//HPを減らす
	void ReduceHP(int amount)
	{
		if (m_invincible_flame <= 0)
		{
			m_hp -= amount;
			m_invincible_flame = INVINCIBLE_FLAME;
		}
	}

	//HPを返す
	int GetHP(void) { return m_hp; }

	//レーザー番号をセット
	void SetBarrierIndex(int num) { m_barrier_index = num; }

	//レーザー番号を返す
	int GetBarrierIndex() const { return m_barrier_index; }
};

#endif // !_ENEMY_BARRIER_H_