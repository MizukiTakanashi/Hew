//=======================================
// グレポンの敵関係(ヘッダファイル)
// 作成日：2022/12/27
// 作成者：高梨水希
//=======================================
#pragma once

#ifndef _ENEMY_GRENADE_H_
#define _ENEMY_GRENADE_H_

#include "main.h"
#include "inh_enemy.h"

class EnemyGrenade :public Inh_Enemy
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
	static const int BULLET_TIME = 300;	//弾の発射間隔
	static const int HP_MAX = 2;		//敵のHP最大値

	//cppで初期化
	static const float SPEED_X;			//敵のスピードY
	static const float SPEED_Y;			//敵のスピードY
	static const float ALPHA_SPEED;		//アルファ値変更スピード

	//メンバ変数
private:
	int m_appearance_time = 0;			//出現してからのカウント
	float m_alpha = 1.0f;				//アルファ値
	bool m_alpha_flag = false;			//アルファ値を変えていいか

	//メンバ関数
public:
	EnemyGrenade() {}		//デフォルトコンストラクタ

	//引数付きコンストラクタ
	EnemyGrenade(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}

	~EnemyGrenade()override {}	//デストラクタ

	void Update(void);	//更新処理

	//出現してからのカウントを数える
	int GetAppearanceTime(void)const { return m_appearance_time; }

	//アルファ値を帰るフラグをオン
	void OnAlphaFlag(void) { m_alpha_flag = true; }

	//現在のアルファ値を返す
	float GetAlpha(void)const { return m_alpha; }
};

#endif // !_ENEMY_GRENADE_H_