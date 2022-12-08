#pragma once
//=======================================
// バリアの敵関係(ヘッダファイル)
// 作成日：2022/12/08
// 作成者：高梨水希
//=======================================

#ifndef _ENEMY_BARRIER_H_
#define _ENEMY_BARRIER_H_

#include "game_object.h"

class EnemyBarrier:public GameObject
{
//定数
public:
	//cppで初期化
	static const float SIZE_X;			//サイズX
	static const float SIZE_Y;			//サイズY

	static const float STOP_POS_Y;		//敵が止まる場所

	static const float RANGE;			//敵が動く範囲

private:
	//ここで初期化
	static const int INVINCIBLE_FLAME = 30;	//敵の無敵時間
	static const int HP_MAX = 2;			//敵のHP最大値

	//cppで初期化
	static const float SPEED_X;			//敵のスピードY
	static const float SPEED_Y;			//敵のスピードY


//メンバ変数
private:
	float m_move_width = 0.0f;			//敵が動く時のcosカーブ
	float m_init_posx = 0.0f;			//敵の初期位置X

	bool m_enemyitem_make = false;		//アイテムを作るか否か

	int m_hp = HP_MAX;					//敵の現在のHP
	int m_invincible_flame = 0;			//無敵時間の残り


//メンバ関数
public:
	EnemyBarrier() {}		//デフォルトコンストラクタ

	//引数付きコンストラクタ
	EnemyBarrier(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)), m_init_posx(pos.x) {}

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
};

#endif // !_ENEMY_BARRIER_H_