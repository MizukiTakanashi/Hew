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
#include "explosion.h"

class PlayerArmGrenade :public inhPlayerArm
{
//定数
public:
	//cppで初期化
	//※FIND_BULLET_SIZEが一番小さく！
	static const D3DXVECTOR2 BULLET_SIZE;		//サイズ
	static const D3DXVECTOR2 FIND_BULLET_SIZE;	//探している間の弾のサイズ
	static const D3DXVECTOR2 FIND_RANGE;		//探している時の攻撃範囲

private:
	//ここで初期化
	static const int BULLET_NUM_MAX = 51;	//弾の制限数　実際に撃てる数はこれより１少ない
	static const int BULLET_SHOOT_MAX = 10;	//弾の同時最大発射数
	static const int BULLET_BREAK_TIME = 1000;	//ホーミング弾が壊れる時間
	static const int BULLET_INTERVAL = 20;	//弾の発射間隔
	static const int EXPLOSION_WAIT_TIME = 0;	//爆発待ち時間
	static const int EXPLOSION_TIME = 100;		//爆発時間

	//cppで初期化
	static const D3DXVECTOR2 BULLET_SIZE;		//サイズ
	static const float BULLET_SPEED;			//スピード
	static const D3DXVECTOR2 EXPLOSION_RANGE;	//爆発のサイズ

//メンバ変数
private:
	DrawObject m_bulletdraw;				//弾の描画オブジェクト
	DrawObject m_explosiondraw;				//爆発の描画オブジェクト
	Bullet* m_pBullet[BULLET_SHOOT_MAX];	//弾のオブジェクト
	Explosion* m_pExplosionDraw[BULLET_SHOOT_MAX];	//描画用の爆発
	int m_interval_count = 0;				//発射間隔のカウント
	int m_attack_count[BULLET_SHOOT_MAX];	//爆発開始からをカウント
	int m_SE_12 = 0;						//弾発射音


//メンバ関数
public:
	//デフォルトコンストラクタ
	PlayerArmGrenade();

	//引数付きコンストラクタ
	PlayerArmGrenade(DrawObject bulletdraw, DrawObject explosiondraw, bool right, int type);

	//デストラクタ
	~PlayerArmGrenade()override;

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

	//アクションを起こす(指定した番号の弾の爆発をセット)
	void Action(int index_num)override;
};

#endif // !_PLAYER_ARM_GRENADE_H_