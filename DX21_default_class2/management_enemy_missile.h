//=======================================
// ミサイルの管理関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#ifndef _ENEMY_NORMAL_MISSILE_H_
#define _ENEMY_NORMAL_MISSILE_H_

#include "main.h"
#include "management_enemy.h"
#include "enemy_normal.h"
#include "bullet.h"
#include "draw_object.h"

class EnemyMissileManagement :public EnemyManagement
{
//定数
private:
	//ここで初期化
	//敵自身
	static const int BULLET_BREAK_TIME = 200;	//ホーミング弾が壊れる時間
	static const int EXIT_TIME = 60 * 10;		//退出時間
	static const int BULLET_NUM = 30;			//同時に出せる弾の数

	//cppで初期化
	static const int ENEMY_NUM[(int)STAGE::NUM];	//敵を出現させる数W
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
	EnemyNormal* m_pEnemyMissile = nullptr;
	Bullet* m_pBullet = nullptr;
	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectBullet;

	int m_SE_22 = 0;						//弾発射音

	int m_EnemyItem_num = 0;				//敵のアイテムの数

	//敵の配列
	D3DXVECTOR2 m_SetEnemy[(int)STAGE::NUM][35] = {
	//チュートリアル
	{
		D3DXVECTOR2(52.5f + (105 * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 9), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 9), -EnemyNormal::SIZE_Y / 2)
	},
	//火星
	{
		D3DXVECTOR2(52.5f + (105 * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 10), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 6), -EnemyNormal::SIZE_Y / 2)
	},
	//水星
	{
		D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
	},
	//土星
	{
		// 10秒
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		// 15
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		// 25秒
		D3DXVECTOR2(71.0f + (142.0f * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 3), -EnemyNormal::SIZE_Y / 2),
		// 30
		D3DXVECTOR2(71.0f + (142.0f * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 7), -EnemyNormal::SIZE_Y / 2),
		// 40
		D3DXVECTOR2(71.0f + (142.0f * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 7), -EnemyNormal::SIZE_Y / 2),
		// 50
		D3DXVECTOR2(71.0f + (142.0f * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		// 55
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		// 65
		D3DXVECTOR2(71.0f + (142.0f * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 5), -EnemyNormal::SIZE_Y / 2),
		// 85
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 7), -EnemyNormal::SIZE_Y / 2),
		// 90
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		// 100秒
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		// 105
		D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8), -EnemyNormal::SIZE_Y / 2),
		// 120
		D3DXVECTOR2(71.0f + (142.0f * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 7), -EnemyNormal::SIZE_Y / 2),
		// 140
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		// 145
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		// 160
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		// 170
		D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8), -EnemyNormal::SIZE_Y / 2),
	},
	//金星
	{
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
	},
	//木星
	{
		D3DXVECTOR2(71.0f + (142.0f * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 6), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 5), -EnemyNormal::SIZE_Y / 2)
	}
	};

	int m_SetEnemyTime[(int)STAGE::NUM][35] = {
	//チュートリアル
	{
		60 * 40,
		60 * 40 + 1,
		60 * 45,
		60 * 80,
		60 * 80 + 1
	},
	//火星
	{
		60 * 5,
		60 * 60,
		60 * 60 + 1,
		60 * 80,
		60 * 145,
		60 * 160
	},
	//水星
	{
		60 * 140,
		60 * 140 + 1,
		60 * 150,
		60 * 150 + 1,
		60 * 170,
		60 * 170 + 1,
		60 * 170 + 2
	},
	//土星
	{
		60 * 10,
		60 * 10 + 1,
		60 + 15,
		60 * 25,
		60 * 25 + 1,
		60 * 30,
		60 * 30 + 1,
		60 * 40,
		60 * 40 + 1,
		60 * 40 + 2,
		60 * 50,
		60 * 50 + 1,
		60 * 55,
		60 * 65,
		60 * 65 + 1,
		60 * 65 + 2,
		60 * 85,
		60 * 85 + 1,
		60 * 90,
		60 * 90 + 1,
		60 * 100,
		60 * 100 + 1,
		60 * 105,
		60 * 105 + 1,
		60 * 120,
		60 * 120 + 1,
		60 * 140,
		60 * 145,
		60 * 145 + 1,
		60 * 160,
		60 * 160 + 1,
		60 * 160 + 2,
		60 * 170,
		60 * 170 + 1,
		60 * 170 + 2
	},
	//金星
	{
		60 * 100,
	},
	//木星
	{
		60 * 10,
		60 * 10 + 1,
		60 * 40,
		60 * 40 + 1,
		60 * 40 + 2,
		60 * 65,
		60 * 65 + 1,
		60 * 75,
		60 * 130,
		60 * 130 + 1,
		60 * 140,
		60 * 140 + 1,
		60 * 165,
		60 * 165 + 1,
		60 * 165 + 2,
	}
	};

	//メンバ関数
public:
	//引数付きコンストラクタ
	EnemyMissileManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage);

	//デストラクタ
	~EnemyMissileManagement()override { delete[] m_pEnemyMissile; delete[] m_pBullet; }

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
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemyMissile[index_num].GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemyMissile[index_num].GetSize(); }

	//指定した弾の座標を返す
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//弾のサイズを返す
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pBullet[index_num].GetSize(); }

	//指定した番号の敵を止める
	void StopEnemy(int index_num, int time) override { m_pEnemyMissile[index_num].StopEnemy(time); }

};

#endif // !_ENEMY_NORMAL_MISSILE_H_