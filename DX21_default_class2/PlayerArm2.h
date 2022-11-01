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
#include "bullet.h"
#include "player.h"

class PlayerArm2 :public inhPlayerArm
{
	//定数
private:
	//ここで初期化
	static const int BULLET_NUM_MAX = 10;		//弾の最大数
	static const int BULLET_INTERVAL = 200;		//弾の発射間隔
	static const int BULLET_BREAK_TIME = 200;	//ホーミング弾が壊れる時間

	//cppで初期化
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY
	static const float BULLET_SPEED;		//スピード
	int m_lasertime = LASER_TIME;

public:
	static const float SPEED_Y;			//レーザーのスピードY
	static const int LASER_TIME;			//レーザーの射出時間
	//メンバ変数
private:
	DrawObject m_bulletdraw;			//弾の描画オブジェクト
	Bullet* m_pBullet = nullptr;		//弾のオブジェクト
	int m_bullet_num = 0;				//現在の弾の数
	int m_bullet_interval_count = 0;	//発射間隔カウント
	Player* m_pPlayer = nullptr;	//プレイヤー位置確認用
	//メンバ関数
public:
	//デフォルトコンストラクタ
	PlayerArm2() { m_pBullet = new Bullet[BULLET_NUM_MAX]; }

	//引数付きコンストラクタ
	PlayerArm2(DrawObject bulletdraw) :m_bulletdraw(bulletdraw) { m_pBullet = new Bullet[BULLET_NUM_MAX]; }

	//デストラクタ
	~PlayerArm2() { delete[] m_pBullet; }

	//更新処理(オーバーライド)
	void Update()override;

	//描画処理(オーバーライド)
	void PlayerArmDraw()const override;
};

#endif // !_PLAYER_ARM_1_H_