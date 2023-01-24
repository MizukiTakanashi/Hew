//=======================================
// めぐみんの管理関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#ifndef _ENEMY_MEGUMIN_MANAGEMENT_H_
#define _ENEMY_MEGUMIN_MANAGEMENT_H_

#include "main.h"
#include "management_enemy.h"
#include "draw_object.h"
#include "enemy_stop.h"
#include "bullet.h"

class EnemyMeguminManagement:public EnemyManagement
{
//定数
private:
	//ここで初期化
	//敵自身
	static const int ENEMY_NUM = 8;		//敵を出現させる数
	static const int BULLET_TIME = 60;		

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
	Bullet* m_pBullet = nullptr;			//弾のクラス
	DrawObject m_pDrawObjectEnemy;			//敵の描画オブジェクト
	DrawObject m_pDrawObjectBullet;			//弾の描画オブジェクト
	int m_SE_18 = 0;						//ガス噴射音

	//敵の位置配列
	D3DXVECTOR2 m_SetEnemy[ENEMY_NUM] = {
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 1), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 7), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 3), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 5), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 4), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 1), -EnemyStop::SIZE_Y / 2),
		D3DXVECTOR2(71.0f + (142.0f * 7), -EnemyStop::SIZE_Y / 2)
	};

	//敵を出す時間
	int m_SetEnemyTime[ENEMY_NUM] = {
		60 * 5,
		60 * 10,
		60 * 10 + 1,
		60 * 50,
		60 * 50 + 1,
		60 * 110,
		60 * 155,
		60 * 155 + 1
	};

//メンバ関数
public:
	//引数付きコンストラクタ
	EnemyMeguminManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2);

	//デストラクタ
	~EnemyMeguminManagement()override{}

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
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override{ return m_pEnemy[index_num].GetSize(); }

	//指定した番号の弾の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pBullet[index_num].GetPos(); }

	//指定した番号の弾のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override{ return m_pBullet[index_num].GetSize(); }

	//指定した番号の敵を止める
	void StopEnemy(int index_num, int time) override { m_pEnemy[index_num].StopEnemy(time); }

};

#endif // !_ENEMY_MEGUMIN_MANAGEMENT_H_