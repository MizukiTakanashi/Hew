//=======================================
// 普通の敵の管理関係(ヘッダファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _ENEMY_NORMAL_MANAGEMENT_H_
#define _ENEMY_NORMAL_MANAGEMENT_H_

#include "main.h"
#include "management_enemy.h"
#include "enemy_normal.h"
#include "bullet.h"
#include "draw_object.h"

class EnemyFireManagement :public EnemyManagement
{
//定数
private:
	//ここで初期化
	//敵自身
	static const int BULLET_BREAK_TIME = 200;	//ホーミング弾が壊れる時間
	static const int EXIT_TIME = 60 * 10;		//退出時間
	static const int BULLET_NUM = 30;			//同時に出せる弾

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
	//※ここは0の方がいいかも！炎状態になって継続ダメージにしてるから
	static const int BULLET_ATTACK = 0;		//攻撃値


//メンバ変数
private:
	EnemyNormal* m_pEnemy = nullptr;
	Bullet* m_pBullet = nullptr;

	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectBullet;

	int m_SE_15_1 = 0;						//発射音


	//敵の配列
	D3DXVECTOR2 m_SetEnemy[(int)STAGE::NUM][15/*9*/] = {
	//チュートリアル
	{
		D3DXVECTOR2(0.0f, 0.0f),
	},
	//火星
	{
		D3DXVECTOR2(0.0f, 0.0f),
	},
	//水星
	{
		D3DXVECTOR2(71.0f + (142 * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 6), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 6), -EnemyNormal::SIZE_Y / 2)

		/*D3DXVECTOR2(71.0f + (142 * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 4), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 3), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142 * 6), -EnemyNormal::SIZE_Y / 2)*/
	},
	//土星
	{
		D3DXVECTOR2(0.0f, 0.0f),
	},
	//金星
	{
		D3DXVECTOR2(0.0f, 0.0f),
	},
	//木星
	{
		D3DXVECTOR2(0.0f, 0.0f),
	}

	};

	int m_SetEnemyTime[(int)STAGE::NUM][15/*9*/] = {
	{//チュートリアル
		0, 0, 0, 0, 0, 0
	},

	{//火星
		0, 0, 0, 0, 0, 0
	},

	{//水星
		60 * 10 + 1,
		60 * 25 ,
		60 * 25 + 1,
		60 * 40 + 3,
		60 * 50,
		60 * 55,
		60 * 60 + 2,
		60 * 70,
		60 * 80,
		60 * 105,
		60 * 105 + 1,
		60 * 120,
		60 * 140,
		60 * 160,
		60 * 170 + 10

		/*60 * 10,
		60 * 25,
		60 * 25 + 1,
		60 * 80,
		60 * 105,
		60 * 105 + 1,
		60 * 140,
		60 * 160,
		60 * 170,*/
	},
	//土星
	{
		0, 0, 0, 0, 0, 0
	},
	//金星
	{
		0, 0, 0, 0, 0, 0
	},
	//木星
	{
		0, 0, 0, 0, 0, 0
	}

	};


//メンバ関数
public:
	//デフォルトコンストラクタ
	EnemyFireManagement() {}

	//引数付きコンストラクタ
	EnemyFireManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage);

	//デストラクタ
	~EnemyFireManagement()override { delete[] m_pEnemy; delete[] m_pBullet; }

	//更新処理
	void Update();

	//描画処理
	void Draw(void)const;

	//指定したのHPを減らす
	bool ReduceHP(int index_num, int reduceHP)override;

	//指定した敵を消す
	void DeleteObj(int index_num)override;

	//指定した弾を消す
	void DeleteBullet(int index_num)override;

	//指定した番号の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemy[index_num].GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemy[index_num].GetSize(); }

	//指定した弾の座標を返す
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//弾のサイズを返す
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pBullet[index_num].GetSize(); }

	//指定した番号の敵を止める
	void StopEnemy(int index_num, int time) override { m_pEnemy[index_num].StopEnemy(time); }

};

#endif // !_ENEMY_NORMAL_MANAGEMENT_H_