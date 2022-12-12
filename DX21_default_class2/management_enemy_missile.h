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
//#include "enemy_missile.h"
#include "bullet.h"
#include "draw_object.h"

class EnemyMissileManagement :public EnemyManagement
{
	//定数
private:
	//ここで初期化
	//敵自身
	static const int ENEMY_NUM = 10;		//敵を出現させる数
	static const int BULLET_BREAK_TIME = 200;	//ホーミング弾が壊れる時間

	//cppで初期化
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
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
										D3DXVECTOR2(52.5f + (105 *  1), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 * 10), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 *  0), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 * 11), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 *  2), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 *  9), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 *  6), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 *  7), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 *  8), -EnemyNormal::SIZE_Y / 2),
										D3DXVECTOR2(52.5f + (105 *  9), -EnemyNormal::SIZE_Y / 2)
										
	};
	//敵を出す時間
	int m_SetEnemyTime[ENEMY_NUM] = {
								60 * 15,
								60 * 15 + 1,
								60 * 50,
								60 * 50 + 1,
								60 * 70,
								60 * 70 + 1,
								60 * 85,
								60 * 85 + 1,
								60 * 85 + 2,
								60 * 85 + 3,
	};
	//メンバ関数
public:
	//デフォルトコンストラクタ
	EnemyMissileManagement() {
		m_pEnemyMissile = new EnemyNormal[ENEMY_NUM];
		m_pBullet = new Bullet[ENEMY_NUM];
	}

	//引数付きコンストラクタ
	EnemyMissileManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2);

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
};

#endif // !_ENEMY_NORMAL_MISSILE_H_