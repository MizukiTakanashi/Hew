#pragma once
//=================================================
// プレイヤーの腕のグレネード関係(ヘッダファイル)
// 作成日：2023/01/13
// 作成者：高梨水希
//=================================================

#ifndef _PLAYER_ARM_GRENADE_H_
#define _PLAYER_ARM_GRENADE_H_

#include "inh_player_arm.h"
#include "draw_object.h"
#include "bullet.h"

class PlayerArmGrenad :public inhPlayerArm
{
//定数
public:
	//cppで初期化
	static const D3DXVECTOR2 FINAD_RANGE;	//探している時の攻撃範囲

private:
	//ここで初期化
	static const int BULLET_NUM_MAX = 50;	//弾の制限数　実際に撃てる数はこれより１少ない
	static const int BULLET_SHOOT_MAX = 10;	//弾の同時最大発射数

	//cppで初期化
	static const D3DXVECTOR2 BULLET_SIZE;	//サイズ

//メンバ変数
private:
	DrawObject m_bulletdraw;				//弾の描画オブジェクト
	Bullet* m_pBullet[BULLET_SHOOT_MAX];	//弾のオブジェクト


//メンバ関数
public:
	//デフォルトコンストラクタ
	PlayerArmGrenad() {
		for (int i = 0; i < BULLET_SHOOT_MAX; i++) {
			m_pBullet[i] = nullptr;
		}	
	}

	//引数付きコンストラクタ
	PlayerArmGrenad(DrawObject bulletdraw, bool right, int type)
		:inhPlayerArm(BULLET_NUM_MAX, right, type), m_bulletdraw(bulletdraw) {
		for (int i = 0; i < BULLET_SHOOT_MAX; i++) {
			m_pBullet[i] = nullptr;
		}
	}

	//デストラクタ
	~PlayerArmGrenad()override {
		for (int i = 0; i < BULLET_SHOOT_MAX; i++) {
			if (m_pBullet[i] != nullptr) {
				delete m_pBullet[i];
			}
		}
	}

	//更新処理(オーバーライド)
	void Update(const D3DXVECTOR2& arm_pos)override;

	//描画処理(オーバーライド)
	void PlayerArmDraw()const override;

	//指定した番号の弾を消す(オーバーライド)
	void DeleteBullet(int index_num)override;

	//指定した番号の弾の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override{
		return m_pBullet[index_num]->GetPos();
	}

	//指定した番号の弾のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override{
		return m_pBullet[index_num]->GetSize();
	}
};

#endif // !_PLAYER_ARM_GRENADE_H_