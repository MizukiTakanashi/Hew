#pragma once
//======================================================
// プレイヤーの腕、ガトリング・炎関係(ヘッダファイル)
// 作成日：2022/10/28
// 作成者：高梨水希
//======================================================

#ifndef _PLAYER_ARM_3_H_
#define _PLAYER_ARM_3_H_

#include "inh_player_arm.h"
#include "draw_object.h"
#include "bullet.h"
#include "sound.h"

class PlayerArm3 :public inhPlayerArm
{
//定数
public:
	enum class TYPE :int
	{
		GATORING,
		FIRE,
		ACID,
		FIREBALL,
		NUM
	};

private:
	//ここで初期化
	static const int BULLET_NUM_MAX = 50;		//弾の制限数　実際に撃てる数はこれより１少ない
	static const int BULLET_SHOOT_MAX = 20;		//弾の同時最大発射数
	static const int BULLET_INTERVAL = 10;		//弾の発射間隔
	static const int ACID_INTERVAL = 120;		//弾の発射間隔
	static const int FIREBALL_INTERVAL = 60;		//弾の発射間隔
	
	//cppで初期化
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY
	static const float BULLET_SPEED;		//スピード
	static const float FIRE_SPEED;			//炎のスピード
	static const float ACID_SPEED;			//炎のスピード
	static const float FIREBALL_SPEED;			//炎のスピード

//メンバ変数
private:
	DrawObject m_bulletdraw;			//弾の描画オブジェクト
	Bullet* m_pBullet = nullptr;		//弾のオブジェクト
	TYPE m_type = TYPE::GATORING;		//弾のタイプ
	int m_SE_21 = 0;					//ガトリング弾発射音
	int m_SE_15_1 = 0;					//炎発射音

	int m_interval = BULLET_INTERVAL;

//メンバ関数
public:
	//デフォルトコンストラクタ
	PlayerArm3() { m_pBullet = new Bullet[BULLET_SHOOT_MAX]; }

	//引数付きコンストラクタ
	PlayerArm3(DrawObject bulletdraw, bool right, int type, TYPE _type = TYPE::GATORING)

		:inhPlayerArm(BULLET_NUM_MAX, right, type), m_bulletdraw(bulletdraw), m_type(_type) 
　{
		m_pBullet = new Bullet[BULLET_SHOOT_MAX]; 
		m_SE_21 = LoadSound((char*)"data\\SE\\2_20.wav");
		SetVolume(m_SE_21, 0.07f);
		m_SE_15_1 = LoadSound((char*)"data\\SE\\1_15_1.wav");
		SetVolume(m_SE_15_1, 0.5f);
    if (m_type == TYPE::ACID)
		{
			m_interval = ACID_INTERVAL;
		}
		else if (m_type == TYPE::FIREBALL)
		{
			m_interval = FIREBALL_INTERVAL;
		}
	}

	//デストラクタ
	~PlayerArm3()override { delete[] m_pBullet; }

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