//=======================================
// プレイヤーの腕、氷の弾関係(ヘッダファイル)
// 作成日：2022/1/1
// 作成者：矢野翔大
//=======================================
#pragma once

#include "inh_player_arm.h"
#include "draw_object.h"
#include "bullet.h"

class PlayerArmIceRain :public inhPlayerArm
{
	//定数
private:
	//ここで初期化
	static const int BULLET_NUM_MAX = 50;		//弾の制限数　実際に撃てる数はこれより１少ない
	static const int BULLET_SHOOT_MAX = 100;		//弾の同時最大発射数
	static const int BULLET_INTERVAL = 10;		//弾の発射間隔
	static const int BULLET_INTERVAL1 = 11;		//弾の発射間隔
	static const int BULLET_INTERVAL2 = 12;		//弾の発射間隔
	static const int BULLET_INTERVAL3 = 13;		//弾の発射間隔
	static const int BULLET_INTERVAL4 = 14;		//弾の発射間隔

	//cppで初期化
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY
	static const float BULLET_SPEED;		//スピード

	//メンバ変数
private:
	DrawObject m_bulletdraw;			//弾の描画オブジェクト
	Bullet* m_pBullet = nullptr;		//弾のオブジェクト
	int m_bullet_interval_count = 0;	//発射間隔カウント
	int m_bullet_interval_count1 = 0;	//発射間隔カウント
	int m_bullet_interval_count2 = 0;	//発射間隔カウント
	int m_bullet_interval_count3 = 0;	//発射間隔カウント
	int m_bullet_interval_count4 = 0;	//発射間隔カウント

	//メンバ関数
public:
	//デフォルトコンストラクタ
	PlayerArmIceRain() { m_pBullet = new Bullet[BULLET_SHOOT_MAX]; }

	//引数付きコンストラクタ
	PlayerArmIceRain(DrawObject bulletdraw, bool right, int type)
		:inhPlayerArm(BULLET_NUM_MAX, right, type), m_bulletdraw(bulletdraw) {
		m_pBullet = new Bullet[BULLET_SHOOT_MAX];
	}

	//デストラクタ
	~PlayerArmIceRain()override { delete[] m_pBullet; }

	//更新処理(オーバーライド)
	void Update(const D3DXVECTOR2& arm_pos)override;

	//描画処理(オーバーライド)
	void PlayerArmDraw()const override;

	//指定した番号の弾を消す(オーバーライド)
	void DeleteBullet(int index_num)override;

	//指定した番号の弾の座標を返す(オーバーライド)
	const D3DXVECTOR2& GetBulletPos(int index_num)const override
	{
		return m_pBullet[index_num].GetPos();
	}

	//指定した番号の弾のサイズを返す(オーバーライド)
	const D3DXVECTOR2& GetBulletSize(int index_num = 0)const override
	{
		return m_pBullet[index_num].GetSize();
	}
};
