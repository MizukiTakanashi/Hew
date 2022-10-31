#pragma once
//====================================================
// 敵の管理関係(ポリモーフィズム用)(ヘッダファイル)
// 作成日：2022/10/31
// 作成者：高梨水希
//====================================================

#ifndef _ENEMY_MANAGEMENT_H_
#define _ENEMY_MANAGEMENT_H_

#include "main.h"

class EnemyManagement
{
private:
	int m_obj_max_num = 0;			//オブジェクトの最大数
	int m_obj_num = 0;				//現在のオブジェクト数
	int m_bullet_max_num = 0;		//弾の最大数
	int m_bullet_num = 0;			//現在の弾数
	int m_bullet_attack = 0;		//弾が与える攻撃力

public:
	//デフォルトコンストラクタ
	EnemyManagement() {}

	//引数付きコンストラクタ
	EnemyManagement(int enemy_max_num, int bullet_max_num, int bullet_attack) 
		:m_obj_max_num(enemy_max_num), m_bullet_max_num(bullet_max_num), m_bullet_attack(bullet_attack) {}

	//デストラクタ
	virtual ~EnemyManagement() {}

	//指定した番号のオブジェクトを消す
	virtual void DeleteObj(int index_num) = 0;

	//指定した番号のオブジェクトを消す
	virtual void DeleteBullet(int index_num) = 0;

	//現在のオブジェクト数を増やす
	void IncreaseObjNum(int num = 1) { m_obj_num += num; }

	//現在の弾数を増やす
	void IncreaseBulletNum(int num = 1) { m_obj_num += num; }

	//現在のオブジェクトの数を返す
	int GetObjNum(void)const { return m_obj_num; }

	//現在の弾の数を返す
	int GetBulletNum(void)const { return m_bullet_num; }
	
	//弾の攻撃力を返す
	int GetBulletAttack(void)const { return m_bullet_attack; }

	//指定した番号の敵の座標を返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetObjPos(int index_num)const = 0;

	//指定した番号の敵のサイズを返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetObjSize(int index_num = 0)const = 0;

	//指定した番号の弾の座標を返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetBulletPos(int index_num)const = 0;

	//指定した番号の弾のサイズを返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetBulletSize(int index_num = 0)const = 0;
};

#endif // !_ENEMY_MANAGEMENT_H_