//=======================================
// 火球の敵の管理関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#ifndef _ENEMY_FIREBALL_MANAGEMENT_H_
#define _ENEMY_FIREBALL_MANAGEMENT_H_

#include "main.h"
#include "management_enemy.h"
#include "enemy_normal.h"
#include "bullet.h"
#include "draw_object.h"

class EnemyFireballManagement :public EnemyManagement
{
//定数
private:
	//ここで初期化
	//敵自身
	static const int BULLET_BREAK_TIME = 200;	//ホーミング弾が壊れる時間
	static const int EXIT_TIME = 60 * 10;		//退出時間

	//cppで初期化
	static const int ENEMY_NUM = 14;		//敵を出現させる数W
	//弾
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY
	static const float BULLET_SPEED;		//スピード

public:
	//ここで初期化
	//敵自身
	static const int ATTACK = 1;			//攻撃値
	//弾
	static const int BULLET_ATTACK = 1;		//攻撃値

//メンバ変数
private:
	EnemyNormal* m_pEnemyNormal = nullptr;
	Bullet* m_pBullet = nullptr;

	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectBullet;

	int m_SE_15_2 = 0;

	//敵の配列
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(71.0f + (142 * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 6), -EnemyNormal::SIZE_Y / 2)
	};

	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 10,
		60 * 25,
		60 * 25 + 1,
		60 * 65,
		60 * 65 + 1,
		60 * 75,
		60 * 75 + 1,
		60 * 120,
		60 * 120 + 1,
		60 * 125,
		60 * 125 + 1,
		60 * 155,
		60 * 155 + 1,
		60 * 170
	};

//メンバ関数
public:
	//デフォルトコンストラクタ
	EnemyFireballManagement() {}

	//引数付きコンストラクタ
	EnemyFireballManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2);

	//デストラクタ
	~EnemyFireballManagement()override { delete[] m_pEnemyNormal; delete[] m_pBullet; }

	//更新処理
	void Update(const D3DXVECTOR2& PlayerPos);

	//描画処理
	void Draw(void)const;

	//指定したのHPを減らす
	bool ReduceHP(int index_num, int reduceHP)override;

	//指定した敵を消す
	void DeleteObj(int index_num)override;

	//指定した弾を消す
	void DeleteBullet(int index_num)override;

	//指定した番号の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemyNormal[index_num].GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemyNormal[index_num].GetSize(); }

	//指定した弾の座標を返す
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//弾のサイズを返す
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pBullet[index_num].GetSize(); }

	//指定した番号の敵を止める
	void StopEnemy(int index_num, int time) override { m_pEnemyNormal[index_num].StopEnemy(time); }

};

#endif // !_ENEMY_FIREBALL_MANAGEMENT_H_