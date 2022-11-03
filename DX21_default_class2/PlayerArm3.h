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
	static const int BULLET_NUM_MAX = 100;		//弾の制限数
	static const int BULLET_SHOOT_MAX = 20;		//弾の同時最大発射数
	static const int BULLET_INTERVAL = 10;		//弾の発射間隔
	
	//cppで初期化
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY
	static const float BULLET_SPEED;		//スピード

//メンバ変数
private:
	DrawObject m_bulletdraw;			//弾の描画オブジェクト
	Bullet* m_pBullet = nullptr;		//弾のオブジェクト
	int m_bullet_interval_count = 0;	//発射間隔カウント

//メンバ関数
public:
	//デフォルトコンストラクタ
	PlayerArm3() { m_pBullet = new Bullet[BULLET_SHOOT_MAX]; }

	//引数付きコンストラクタ
	PlayerArm3(DrawObject bulletdraw, bool right) 
		:inhPlayerArm(BULLET_NUM_MAX, right), m_bulletdraw(bulletdraw) { m_pBullet = new Bullet[BULLET_SHOOT_MAX]; }

	//デストラクタ
	~PlayerArm3() { delete[] m_pBullet; }

	//更新処理(オーバーライド)
	void Update(const D3DXVECTOR2& arm_pos)override;

	//描画処理(オーバーライド)
	void PlayerArmDraw()const override;

	//指定した番号の弾を消す(オーバーライド)
	void DeleteBullet(int index_num)override;

	//指定した番号の弾の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override
		{ return m_pBullet[index_num].GetPos();	}

	//指定した番号の弾のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override
		{ return m_pBullet[index_num].GetSize(); }
};

#endif // !_PLAYER_ARM_1_H_