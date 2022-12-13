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
//メンバ変数
private:
	//敵自身
	int m_obj_num = 0;				//現在のオブジェクト数
	int m_obj_delete_index = 0;		//消したオブジェクトの番号
	int m_obj_attack = 0;			//敵自身がぶつかって与える攻撃力
	
	//弾
	int m_bullet_num = 0;			//現在の弾数
	int m_bullet_max_num = 0;		//弾の最大数
	int m_bullet_attack = 0;		//弾が与える攻撃力

	//別オブジェクト
	int m_other_num = 0;			//現在の別オブジェクト数
	int m_other_attack = 0;			//別オブジェクトが与える攻撃力

protected:
	int m_EnemyNum = 0;				//出現させた敵の数
	int m_FlameNum = 0;				//現在のフレーム数


//メンバ関数
public:
	//デフォルトコンストラクタ
	EnemyManagement() {}

	//引数付きコンストラクタ
	EnemyManagement(int bullet_max_num, int obj_attack, int bullet_attack, int other_attack = 0)
		:m_bullet_max_num(bullet_max_num), m_obj_attack(obj_attack), m_bullet_attack(bullet_attack), 
		m_other_attack(other_attack) {}

	//デストラクタ
	virtual ~EnemyManagement() {}

	//指定した番号のオブジェクトのHPを減らす 敵が死んだらtrueを返す
	virtual bool ReduceHP(int index_num, int reduceHP) { return false; }

	//指定した番号の別オブジェクトのHPを減らす 敵が死んだらtrueを返す
	//(オーバーライド用)
	virtual bool ReduceOtherHP(int index_num, int reduceHP) { return false; }

	//消したオブジェクトの番号を返す(ホーミング弾用)
	int GetDeleteObjIndex(void)const { return m_obj_delete_index; }

	//メンバ変数に消したオブジェクトの番号を記録させておく
	//現在のオブジェクト数を一つ減らす
	virtual void DeleteObj(int index_num) { m_obj_delete_index = index_num; m_obj_num--; }
	
	//指定した番号の弾を消す 
	virtual void DeleteBullet(int index_num) = 0;

	//指定した番号の別オブジェクトを消す 
	virtual void DeleteOther(int index_num) { m_other_num--; }

	//現在のオブジェクト数を増やす
	void IncreaseObjNum(int num) { m_obj_num += num; }

	//現在の弾数を増やす
	void IncreaseBulletNum(int num) { m_bullet_num += num; }

	//現在の別オブジェクト数を増やす
	void IncreaseOtherNum(int num) { m_other_num += num; }

	//現在のオブジェクトの数を返す
	int GetObjNum(void)const { return m_obj_num; }

	//現在の弾の数を返す
	int GetBulletNum(void)const { return m_bullet_num; }

	//現在の別オブジェクトの数を返す
	int GetOtherNum(void)const { return m_other_num; }
	
	//敵自身がぶつかった時の攻撃力を返す
	int GetObjAttack(void)const { return m_obj_attack; }

	//弾の攻撃力を返す
	int GetBulletAttack(void)const { return m_bullet_attack; }

	//別オブジェクトの攻撃力を返す
	int GetOtherAttack(void)const { return m_other_attack; }

	//指定した番号の敵の座標を返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetObjPos(int index_num)const = 0;

	//指定した番号の敵のサイズを返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetObjSize(int index_num = 0)const = 0;

	//指定した番号の弾の座標を返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetBulletPos(int index_num)const = 0;

	//指定した番号の弾のサイズを返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetBulletSize(int index_num = 0)const = 0;

	//指定した番号の別オブジェクトの座標を返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetOtherPos(int index_num)const { return D3DXVECTOR2(-30.0f, -30.0f); };

	//指定した番号の別オブジェクトのサイズを返す(オーバーライド用)
	virtual const D3DXVECTOR2& GetOtherSize(int index_num = 0)const{ return D3DXVECTOR2(0.0f, 0.0f); };

};

#endif // !_ENEMY_MANAGEMENT_H_