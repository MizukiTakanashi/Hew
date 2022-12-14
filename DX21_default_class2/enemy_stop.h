//=======================================
// 動きを止める敵関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#ifndef _ENEMY_STOP_H_
#define _ENEMY_STOP_H_

#include "main.h"
#include "inh_enemy.h"

class EnemyStop :public Inh_Enemy
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
	static const int BULLET_TIME = 240;	//弾の発射間隔
	static const int INVINCIBLE_FLAME = 30;	//敵の無敵時間

	//cppで初期化
	static const float SPEED_X;			//敵のスピードY
	static const float SPEED_Y;			//敵のスピードY
	static const int HP_MAX = 3;		//敵のHP最大値

//メンバ変数
private:


//メンバ関数
public:
	EnemyStop() {}		//デフォルトコンストラクタ

	//引数付きコンストラクタ
	EnemyStop(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}

	~EnemyStop()override {}	//デストラクタ

	void Update(void);	//更新処理
};

#endif // !_ENEMY_STOP_H_