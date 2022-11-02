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
	int m_BulletNum = 0;		//現在の弾の数
	int m_bullet_maked_num = 0;	//今まで作られた弾の数(アイテムの消費量)
	int m_bullet_max_num = 0;	//アイテムが出す最大弾数
	bool m_right = false;		//右についてるか左についてるか

public:
	//デフォルトコンストラクタ
	inhPlayerArm(){}

	//引数付きコンストラクタ
	inhPlayerArm(int bullet_max_num, bool right)
		:m_bullet_max_num(bullet_max_num), m_right(right) {}

	//デストラクタ
	~inhPlayerArm(){}

	//更新処理(オーバーライド)
	virtual void Update(const D3DXVECTOR2& arm_pos) = 0;

	//描画処理(オーバーライド)
	virtual void PlayerArmDraw(void)const = 0;

	//弾が尽きたかを返す
	// true：使い終わった　false：まだ使い終わってない
	bool IsBulletUsed(void)const;

	//作った弾の数を増やす
	void IncreaseBulletMaked(int num = 1) { m_bullet_maked_num += num; }

	//指定した番号の弾を消す(オーバーライド用)
	virtual void DeleteBullet(int index_num) = 0;

	//現在の弾数を増やす
	void IncreaseBulletNum(int num = 1) { m_BulletNum += num; }

	//弾の数を取得
	int GetBulletNum(void)const { return m_BulletNum; }

	//指定した番号の弾の座標を返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetBulletPos(int index_num)const = 0;

	//指定した番号の弾のサイズを返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetBulletSize(int index_num = 0)const = 0;

	//ついているのが右腕か左腕かを返す
	bool GetRightLeft(void)const { return m_right; }
};

#endif // !_INH_PLAYER_ARM_H_