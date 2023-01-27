//=======================================
// ボスクラス(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#ifndef _BOSS_H_
#define _BOSS_H_

#include "main.h"
#include "inh_enemy.h"

class Boss :public Inh_Enemy
{
	//定数
public:
	//cppで初期化
	static const float SIZE_X;			//サイズX
	static const float SIZE_Y;			//サイズY
	static const float STOP_POS_Y;		//敵が止まる場所
	static const float RANGE;			//敵が動く範囲
	static const int HP_MAX = 40;		//敵のHP最大値
private:
	//ここで初期化
	static const int BULLET_TIME = 120;	//弾の発射間隔
	static const int INVINCIBLE_FLAME = 30;	//敵の無敵時間

	//cppで初期化
	static const float SPEED_X;			//敵のスピードY
	static const float SPEED_Y;			//敵のスピードY
	

	//メンバ変数
private:
	int m_appearance_time = 0;			//出現してからのカウント

	//メンバ関数
public:
	//デフォルトコンストラクタ
	Boss() {}

	//引数付きコンストラクタ
	Boss(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}

	//デストラクタ
	~Boss()override;

	//更新処理
	void Update(void);

	//弾を作るか否かのフラグを返す
	bool GetFlagBulletMake()const { return m_bullet_make; }

	//弾を作った
	void BulletMake() { m_bullet_make = false; }

};

#endif // !_BOSS_H_