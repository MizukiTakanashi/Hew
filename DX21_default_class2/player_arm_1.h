#pragma once
//=======================================
// プレイヤーの腕1関係(ヘッダファイル)
// 作成日：2022/10/28
// 作成者：高梨水希
//=======================================

#ifndef _PLAYER_ARM_1_H_
#define _PLAYER_ARM_1_H_

#include "inh_player_arm.h"
#include "draw_object.h"
#include "bullet.h"
#include "sound.h"

class PlayerArm1:public inhPlayerArm
{
//定数
private:
	//ここで初期化
	static const int BULLET_NUM_MAX = 20;		//弾の制限数　実際に撃てる数はこれより１少ない
	static const int BULLET_SHOOT_MAX = 10;		//弾の同時最大発射数
	static const int BULLET_INTERVAL = 20;		//弾の発射間隔
	static const int BULLET_BREAK_TIME = 200;	//ホーミング弾が壊れる時間

	//cppで初期化
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY
	static const float BULLET_SPEED;		//スピード

//メンバ変数
private:
	DrawObject m_bulletdraw;			//弾の描画オブジェクト
	Bullet* m_pBullet = nullptr;		//弾のオブジェクト
	int m_interval_count = 0;			//発射間隔のカウント
	int m_SE_22 = 0;					//発射音

//メンバ関数
public:
	//デフォルトコンストラクタ
	PlayerArm1(){ m_pBullet = new Bullet[BULLET_SHOOT_MAX]; }

	//引数付きコンストラクタ
	PlayerArm1(DrawObject& bulletdraw, bool right, int type)
		:inhPlayerArm(BULLET_NUM_MAX, right, type), m_bulletdraw(bulletdraw) {
		m_pBullet = new Bullet[BULLET_SHOOT_MAX]; 
		m_SE_22 = LoadSound((char*)"data\\SE\\2_21.wav");
		SetVolume(m_SE_22, 0.1f);
	}

	//デストラクタ
	~PlayerArm1()override { delete[] m_pBullet; }

	//更新処理(オーバーライド)
	void Update(const D3DXVECTOR2& arm_pos)override;

	//描画処理(オーバーライド)
	void PlayerArmDraw()const override;

	//指定した番号のオブジェクトを消す(オーバーライド)
	void DeleteBullet(int index_num)override;

	//指定した番号の弾の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override
		{ return m_pBullet[index_num].GetPos();	}

	//指定した番号の弾のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override
		{ return m_pBullet[index_num].GetSize(); }
};

#endif // !_PLAYER_ARM_1_H_