//=======================================
// レーザーの敵の管理関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#ifndef _ENEMY_LASER_MANAGEMENT_H_
#define _ENEMY_LASER_MANAGEMENT_H_

#include "main.h"
#include "management_enemy.h"
#include "enemy_laser.h"
#include "laser.h"
#include "draw_object.h"
#include "enemy_set_pos.h"

class EnemyLaserManagement:public EnemyManagement
{
//定数
private:
	//ここで初期化
	//敵自身
	static const int ENEMY_NUM = 12;		//敵を出現させる数

	//cppで初期化
	//弾
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY

public:
	//ここで初期化
	//敵自身
	static const int ATTACK = 1;			//攻撃値
	//弾
	static const int LASER_ATTACK = 1;		//攻撃値


private:
	//メンバ変数
	EnemyLaser* m_pEnemyLaser = nullptr;
	Laser* m_pLaser = nullptr;
	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectLaser;
	EnemySetPos m_pEnemySetPos;

	int m_EnemyItem_num = 0;	//敵のアイテムの数

	//敵の配列
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = { D3DXVECTOR2(52.5f + (105 * 1 - 1), -EnemyLaser::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 2 - 1), -EnemyLaser::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 3 - 1), -EnemyLaser::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 4 - 1), -EnemyLaser::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 5 - 1), -EnemyLaser::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 6 - 1), -EnemyLaser::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 7 - 1), -EnemyLaser::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 8 - 1), -EnemyLaser::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 9 - 1), -EnemyLaser::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 10 - 1), -EnemyLaser::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 11 - 1), -EnemyLaser::SIZE_Y / 2)
										,D3DXVECTOR2(52.5f + (105 * 12 - 1), -EnemyLaser::SIZE_Y / 2) };
	int m_SetEnemyTime[ENEMY_NUM] = { 60 * 3,
								60 * 6,
								60 * 9,
								60 * 12,
								60 * 15,
								60 * 18,
								60 * 21,
								60 * 24,
								60 * 27,
								60 * 30,
								60 * 33,
								60 * 36 };

public:
	//デフォルトコンストラクタ
	EnemyLaserManagement(){
		m_pEnemyLaser = new EnemyLaser[ENEMY_NUM];
		m_pLaser = new Laser[ENEMY_NUM];
	}	

	//引数付きコンストラクタ
	EnemyLaserManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2,
		EnemySetPos& pEnemySetPos );

	//デストラクタ
	~EnemyLaserManagement()override{}

	//更新処理
	void Update();

	//描画処理
	void Draw(void)const;			

	//指定した敵を消す
	void DeleteObj(int index_num)override;

	//指定した弾を消す
	void DeleteBullet(int index_num)override;

	//指定した番号の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemyLaser[index_num].GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemyLaser[index_num].GetSize(); }

	//指定した弾の座標を返す
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pLaser[index_num].GetPos(); }

	//弾のサイズを返す
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override{ return m_pLaser[index_num].GetSize(); }

};

#endif // !_ENEMY_LASER_MANAGEMENT_H_