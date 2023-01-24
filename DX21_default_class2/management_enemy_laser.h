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

class EnemyLaserManagement:public EnemyManagement
{
//定数
private:
	//ここで初期化
	//敵自身
	static const int ENEMY_NUM[(int)STAGE::NUM];	//敵を出現させる数W
	static const int EXIT_TIME = 60 * 15;	//退出時間

	//cppで初期化
	//弾
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY
	
	static const float EXIT_MOVE_SPEED_X;	//退出スピードX

public:
	//ここで初期化
	//敵自身
	static const int ATTACK = 1;			//攻撃値
	//弾
	static const int LASER_ATTACK = 1;		//攻撃値


//メンバ変数
private:
	EnemyLaser* m_pEnemyLaser = nullptr;
	Laser* m_pLaser = nullptr;
	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectLaser;

	int m_SE_06 = 0;	//ビーム音
	int m_SE_07 = 0;	//ビーム発射音
	int m_SE_14 = 0;	//熱風音
	int m_SE_19 = 0;	//ガス噴射音

	//敵の配列
	D3DXVECTOR2 m_SetEnemy[(int)STAGE::NUM][4] = {
		//月
		{
			D3DXVECTOR2(52.5f + (105 * 4), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 6), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 5), -EnemyLaser::SIZE_Y / 2),
		},
		//火星
		{
			D3DXVECTOR2(0.0f, 0.0f),
			D3DXVECTOR2(0.0f, 0.0f),
			D3DXVECTOR2(0.0f, 0.0f)
		},
		//水星
		{
			D3DXVECTOR2(71.0f + (142.0f * 3.0f), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 5.0f), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 0.0f), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 8.0f), -EnemyLaser::SIZE_Y / 2)
		},
		//土星
		{
			D3DXVECTOR2(71.0f + (142.0f * 0.0f), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 8.0f), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 3.0f), -EnemyLaser::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142.0f * 5.0f), -EnemyLaser::SIZE_Y / 2)
		}
	};
	//敵を出す時間
	int m_SetEnemyTime[(int)STAGE::NUM][4] = {
		//月
		{
			60 * 60,
			60 * 60 + 1,
			60 * 80,
		},
		//火星
		{
			0, 0, 0,
		},
		//水星
		{
			60 * 60,
			60 * 60 + 1,
			60 * 100,
			60 * 100 + 1,
		},
		//土星
		{
			60 * 1,
			60 * 40 + 1,
			60 * 165,
			60 * 165 + 1
		}
	};


//メンバー関数
public:
	//引数付きコンストラクタ
	EnemyLaserManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage);

	//デストラクタ
	~EnemyLaserManagement()override{}

	//更新処理
	void Update();

	//描画処理
	void Draw(void)const;			

	//指定したのHPを減らす　敵が死んだらtrueを返す
	bool ReduceHP(int index_num, int reduceHP)override;

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

	//指定した番号の敵を止める
	void StopEnemy(int index_num, int time) override { m_pEnemyLaser[index_num].StopEnemy(time); }

};

#endif // !_ENEMY_LASER_MANAGEMENT_H_