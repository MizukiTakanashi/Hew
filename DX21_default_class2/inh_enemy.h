//=======================================
// 継承用敵クラス(ヘッダファイル)
// 作成日：
// 作成者：恩田洋行
//=======================================
#pragma once

#ifndef _INH_ENEMY_H_
#define _INH_ENEMY_H_

#include "game_object.h"

class Inh_Enemy :public GameObject
{
//定数
public:

private:
	//cppで初期化
	static const int INVINCIBLE_FLAME = 30;			//敵の無敵時間

//メンバ変数
private:
	bool m_enemyitem_make = false;		//アイテムを作るか否か
	int m_hp = 0;						//敵の現在のHP

protected:
	int m_bullet_count = 0;				//弾を発射するまでのカウント
	bool m_bullet_make = false;			//弾を作るか否か
	float m_move_width = 0.0f;			//敵が動く時のcosカーブ
	int m_invincible_flame = 0;			//無敵時間の残り
	float m_init_posx = 0.0f;			//敵の初期位置X

//メンバ関数
public:
	//デフォルトコンストラクタ
	Inh_Enemy() {}		

	//引数付きコンストラクタ
	Inh_Enemy(DrawObject& pDrawObject, const D3DXVECTOR2& pos, D3DXVECTOR2 size, int hp)
		:GameObject(pDrawObject, pos, size), m_hp(hp), m_init_posx(pos.x) {}

	//デストラクタ
	~Inh_Enemy()override {}	

	//更新処理
	virtual void Update(void) {}	

	//弾を作るか否かのフラグを返す
	bool GetFlagBulletMake()const { return m_bullet_make; }

	//弾を作った
	void BulletMake() { m_bullet_make = false; }

	//敵のアイテムを作るか否かのフラグを返す
	bool GetFlagEnemyItemMake()const { return m_enemyitem_make; }

	//敵のアイテムを作った
	void EnemyItemMake() { m_enemyitem_make = false; }

	//HPを減らす
	bool ReduceHP(int amount) 
	{
		if (m_invincible_flame <= 0)
		{
			m_hp -= amount;
			m_invincible_flame = INVINCIBLE_FLAME;

			return true;
		}
		else
		{
			return false;
		}
	}

	//HPを返す
	int GetHP(void) { return m_hp; }

};

#endif // !_INH_ENEMY_H_