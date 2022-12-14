//=======================================
// 普通の敵関係(ヘッダファイル)
// 作成日：2022/09/13
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _ENEMY_GATORING_H_
#define _ENEMY_GATORING_H_

#include "main.h"
#include "inh_enemy.h"

class EnemyGatoring :public Inh_Enemy
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
	static const int BULLET_TIME = 30;	//弾の発射間隔
	static const int INVINCIBLE_FLAME = 30;	//敵の無敵時間

	//cppで初期化
	static const float SPEED_X;			//敵のスピードY
	static const float SPEED_Y;			//敵のスピードY
	static const int HP_MAX = 1;		//敵のHP最大値

//メンバ変数
private:
	int m_appearance_time = 0;			//出現してからのカウント

//メンバ関数
public:
	EnemyGatoring() {}		//デフォルトコンストラクタ

	//引数付きコンストラクタ
	EnemyGatoring(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}

	~EnemyGatoring()override {}	//デストラクタ

	void Update(void);	//更新処理

	//出現してからのカウントを数える
	int GetAppearanceTime(void)const { return m_appearance_time; }
};

#endif // !_ENEMY_GATORING_H_