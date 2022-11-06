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
	static const int MAX_NUM = 10;			//敵の最大数
	static const int APPEARANCE_TIME = 350;	//敵の出現スピード

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

	int m_count = 0;		//敵の出現速度

public:
	//デフォルトコンストラクタ
	EnemyLaserManagement(){
		m_pEnemyLaser = new EnemyLaser[MAX_NUM];
		m_pLaser = new Laser[MAX_NUM];
	}	

	//引数付きコンストラクタ
	EnemyLaserManagement(DrawObject& pDrawObject1, DrawObject& pDrawObject2,
		EnemySetPos& pEnemySetPos );

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