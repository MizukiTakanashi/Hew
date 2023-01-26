//=======================================
// 高速発射の敵の管理関係(ヘッダファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _ENEMY_GATORING_MANAGEMENT_H_
#define _ENEMY_GATORING_MANAGEMENT_H_

#include "main.h"
#include "management_enemy.h"
#include "enemy_gatoring.h"
#include "bullet.h"
#include "draw_object.h"

class EnemyGatoringManagement:public EnemyManagement
{
//定数
private:
	//ここで初期化
	//敵自身
	static const int BULLET_NUM = 30;		//同時に弾を出現させる数
	static const int EXIT_TIME = 60 * 10;	//退出時間

	//cppで初期化
	static const int ENEMY_NUM[(int)STAGE::NUM];	//敵を出現させる数
	//弾
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY
	static const float BULLET_SPEED;		//スピード

	static const float EXIT_MOVE_SPEED_Y;	//退出スピードY

public:
	//ここで初期化
	//敵自身
	static const int ATTACK = 5;			//攻撃値
	//弾
	static const int BULLET_ATTACK = 1;		//攻撃値

//メンバ変数
private:
	EnemyGatoring* m_pEnemyGatoring = nullptr;	//敵のクラス
	Bullet* m_pBullet = nullptr;				//弾のクラス
	DrawObject m_pDrawObjectEnemy;				//敵の描画オブジェクト
	DrawObject m_pDrawObjectBullet;				//弾の描画オブジェクト
	int m_SE_21 = 0;							//弾発射音


	//敵の位置配列
	D3DXVECTOR2 m_SetEnemy[(int)STAGE::NUM][5] = {
		//チュートリアル
		{
			D3DXVECTOR2(52.5f + (105 * 5), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 2), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 8), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 3), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 7), -EnemyGatoring::SIZE_Y / 2)
		},
		//火星
		{
			D3DXVECTOR2(52.5f + (105 * 5), -EnemyGatoring::SIZE_Y / 2),
		},
		//水星
		{
			D3DXVECTOR2(52.5f + (105 * 5), -EnemyGatoring::SIZE_Y / 2),
		},
		//土星
		{
			D3DXVECTOR2(71.0f + (142 * 0), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 8), -EnemyGatoring::SIZE_Y / 2),
		},
		//金星
		{
			D3DXVECTOR2(71.0f + (142 * 1), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 7), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 0), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 4), -EnemyGatoring::SIZE_Y / 2),
			D3DXVECTOR2(71.0f + (142 * 8), -EnemyGatoring::SIZE_Y / 2)
		}
	};

	//敵を出す時間
	int m_SetEnemyTime[(int)STAGE::NUM][5] = {
		//チュートリアル
		{
			60 * 15,
			60 * 20,
			60 * 20 + 1,
			60 * 80,
			60 * 80 + 1
		},
		//火星
		{
			60 * 0,
		},
		//水星
		{
			60 * 0,
		},
		//土星
		{
			60 * 90,
			60 * 90 + 1,
		},
		//金星
		{
			60 * 145,
			60 * 145 + 1,
			60 * 170,
			60 * 170 + 1,
			60 * 170 + 2
		}
	};

//メンバ関数
public:
	//引数付きコンストラクタ
	EnemyGatoringManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, int stage);

	//デストラクタ
	~EnemyGatoringManagement()override{}

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

	//指定した番号の敵の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const override{ return m_pEnemyGatoring[index_num].GetPos(); }

	//指定した番号の敵のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override{ return m_pEnemyGatoring[0].GetSize(); }

	//指定した番号の弾の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//指定した番号の弾のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override{ return m_pBullet[0].GetSize(); }

	//指定した番号の敵を止める
	void StopEnemy(int index_num, int time) override { m_pEnemyGatoring[index_num].StopEnemy(time); }

};

#endif // !_ENEMY_Gatoring_MANAGEMENT_H_