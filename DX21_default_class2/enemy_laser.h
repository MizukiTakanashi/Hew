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
	int m_laser_index = -1;				//レーザー番号
	int m_laser_direction = 0;			//レーザーの方向
	int m_appearance_time = 0;			//出現してからのカウント
	bool m_exit_direction_right = true;	//退出方向
	bool m_exit_flag = false;			//退出になったかフラグ

//メンバ関数
public:
	EnemyLaser(){}		//デフォルトコンストラクタ

	//引数付きコンストラクタ
	EnemyLaser(DrawObject& pDrawObject, const D3DXVECTOR2& pos, bool exit_direction_right = true)
		:Inh_Enemy(pDrawObject, pos, D3DXVECTOR2(SIZE_X, SIZE_Y), HP_MAX),
		m_exit_direction_right(exit_direction_right) {}

	~EnemyLaser()override{}	//デストラクタ

	void Update(void);	//更新処理

	//レーザー番号を返す
	int GetLaserIndex(void) const { return m_laser_index; }

	//レーザー番号をセット
	void SetLaserIndex(int num) { m_laser_index = num; }

	//レーザーの方向を返す
	int GetLaserDirection(void)const { return m_laser_direction; }

	//レーザーの方向をセット
	void SetLaserDirection(int direction) { m_laser_direction = direction; }

	//出現してからのカウントを数える
	int GetAppearanceTime(void)const { return m_appearance_time; }

	//退出時間になったかフラグをオン
	void OnExitFlag(void) { m_exit_flag = true; }

	//退出方向を返す
	//true：右　false：左
	bool IsExitDirectionRight(void)const { return m_exit_direction_right; }
};