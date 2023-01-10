//=======================================
// 普通の敵関係(ヘッダファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _ENEMY_NORMAL_H_
#define _ENEMY_NORMAL_H_

#include "main.h"
#include "inh_enemy.h"

class EnemyNormal:public Inh_Enemy
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
	static const int HP_MAX = 2;		//敵のHP最大値

	//cppで初期化
	static const float SPEED_X;			//敵のスピードY
	static const float SPEED_Y;			//敵のスピードY
	static const float ALPHA_SPEED;		//アルファ値変更スピード

//メンバ変数
private:
//メンバ関数
public:
	EnemyNormal(){}		//デフォルトコンストラクタ

	//引数付きコンストラクタ
	EnemyNormal(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}

	~EnemyNormal()override{}	//デストラクタ

	void Update(void);	//更新処理

};

#endif // !_ENEMY_NORMAL_H_