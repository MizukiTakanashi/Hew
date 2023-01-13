#pragma once
//=========================================================
// プレイヤーの腕のアイテム(バリア)関係(ヘッダファイル)
// 作成日：2022/12/19
// 作成者：高梨水希
//========================================================

#ifndef _PLAYER_ARM_BARRIER_H_
#define _PLAYER_ARM_BARRIER_H_

#include "inh_player_arm.h"
#include "draw_object.h"
#include "bullet.h"

class PlayerArmBarrier :public inhPlayerArm
{
//定数
private:
	//ここで初期化
	static const int BULLET_NUM_MAX = 5;	//弾の制限数　実際に撃てる数はこれより１少ない
	static const int BULLET_SHOOT_MAX = 1;	//弾の同時最大発射数
	static const int BARRIER_HP_MAX = 5;	//バリアの最大HP

	//cppで初期化
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY
	static const D3DXVECTOR2 RIGHT_BARRIER_INTERVAL_POS;	//バリアと右腕の間隔
	static const D3DXVECTOR2 LEFT_BARRIER_INTERVAL_POS;		//バリアと左腕の間隔
	static const D3DXVECTOR2 CENTER_BARRIER_INTERVAL_POS;	//バリアと中央の間隔


//メンバ変数
private:
	DrawObject m_bulletdraw;			//弾の描画オブジェクト
	Bullet* m_pBullet = nullptr;		//弾のオブジェクト


//メンバ関数
public:
	//デフォルトコンストラクタ
	PlayerArmBarrier() { m_pBullet = new Bullet; }

	//引数付きコンストラクタ
	PlayerArmBarrier(DrawObject bulletdraw, bool right, int type)
		:inhPlayerArm(BULLET_NUM_MAX, right, type, BARRIER_HP_MAX), m_bulletdraw(bulletdraw) {
		m_pBullet = new Bullet[BULLET_SHOOT_MAX];
	}

	//デストラクタ
	~PlayerArmBarrier()override { 
		if (m_pBullet != nullptr) {
			delete m_pBullet;
		}
	}

	//更新処理(オーバーライド)
	void Update(const D3DXVECTOR2& arm_pos)override;

	//描画処理(オーバーライド)
	void PlayerArmDraw()const override;

	//指定した番号の弾を消す(オーバーライド)
	void DeleteBullet(int index_num)override;

	//指定した番号の弾の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override
	{
		return m_pBullet->GetPos();
	}

	//指定した番号の弾のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override
	{
		return m_pBullet->GetSize();
	}
};

#endif // !_PLAYER_ARM_BARRIER_H_