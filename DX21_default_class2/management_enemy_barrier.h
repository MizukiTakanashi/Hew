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
public:
	//ここで初期化
	static const int ATTACK = 5;			//敵自身の攻撃値
	static const int BARRIER_ATTACK = 0;	//バリアの攻撃値
	static const int BARRIER_HP_MAX = 5;	//敵のバリアのHP最大値

private:
	//ここで初期化
	static const int ENEMY_NUM = 4;			//敵を出現させる数

	//cppで初期化
	static const D3DXVECTOR2 BARRIER_SIZE;	//バリアの大きさ
	static const D3DXVECTOR2 INTERVAL_POS;	//敵とバリアの間隔

//メンバ変数
private:
	EnemyBarrier* m_pEnemy = nullptr;	//敵のクラス
	GameObject* m_pBarrier = nullptr;	//バリア
	int m_BarrierHP[ENEMY_NUM];			//バリアのHP
	DrawObject m_pDrawObjectEnemy;		//敵の描画オブジェクト
	DrawObject m_pDrawObjectBarrier;	//バリアの描画オブジェクト

	//敵の位置配列
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(52.5f + (105 * 2), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 2), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 4), -EnemyBarrier::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 10), -EnemyBarrier::SIZE_Y / 2)
	};

	//敵を出す時間
	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 5,
		60 * 80,
		60 * 160,
		60 * 170
	};

	//メンバ関数
public:
	//デフォルトコンストラクタ
	EnemyBarrierManagement() {
		m_pEnemy = new EnemyBarrier[ENEMY_NUM];
		m_pBarrier = new GameObject[ENEMY_NUM];

		for (int i = 0; i < ENEMY_NUM; i++) {
			m_BarrierHP[i] = BARRIER_HP_MAX;
		}
	}

	//引数付きコンストラクタ
	EnemyBarrierManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2);

	//デストラクタ
	~EnemyBarrierManagement()override { 
		delete[] m_pEnemy;
		delete[] m_pBarrier;
	}

	//更新処理
	void Update();

	//描画処理
	void Draw(void)const;

	//指定したのHPを減らす　敵が死んだらtrueを返す
	bool ReduceHP(int index_num, int reduceHP)override;

	//指定した番号の別オブジェクトのHPを減らす 敵が死んだらtrueを返す
	//(オーバーライド用)
	bool ReduceOtherHP(int index_num, int reduceHP)override;

	//指定した敵を消す
	void DeleteObj(int index_num)override;

	//指定した弾を消す(尚使ってない)
	void DeleteBullet(int index_num)override{}

	//指定したバリアを消す
	void DeleteOther(int index_num)override;

	//指定した番号の敵の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemy[index_num].GetPos(); }

	//指定した番号の敵のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemy[0].GetSize(); }

	//指定した弾の座標を返す
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return D3DXVECTOR2(-30.0f, -30.0f); }

	//弾のサイズを返す
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return D3DXVECTOR2(0.0f, 0.0f);}

	//指定した番号のバリアの座標を返す(オーバーライド)
	const D3DXVECTOR2& GetOtherPos(int index_num)const override { return m_pBarrier[index_num].GetPos(); };

	//指定した番号のバリアのサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetOtherSize(int index_num = 0)const override { return m_pBarrier[index_num].GetSize(); };

	//指定した番号の敵を止める
	void StopEnemy(int index_num, int time) override { m_pEnemy[index_num].StopEnemy(time); }

};

#endif // !_MANAGEMENT_ENEMY_BARRIER_H_