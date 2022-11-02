#pragma once
//=======================================
// プレイヤーの腕2関係(ヘッダファイル)
// 作成日：2022/11/01
// 作成者：矢野翔大
//=======================================

#ifndef _PLAYER_ARM_2_H_
#define _PLAYER_ARM_2_H_

#include "inhPlayerArm.h"
#include "DrawObject.h"
#include "laser.h"
#include "player.h"

class PlayerArm2 :public inhPlayerArm
{
	//定数
private:
	//ここで初期化
	static const int BULLET_NUM_MAX = 10;		//弾の最大数
	static const int BULLET_INTERVAL = 200;		//弾の発射間隔
	static const int BULLET_BREAK_TIME = 200;	//ホーミング弾が壊れる時間

	static const int LASER_TIME = 150;			//レーザーの射出時間

	//cppで初期化
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY
	static const float BULLET_SPEED;		//スピード

	static const float SPEED_Y;			//レーザーのスピードY

//メンバ変数
private:
	DrawObject m_laser_draw;			//弾の描画オブジェクト
	Laser* m_pLaser = nullptr;			//弾のオブジェクト
	int m_bullet_interval_count = 0;	//発射間隔カウント
	int m_lasertime = LASER_TIME;		//レーザーの射出時間

//メンバ関数
public:
	//デフォルトコンストラクタ
	PlayerArm2() { m_pLaser = new Laser[BULLET_NUM_MAX]; }

	//引数付きコンストラクタ
	PlayerArm2(DrawObject bulletdraw) 
		:inhPlayerArm(), m_laser_draw(bulletdraw) { m_pLaser = new Laser[BULLET_NUM_MAX]; }

	//デストラクタ
	~PlayerArm2() { delete[] m_pLaser; }

	//更新処理(オーバーライド)
	void Update(const D3DXVECTOR2& arm_pos)override;

	//描画処理(オーバーライド)
	void PlayerArmDraw()const override;

	void SetArmPos(const D3DXVECTOR2&){}
};

#endif // !_PLAYER_ARM_1_H_