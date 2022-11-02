#pragma once
//=======================================
// プレイヤーの腕1関係(ヘッダファイル)
// 作成日：2022/10/28
// 作成者：高梨水希
//=======================================

#ifndef _PLAYER_ARM_3_H_
#define _PLAYER_ARM_3_H_

#include "inhPlayerArm.h"
#include "DrawObject.h"
#include "bullet.h"

class PlayerArm3 :public inhPlayerArm
{
	//定数
private:
	//ここで初期化
	static const int BULLET_NUM_MAX = 10;		//弾の最大数
	static const int BULLET_INTERVAL = 100;		//弾の発射間隔
	

	//cppで初期化
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY
	static const float BULLET_SPEED;		//スピード

	//メンバ変数
private:
	DrawObject m_bulletdraw;			//弾の描画オブジェクト
	Bullet* m_pBullet = nullptr;		//弾のオブジェクト
	int m_bullet_num = 0;				//現在の弾の数
	int m_bullet_interval_count = 0;	//発射間隔カウント
	bool m_right = true;				//自分が付いているのが右か左か判断

	//メンバ関数
public:
	//デフォルトコンストラクタ
	PlayerArm3() { m_pBullet = new Bullet[BULLET_NUM_MAX]; }

	//引数付きコンストラクタ
	PlayerArm3(DrawObject bulletdraw, bool right) 
		:m_bulletdraw(bulletdraw),m_right (right) { m_pBullet = new Bullet[BULLET_NUM_MAX]; }

	//デストラクタ
	~PlayerArm3() { delete[] m_pBullet; }

	//更新処理(オーバーライド)
	void Update()override;

	//描画処理(オーバーライド)
	void PlayerArmDraw()const override;

};

#endif // !_PLAYER_ARM_1_H_