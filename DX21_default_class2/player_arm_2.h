#pragma once
//=======================================
// プレイヤーの腕2関係(ヘッダファイル)
// 作成日：2022/11/01
// 作成者：矢野翔大
//=======================================

#ifndef _PLAYER_ARM_2_H_
#define _PLAYER_ARM_2_H_

#include "inh_player_arm.h"
#include "draw_object.h"
#include "laser.h"
#include "player.h"

class PlayerArm2 :public inhPlayerArm
{
	//定数
private:
	//ここで初期化
	static const int BULLET_NUM_MAX = 5;		//弾の制限数　実際に撃てる数はこれより１少ない
	static const int BULLET_SHOOT_MAX = 5;		//弾の同時最大発射数
	static const int BULLET_INTERVAL = 20;		//弾の発射間隔

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
	PlayerArm2() { m_pLaser = new Laser[BULLET_SHOOT_MAX]; }

	//引数付きコンストラクタ
	PlayerArm2(DrawObject& bulletdraw, bool right, int type) 
		:inhPlayerArm(BULLET_NUM_MAX, right, type), m_laser_draw(bulletdraw) { m_pLaser = new Laser[BULLET_SHOOT_MAX]; }

	//デストラクタ
	~PlayerArm2()override { delete[] m_pLaser; }

	//更新処理(オーバーライド)
	void Update(const D3DXVECTOR2& arm_pos)override;

	//描画処理(オーバーライド)
	void PlayerArmDraw()const override;

	//指定した番号の弾を消す(オーバーライド)
	void DeleteBullet(int index_num)override;

	//指定した番号の弾の座標を返す(オーバーライド用)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override
		{ return m_pLaser[index_num].GetPos(); }

	//指定した番号の弾のサイズを返す(オーバーライド用)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override
		{ return m_pLaser[index_num].GetSize();	}
};

#endif // !_PLAYER_ARM_1_H_