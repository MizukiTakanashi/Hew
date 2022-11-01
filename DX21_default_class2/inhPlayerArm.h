#pragma once
//==============================================
// (継承用)プレイヤーの腕関係(ヘッダファイル)
// 作成日：2022/10/28
// 作成者：高梨水希
//==============================================

#ifndef _INH_PLAYER_ARM_H_
#define _INH_PLAYER_ARM_H_

#include "GameObject.h"

class inhPlayerArm:public GameObject
{
private:
	int m_BulletNum = 0;	//弾の数


public:
	//デフォルトコンストラクタ
	inhPlayerArm(){}

	//デストラクタ
	~inhPlayerArm(){}

	//更新処理(オーバーライド)
	virtual void Update() = 0;

	//描画処理(オーバーライド)
	virtual void PlayerArmDraw(void)const = 0;

	//指定した番号のオブジェクトを消す
	virtual void DeleteBullet(int index_num) = 0;

	//現在の弾数を増やす
	void IncreaseBulletNum(int num = 1) { m_BulletNum += num; }

	//弾の数を取得
	int GetBulletNum(void)const { return m_BulletNum;}

	//指定した番号の弾の座標を返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetBulletPos(int index_num)const = 0;

	//指定した番号の弾のサイズを返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetBulletSize(int index_num = 0)const = 0;
};

#endif // !_INH_PLAYER_ARM_H_