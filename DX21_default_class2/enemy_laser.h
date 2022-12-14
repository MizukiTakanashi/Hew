//=======================================
// レーザーの敵関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#include "main.h"
#include "inh_enemy.h"

class EnemyLaser:public Inh_Enemy
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
	static const int HP_MAX = 3;			//敵のHP最大値

	//cppで初期化
	static const float SPEED_X;			//敵のスピードY
	static const float SPEED_Y;			//敵のスピードY

//メンバ変数
private:
	int m_laser_index = -1;	//レーザー番号

//メンバ関数
public:
	EnemyLaser(){}		//デフォルトコンストラクタ

	//引数付きコンストラクタ
	EnemyLaser(DrawObject& pDrawObject, const D3DXVECTOR2& pos)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX) {}

	~EnemyLaser()override{}	//デストラクタ

	void Update(void);	//更新処理

	//レーザー番号をセット
	void SetLaserIndex(int num) { m_laser_index = num; }

	//レーザー番号を返す
	int GetLaserIndex() const { return m_laser_index; }

};
