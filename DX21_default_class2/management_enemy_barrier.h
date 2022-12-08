#pragma once
//=======================================
// バリアの敵の関係(ヘッダファイル)
// 作成日：2022/12/08
// 作成者：高梨水希
//=======================================

#ifndef _MANAGEMENT_ENEMY_BARRIER_H_
#define _MANAGEMENT_ENEMY_BARRIER_H_

#include "management_enemy.h"
#include "enemy_barrier.h"

class EnemyBarrierManagement:public EnemyManagement
{
//定数
private:
	//ここで初期化
	//敵自身
	static const int ENEMY_NUM = 9;		//敵を出現させる数

public:
	//ここで初期化
	//敵自身
	static const int ATTACK = 5;		//攻撃値

	//メンバ変数
private:
	EnemyBarrier* m_pEnemy = nullptr;	//敵のクラス
	DrawObject m_pDrawObjectEnemy;		//敵の描画オブジェクト

	//敵の位置配列
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(52.5f + (105 * 5), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 0), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 11), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 4), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 7), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 2), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 3), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 4), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 5), -EnemyBarrier::SIZE_Y / 2)
	};

	//敵を出す時間
	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 5,
		60 * 35,
		60 * 35 + 1,
		60 * 55,
		60 * 55 + 1,
		60 * 85,
		60 * 85 + 1,
		60 * 85 + 2,
		60 * 85 + 3,
	};

	//メンバ関数
public:
	//デフォルトコンストラクタ
	EnemyBarrierManagement() {
		m_pEnemy = new EnemyBarrier[ENEMY_NUM];
	}

	//引数付きコンストラクタ
	EnemyBarrierManagement(DrawObject& pDrawObject1);

	//デストラクタ
	~EnemyBarrierManagement()override { delete[] m_pEnemy; }

	//更新処理
	void Update(const D3DXVECTOR2& PlayerPos);

	//描画処理
	void Draw(void)const;

	//指定したのHPを減らす　敵が死んだらtrueを返す
	bool ReduceHP(int index_num, int reduceHP)override;

	//指定した敵を消す
	void DeleteObj(int index_num)override;

	//指定した番号の敵の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemy[index_num].GetPos(); }

	//指定した番号の敵のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemy[0].GetSize(); }
};

#endif // !_MANAGEMENT_ENEMY_BARRIER_H_