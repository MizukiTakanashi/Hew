//=======================================
// レーザーの敵の管理関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#ifndef _ENEMY_LASER_MANAGEMENT_H_
#define _ENEMY_LASER_MANAGEMENT_H_

#include "main.h"
#include "enemylaser.h"
#include "laser.h"
#include "DrawObject.h"
#include "EnemySetPos.h"

class EnemyLaserManagement
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

	int m_enemy_num = 0;	//敵の数
	int m_laser_num = 0;	//弾の数
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
	void DeleteEnemy(int index_num);

	//現在の敵の数を返す
	int GetEnemyNum(void)const { return m_enemy_num; }

	//指定した敵の座標を返す
	const D3DXVECTOR2& GetEnemyPos(int index_num)const { return m_pEnemyLaser[index_num].GetPos(); }

	//敵のサイズを返す
	const D3DXVECTOR2& GetEnemySize(void)const { return m_pEnemyLaser[0].GetSize(); }


	//指定した弾を消す
	void DeleteBullet(int index_num);
	
	//現在の弾の数を返す
	int GetBulletNum(void)const { return m_laser_num; }

	//指定した弾の座標を返す
	const D3DXVECTOR2& GetBulletPos(int index_num)const { return m_pLaser[index_num].GetPos(); }

	//弾のサイズを返す
	const D3DXVECTOR2& GetBulletSize(void)const { return m_pLaser[0].GetSize(); }


};

#endif // !_ENEMY_LASER_MANAGEMENT_H_