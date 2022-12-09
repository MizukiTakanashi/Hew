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
	static const float SIZE_X;					//サイズX
	static const float SIZE_Y;					//サイズY

	static const float STOP_POS_Y;				//敵が止まる場所

	static const float RANGE;					//敵が動く範囲

	static const D3DXVECTOR2 BARRIER_SIZE;		//バリアのサイズ

private:
	//ここで初期化
	static const int INVINCIBLE_FLAME = 30;		//敵の無敵時間
	static const int HP_MAX = 1;				//敵のHP最大値
	static const int BARRIER_TIME_LIMIT = 200;	//バリアの時間
	static const int BARRIER_INTERVAL = -2;		//バリアの出現間隔

	//cppで初期化
	static const float SPEED_X;					//敵のスピードY
	static const float SPEED_Y;					//敵のスピードY

	static const D3DXVECTOR2 INTERVAL_POS;		//敵とバリアの間隔


//メンバ変数
private:
	GameObject* m_pBarrier = nullptr;	//バリア

	float m_move_width = 0.0f;			//敵が動く時のcosカーブ
	float m_init_posx = 0.0f;			//敵の初期位置X

	int m_hp = HP_MAX;					//敵の現在のHP
	int m_invincible_flame = 0;			//無敵時間の残り

	int m_barrier_time = 0;				//バリアがある時間のカウント
	int m_barrier_interval_time = -1;	//次のバリアが生成される時間のカウント

	int m_barrier_index = 0;			//バリア管理の方で作る、バリアのインデックス番号を記録


//メンバ関数
public:
	//デフォルトコンストラクタ
	EnemyBarrier() {}		

	//引数付きコンストラクタ
	EnemyBarrier(DrawObject& pDrawObject, DrawObject& pDrawObject2, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)),
		m_pBarrier(new GameObject(pDrawObject2, pos + INTERVAL_POS, BARRIER_SIZE)),
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
	
	//バリアの描画
	void DrawBarrier(void)const;

	//バリアの座標を返す
	const D3DXVECTOR2& GetBarrierPos(void)const { return m_pBarrier->GetPos(); }

	//バリアを消す
	void DeleteBarrier(void) { m_barrier_interval_time = 0; m_barrier_time = -1; }

	//バリアを作ったか
	//bool IsBarrierMake(void) { return m_barrier_time == 0; }

	//バリアを壊したか
	//bool IsBarrierBreak(void) { return m_barrier_interval_time == 0; }
};

#endif // !_ENEMY_BARRIER_H_