#pragma once
//=========================================================
// プレイヤーの腕のアイテム(STOP)関係(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//========================================================

#ifndef _PLAYER_ARM_STOP_H_
#define _PLAYER_ARM_STOP_H_

#include "inh_player_arm.h"
#include "draw_object.h"
#include "bullet_stop.h"

class PlayerArmStop :public inhPlayerArm
{
//定数
private:
	//ここで初期化
	static const int BULLET_NUM_MAX = 5;	//弾の制限数　実際に撃てる数はこれより１少ない
	static const int BULLET_SHOOT_MAX = 1;	//弾の同時最大発射数
	static const int BULLET_INTERVAL = 120;		//弾の発射間隔
	static const int BULLET_TIME = 120;

	//cppで初期化
	static const float BULLET_SIZE_X;		//サイズX
	static const float BULLET_SIZE_Y;		//サイズY


//メンバ変数
private:
	DrawObject m_bulletdraw;			//弾の描画オブジェクト
	BulletStop* m_pBullet = nullptr;	//弾のオブジェクト
	int m_SE_11 = 0;					//冷気を出す音


//メンバ関数
public:
	//デフォルトコンストラクタ
	PlayerArmStop() { m_pBullet = new BulletStop[BULLET_SHOOT_MAX]; }

	//引数付きコンストラクタ
	PlayerArmStop(DrawObject bulletdraw, bool right, int type);

	//デストラクタ
	~PlayerArmStop()override { delete[] m_pBullet; }

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

#endif // !_PLAYER_ARM_STOP_H_