//=======================================
// グレポンの敵の管理関係(ヘッダファイル)
// 作成日：2022/12/27
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _ENEMY_GRENADE_MANAGEMENT_H_
#define _ENEMY_GRENADE_MANAGEMENT_H_

#include "main.h"
#include "management_enemy.h"
#include "enemy_grenade.h"
#include "bullet.h"
#include "draw_object.h"
#include "explosion.h"

class EnemyGrenadeManagement :public EnemyManagement
{
//定数
public:
	//ここで初期化
	static const int ATTACK = 1;			//敵の攻撃値
	static const int BULLET_ATTACK = 1;		//弾の攻撃値

	//cppで初期化
	static const D3DXVECTOR2 OTHER_RANGE;

private:
	//ここで初期化
	//敵自身
	static const int BULLET_BREAK_TIME = 200;	//ホーミング弾が壊れる時間
	static const int EXIT_TIME = 60 * 10;		//退出時間

	static const int EXPLOSION_WAIT_TIME = 200;	//爆発待ち時間
	static const int EXPLOSION_TIME = 100;		//爆発時間

	static const int BULLET_NUM = 20;			//同時に出せる弾

	//cppで初期化
	static const int ENEMY_NUM[(int)STAGE::NUM];	//敵を出現させる数W
	//弾
	static const float BULLET_SPEED;			//スピード
	static const D3DXVECTOR2 BULLET_SIZE;		//弾のサイズ
	static const D3DXVECTOR2 EXPLOSION_RANGE;	//爆発のサイズ

//メンバ変数
private:
	EnemyGrenade* m_pEnemy = nullptr;		//敵自身
	Bullet* m_pBullet = nullptr;			//弾(別オブジェクト)
	Bullet* m_pExplosion[17];				//爆発
	Explosion* m_pExplosionDraw[17];			//描画用の爆発

	DrawObject m_pDrawObjectEnemy;
	DrawObject m_pDrawObjectBullet;
	DrawObject m_pDrawObjectExplosion;

	int m_stage_num = 0;			//ステージ

	int m_SE_12 = 0;				//弾発射音

	//敵の配列
	D3DXVECTOR2 m_SetEnemy[(int)STAGE::NUM][17] = {
		//月
		{
			D3DXVECTOR2(0.0f, 0.0f),
		},
		//火星
		{
			// 25
			D3DXVECTOR2(52.5f + (105 * 2), -EnemyGrenade::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 4), -EnemyGrenade::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 6), -EnemyGrenade::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 8), -EnemyGrenade::SIZE_Y / 2),
			// 40
			D3DXVECTOR2(52.5f + (105 * 10), -EnemyGrenade::SIZE_Y / 2),
			// 80
			D3DXVECTOR2(52.5f + (105 * 0), -EnemyGrenade::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 10), -EnemyGrenade::SIZE_Y / 2),
			// 90
			D3DXVECTOR2(52.5f + (105 * 3), -EnemyGrenade::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 7), -EnemyGrenade::SIZE_Y / 2),
			// 100
			D3DXVECTOR2(52.5f + (105 * 4), -EnemyGrenade::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 6), -EnemyGrenade::SIZE_Y / 2),
			// 115
			D3DXVECTOR2(52.5f + (105 * 2), -EnemyGrenade::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 8), -EnemyGrenade::SIZE_Y / 2),
			// 135
			D3DXVECTOR2(52.5f + (105 * 0), -EnemyGrenade::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 10), -EnemyGrenade::SIZE_Y / 2),
			// 145
			D3DXVECTOR2(52.5f + (105 * 3), -EnemyGrenade::SIZE_Y / 2),
			D3DXVECTOR2(52.5f + (105 * 8), -EnemyGrenade::SIZE_Y / 2)
		},
		//水星
		{
			D3DXVECTOR2(0.0f, 0.0f),
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

	int m_SetEnemyTime[(int)STAGE::NUM][17] = {
		//月
		{
			0, 0, 0, 0, 0
		},
		//火星
		{
			60 * 25,
			60 * 25 + 1,
			60 * 25 + 2,
			60 * 25 + 3,
			60 * 40,
			60 * 80,
			60 * 80 + 1,
			60 * 90,
			60 * 90 + 1,
			60 * 100,
			60 * 100 + 1,
			60 * 115,
			60 * 115 + 1,
			60 * 135,
			60 * 135 + 1,
			60 * 145,
			60 * 145 + 1
		},
		//水星
		{
			0, 0, 0, 0, 0
		},
		//土星
		{
			0, 0, 0, 0, 0
		},
		//金星
		{
			0, 0, 0, 0, 0
		},
		//木星
		{
			0, 0, 0, 0, 0
		}
	};


//メンバ関数
public:
	//デフォルトコンストラクタ
	EnemyGrenadeManagement() {}

	//引数付きコンストラクタ
	EnemyGrenadeManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2, 
		DrawObject& pDrawObject3, int stage);

	//デストラクタ
	~EnemyGrenadeManagement()override;

	//更新処理
	void Update(const D3DXVECTOR2& PlayerPos);

	//描画処理
	void Draw(void)const;

	//爆発をセット
	void SetExplosion(D3DXVECTOR2 pos);

	//指定したのHPを減らす
	bool ReduceHP(int index_num, int reduceHP)override;

	//指定した敵を消す
	void DeleteObj(int index_num)override;

	//指定した弾を消す
	void DeleteBullet(int index_num)override;

	//指定した別オブジェクトを消す
	void DeleteOther(int index_num)override;

	//指定した番号の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetObjPos(int index_num)const override { return m_pEnemy[index_num].GetPos(); }

	//指定した番号のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetObjSize(int index_num = 0)const override { return m_pEnemy[index_num].GetSize(); }

	//指定した弾の座標を返す
	const D3DXVECTOR2& GetBulletPos(int index_num)const override { return m_pExplosion[index_num]->GetPos(); }

	//弾のサイズを返す
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override { return m_pExplosion[index_num]->GetSize(); }

	//指定した番号の別オブジェクトの座標を返す(オーバーライド用)
	const D3DXVECTOR2& GetOtherPos(int index_num)const override{ return m_pBullet[index_num].GetPos(); };

	//指定した番号の敵を止める
	void StopEnemy(int index_num, int time) override { m_pEnemy[index_num].StopEnemy(time); }
};

#endif // !_ENEMY_GRENADE_MANAGEMENT_H_