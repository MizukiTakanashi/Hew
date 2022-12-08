//=======================================
// レーザーの敵関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#ifndef _ENEMY_LASER_H_
#define _ENEMY_LASER_H_

#include "main.h"
#include "draw_object.h"
#include "game_object.h"

class EnemyLaser:public GameObject
{
//定数
public:
	//cppで初期化
	static const float SIZE_X;			//サイズX
	static const float SIZE_Y;			//サイズY

	static const float STOP_POS_Y;		//敵が止まる場所

	static const float RANGE;			//敵が動く範囲

private:
	//ここで初期化
	static const int LASER_BETWEEN = 300;	//レーザーの発射間隔
	static const int INVINCIBLE_FLAME = 30;			//敵の無敵時間


	//cppで初期化
	static const float SPEED_X;			//敵のスピードY
	static const float SPEED_Y;			//敵のスピードY
	static const int HP_MAX;			//敵のHP最大値

//メンバ変数
private:
	int m_laser_count = 0;				//弾を発射するまでのカウント
	bool m_laser_make = false;			//弾を作るか否か

	float m_move_width = 0.0f;			//敵が動く時のcosカーブ
	float m_init_posx = 0.0f;			//敵の初期位置X

	bool m_enemyitem_make = false;		//アイテムを作るか否か

	int m_laser_index = -1;	//レーザー番号

	int m_hp = HP_MAX;					//敵の現在のHP
	int m_invincible_flame = 0; //無敵時間の残り


//メンバ関数
public:
	EnemyLaser(){}		//デフォルトコンストラクタ

	//引数付きコンストラクタ
	EnemyLaser(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)), m_init_posx(pos.x) {}

	~EnemyLaser()override{}	//デストラクタ

	void Update(void);	//更新処理

	//弾を作るか否かのフラグを返す
	bool GetFlagBulletMake()const { return m_laser_make; }

	//弾を作った
	void BulletMake() { m_laser_make = false; }

	//レーザー番号をセット
	void SetLaserIndex(int num) { m_laser_index = num; }

	//レーザー番号を返す
	int GetLaserIndex() const { return m_laser_index; }

	//HPを減らす
	void ReduceHP(int amount) 
	{
		if (m_invincible_flame <= 0)
		{
			m_hp -= amount;
			m_invincible_flame = INVINCIBLE_FLAME;
		}
	}

	//HPを返す
	int GetHP(void) { return m_hp; }

};

#endif // !_ENEMY_LASER_H_