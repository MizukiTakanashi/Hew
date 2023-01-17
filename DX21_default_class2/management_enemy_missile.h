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

	int m_EnemyItem_num = 0;	//敵のアイテムの数

	//敵の配列
	D3DXVECTOR2 m_SetEnemy[(int)STAGE::NUM][6] = {
	{//チュートリアル
		D3DXVECTOR2(52.5f + (105 * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 9), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 5), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 1), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 9), -EnemyNormal::SIZE_Y / 2)
	},

	{//火星
		D3DXVECTOR2(52.5f + (105 * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 0), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 10), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 8), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 2), -EnemyNormal::SIZE_Y / 2),
		D3DXVECTOR2(52.5f + (105 * 6), -EnemyNormal::SIZE_Y / 2)
	},
	};

	int m_SetEnemyTime[(int)STAGE::NUM][6] = {
	{//チュートリアル
		60 * 40,
		60 * 40 + 1,
		60 * 45,
		60 * 80,
		60 * 80 + 1
	},

	{//火星
		60 * 5,
		60 * 60,
		60 * 60 + 1,
		60 * 80,
		60 * 145,
		60 * 160
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