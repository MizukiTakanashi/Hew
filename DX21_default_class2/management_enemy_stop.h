//=======================================
// 動きを止める敵の管理関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#ifndef _ENEMY_STOP_MANAGEMENT_H_
#define _ENEMY_STOP_MANAGEMENT_H_

#include "main.h"
#include "management_enemy.h"
#include "draw_object.h"
#include "enemy_stop.h"
#include "bullet_stop.h"

class EnemyStopManagement:public EnemyManagement
{
//定数
private:
	//ここで初期化
	//敵自身
	static const int ENEMY_NUM = 5;		//敵を出現させる数
	static const int BULLET_TIME = 60;		
	static const int BULLET_NUM = 20;	//同時に出せる弾

	//cppで初期化
	//弾
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY
	static const float BULLET_SPEED;		//スピード

public:
	//ここで初期化
	//敵自身
	static const int ATTACK = 5;			//攻撃値
	//弾
	static const int BULLET_ATTACK = 1;		//攻撃値

//メンバ変数
private:
	EnemyStop* m_pEnemy = nullptr;			//敵のクラス
	BulletStop* m_pBullet = nullptr;		//弾のクラス
	DrawObject m_pDrawObjectEnemy;			//敵の描画オブジェクト
	DrawObject m_pDrawObjectBullet;			//弾の描画オブジェクト
	int m_SE_11 = 0;						//冷気を出した時の音

	//敵の位置配列
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(52.5f + (105 *  1), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  9), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  1), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  9), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 *  0), -EnemyStop::SIZE_Y / 2)
	};

	//敵を出す時間
	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 30,
		60 * 30 + 1,
		60 * 105,
		60 * 105 + 1,
		60 * 170
	};

//メンバ関数
public:
	//デフォルトコンストラクタ
	EnemyStopManagement() {
		m_pEnemy = new EnemyStop[ENEMY_NUM];
		m_pBullet = new BulletStop[ENEMY_NUM];
	}

	//引数付きコンストラクタ
	EnemyStopManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2);

	//デストラクタ
	~EnemyStopManagement()override{}

	//更新処理
	void Update(void);

	//描画処理
	void Draw(void)const;

	//指定したのHPを減らす　敵が死んだらtrueを返す
	bool ReduceHP(int index_num, int reduceHP)override;

	//指定した敵を消す
	void DeleteObj(int index_num)override;

	//指定した弾を消す
	void DeleteBullet(int index_num)override;

	//指定した番号の敵の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const override{ return m_pEnemy[index_num].GetPos(); }

	//指定した番号の敵のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override{ return m_pEnemy[0].GetSize(); }

	//指定した番号の弾の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//指定した番号の弾のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override{ return m_pBullet[0].GetSize(); }

	//弾の攻撃力を返す
	int GetBulletAttack(void) const override { return 0; }

	//指定した番号の敵を止める
	void StopEnemy(int index_num, int time) override { m_pEnemy[index_num].StopEnemy(time); }

};

#endif // !_ENEMY_STOP_MANAGEMENT_H_