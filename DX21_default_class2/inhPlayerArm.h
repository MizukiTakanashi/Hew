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
//メンバ変数
private:
	int m_BulletNum = 0;		//現在の弾の数
	int m_bullet_maked_num = 0;	//今まで作られた弾の数(アイテムの消費量)
	int m_bullet_max_num = 0;	//アイテムが出す最大弾数
	bool m_right = false;		//右についてるか左についてるか

	//とある座標取得用
	//現在はPlayerArm1のホーミング弾の敵の位置取得用
	D3DXVECTOR2 m_something_pos = D3DXVECTOR2(0.0f, 0.0f);	

//メンバ関数
public:
	//デフォルトコンストラクタ
	inhPlayerArm(){}

	//引数付きコンストラクタ
	inhPlayerArm(int bullet_max_num, bool right)
		:m_bullet_max_num(bullet_max_num), m_right(right) {}

	//デストラクタ
	~inhPlayerArm(){}

	//=========================
	// オーバーライド用
	
	//更新処理(オーバーライド)
	virtual void Update(const D3DXVECTOR2& arm_pos) = 0;

	//描画処理(オーバーライド)
	virtual void PlayerArmDraw(void)const = 0;

	//指定した番号の弾を消す(オーバーライド用)
	virtual void DeleteBullet(int index_num) = 0;

	//指定した番号の弾の座標を返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetBulletPos(int index_num)const = 0;

	//指定した番号の弾のサイズを返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetBulletSize(int index_num = 0)const = 0;


	//弾が尽きたかを返す
	// true：使い終わった　false：まだ使い終わってない
	bool IsBulletUsed(void)const;

	//作った弾の数を増やす
	void IncreaseBulletMaked(int num = 1) { m_bullet_maked_num += num; }

	//現在の弾数を増やす
	void IncreaseBulletNum(int num = 1) { m_BulletNum += num; }

	//弾の数を取得
	int GetBulletNum(void)const { return m_BulletNum; }

	//ついているのが右腕か左腕かを返す
	bool GetRightLeft(void)const { return m_right; }

	//とある座標セット用(詳細はメンバ変数のm_something_posのコメントへ)
	void SetSomethingPos(const D3DXVECTOR2& pos) { m_something_pos = pos; }

	//とある座標取得用(詳細はメンバ変数のm_something_posのコメントへ)
	const D3DXVECTOR2& GetSomethingPos(void)const { return m_something_pos; }
};

#endif // !_INH_PLAYER_ARM_H_