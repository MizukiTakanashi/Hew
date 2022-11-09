//=======================================
// 普通の敵関係(ヘッダファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _ENEMY_NORMAL_H_
#define _ENEMY_NORMAL_H_

#include "main.h"
#include "bullet.h"
#include "draw_object.h"
#include "game_object.h"

class EnemyNormal:public GameObject
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
	static const int BULLET_TIME = 200;	//弾の発射間隔

	//cppで初期化
	static const float SPEED_X;			//敵のスピードY
	static const float SPEED_Y;			//敵のスピードY


//メンバ変数
private:
	int m_bullet_count = 0;				//弾を発射するまでのカウント
	bool m_bullet_make = false;			//弾を作るか否か

	float m_move_width = 0.0f;			//敵が動く時のcosカーブ
	float m_init_posx = 0.0f;			//敵の初期位置X

	bool m_enemyitem_make = false;		//アイテムを作るか否か


//メンバ関数
public:
	EnemyNormal(){}		//デフォルトコンストラクタ

	//引数付きコンストラクタ
	EnemyNormal(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:GameObject(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y)), m_init_posx(pos.x) {}

	~EnemyNormal()override{}	//デストラクタ

	void Update(void);	//更新処理

	//弾を作るか否かのフラグを返す
	bool GetFlagBulletMake()const { return m_bullet_make; }

	//弾を作った
	void BulletMake() { m_bullet_make = false; }

	//敵のアイテムを作るか否かのフラグを返す
	bool GetFlagEnemyItemMake()const { return m_enemyitem_make; }

	//敵のアイテムを作った
	void EnemyItemMake() { m_enemyitem_make = false; }
};

#endif // !_ENEMY_NORMAL_H_